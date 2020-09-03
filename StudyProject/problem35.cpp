#include "problem35.h"

namespace KakaoIntern2020 {

	namespace problem35 {

		// index 0은 필요해서 채움.
		// 1~4 사용.
		int dx[5] = { 0, -1, 0, 1, 0 };
		int dy[5] = { 0, 0, -1, 0, 1 };

		// 블록의 위치
		class position {
		public:
			int x = 0;
			int y = 0;
		};

		// 현재 검색중인 경로를 표현.
		class road {
		public:
			position pos; // 위치
			int dist = 0; // 현재 방향
			int cost = 0; // 현재 비용
		};

		bool checkCondition(vector<vector<int>> board, position pos) {
			// 블럭 범위 밖을 벗어난 경우 return false.
			// 벽일 경우 return false;
			if (pos.x < 0 || board.size() <= pos.x || pos.y < 0 || board.size() <= pos.y) return false;
			if (board[pos.y][pos.x] == 1) return false;
			return true;
		}

		int needCost(int curDist, int nextDist) {
			if (curDist == 0)
				return 100;
			if (curDist - nextDist == 0)
				return 100;
			return 600;
		}

		int solution(vector<vector<int>> board) {

			// 방향 -> 0:없음, 1:좌, 2:상, 3:우, 4:하

			// check하는 map을 하나 만들어서 각 블록마다
			// 4방향에서 들어오는 경로의 cost를 저장 가능하도록 한다.
			// 기존에 같은 방향에서 들어왔던 경로의 cost보다
			// 현재 cost가 더 작다면 정보 갱신, 아니라면 현재 경로 검색중단.

			int answer = 0;

			vector<vector<vector<int>>> checkMap;

			for (int i = 0; i < board.size(); i++) {
				vector<vector<int>> v;
				for (int j = 0; j < board.size(); j++) {

					vector<int> costs(5, 0);
					v.push_back(costs);
				}

				checkMap.push_back(v);
			}

			road start;

			queue<road> q;
			q.push(start);

			while (!q.empty()) {

				int qSize = q.size();

				for (int i = 0; i < qSize; i++) {

					road data = q.front();
					q.pop();

					// 각 가려는 방향마다 벽인지 땅 범위 밖인지
					// 이미 갔던 방향인지 확인 후 조건이 맞으면 큐에 삽입.
					for (int d = 1; d <= 4; d++) {

						// 왔던 방향에서 반대로 되돌아가는 방향 pass.
						if (data.dist != 0 && (data.dist - d) == 2)
							continue;

						road inputData = data;
						inputData.pos.x += dx[d];
						inputData.pos.y += dy[d];
						inputData.cost += needCost(data.dist, d);
						inputData.dist = d;

						if (checkCondition(board, inputData.pos) == true) {
							if (checkMap[inputData.pos.y][inputData.pos.x][inputData.dist] == 0 ||
								checkMap[inputData.pos.y][inputData.pos.x][inputData.dist] > inputData.cost) {
								// 간적이 없거나 갔던 cost보다 적은 cost일 경우 queue 삽입.
								q.push(inputData);
								checkMap[inputData.pos.y][inputData.pos.x][inputData.dist] = inputData.cost;
							}
						}
					}


				}
			}

			// [n-1][n-1] 위치에서 4방향에서 오는 경로의 cost중 가장 싼 cost 검색.
			vector<int> destination = checkMap[board.size() - 1][board.size() - 1];
			answer = destination[1];
			for (int cost : destination)
				if (answer == 0 || (cost != 0 && answer > cost))
					answer = cost;

			return answer;
		}

		void execute() {

			vector<int> v(3, 0);
			vector<vector<int>> board(3, v);

			cout << solution(board);
		}
	}
}