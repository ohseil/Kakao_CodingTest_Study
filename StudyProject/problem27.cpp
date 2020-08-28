#include "problem27.h"

namespace KakaoWinterIntern2019 {

	namespace problem27 {

		int solution(vector<vector<int>> board, vector<int> moves) {

			// 인형 번호 : 1 ~ 100
			// 빈칸 : 0

			// board에서 각 열마다 쌓여있는 높이를 확인하고 저장.
			// 각 move를 확인하고 stack을 이용해서 인형을 쌓으면서 터트리고
			// 집은 인형이 있던 열은 높이를 갱신한다.

			int answer = 0;

			vector<int> heights;
			stack<int> bucket;
			int n = board.size();

			for (int i = 0; i < n; i++) {

				// 초기화
				heights.push_back(n);

				for (int j = 0; j < n; j++) {
					if (board[j][i] != 0) {
						// 현재 높이에 인형이 있다면 높이정보 저장.
						heights[i] = j;
						break;
					}
				}
			}

			// 저장한 높이데이터를 이용해서 각 move를 실행.

			for (int move : moves) {

				// 인형을 빼서 바구니에 넣으면서 터뜨림 확인하고,
				// 인형을 꺼낸 위치의 높이 갱신.

				int index = move - 1;

				if (heights[index] < n) {

					int dollNum = board[heights[index]][index]; // 뽑은 인형번호

					if (bucket.empty() == true) {
						// 비어있다면 바구니에 담기.
						bucket.push(dollNum);
					}
					else {

						if (bucket.top() == dollNum) {
							// 연속된 인형이라면 터뜨림
							answer += 2;
							bucket.pop();
						}
						else {
							// 연속된 인형이 아니라면 바구니에 담기.
							bucket.push(dollNum);
						}
					}

					heights[index]++; // 높이 갱신.
				}
			}

			return answer;
		}

		void execute() {


		}
	}
}