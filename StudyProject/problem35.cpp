#include "problem35.h"

namespace KakaoIntern2020 {

	namespace problem35 {

		// index 0�� �ʿ��ؼ� ä��.
		// 1~4 ���.
		int dx[5] = { 0, -1, 0, 1, 0 };
		int dy[5] = { 0, 0, -1, 0, 1 };

		// ����� ��ġ
		class position {
		public:
			int x = 0;
			int y = 0;
		};

		// ���� �˻����� ��θ� ǥ��.
		class road {
		public:
			position pos; // ��ġ
			int dist = 0; // ���� ����
			int cost = 0; // ���� ���
		};

		bool checkCondition(vector<vector<int>> board, position pos) {
			// �� ���� ���� ��� ��� return false.
			// ���� ��� return false;
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

			// ���� -> 0:����, 1:��, 2:��, 3:��, 4:��

			// check�ϴ� map�� �ϳ� ���� �� ��ϸ���
			// 4���⿡�� ������ ����� cost�� ���� �����ϵ��� �Ѵ�.
			// ������ ���� ���⿡�� ���Դ� ����� cost����
			// ���� cost�� �� �۴ٸ� ���� ����, �ƴ϶�� ���� ��� �˻��ߴ�.

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

					// �� ������ ���⸶�� ������ �� ���� ������
					// �̹� ���� �������� Ȯ�� �� ������ ������ ť�� ����.
					for (int d = 1; d <= 4; d++) {

						// �Դ� ���⿡�� �ݴ�� �ǵ��ư��� ���� pass.
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
								// ������ ���ų� ���� cost���� ���� cost�� ��� queue ����.
								q.push(inputData);
								checkMap[inputData.pos.y][inputData.pos.x][inputData.dist] = inputData.cost;
							}
						}
					}


				}
			}

			// [n-1][n-1] ��ġ���� 4���⿡�� ���� ����� cost�� ���� �� cost �˻�.
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