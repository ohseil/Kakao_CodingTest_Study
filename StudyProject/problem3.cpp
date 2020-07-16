#include "problem3.h"

namespace KakaoBlind2020 {

	namespace problem3 {

		bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

			bool answer = false;

			int n = lock[0].size(), m = key[0].size();

			vector<vector<int>> board, originBoard;

			for (int i = 0; i < n + (m - 1) * 2; i++) {
				vector<int> v;
				for (int j = 0; j < n + (m - 1) * 2; j++) {
					v.push_back(0);
				}
				originBoard.push_back(v);
			}

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					originBoard[i + (m - 1)][j + (m - 1)] = lock[i][j];

			// key 돌릴 경우 4가지 모양
			for (int num = 0; num < 4; num++) {

				for (int xstart = 0; xstart < n + m - 1; xstart++) {
					for (int ystart = 0; ystart < n + m - 1; ystart++) {

						// board 초기화
						board.clear();
						board.assign(originBoard.begin(), originBoard.end());

						for (int i = 0; i < m; i++) {

							bool isCollision = false;

							for (int j = 0; j < m; j++) {

								if (key[i][j] == 1) {
									if (board[i + xstart][j + ystart] == 1) {
										isCollision = true;
										break;
									}
									else {
										board[i + xstart][j + ystart] = 1;
									}
								}

							}

							if (isCollision == true)
								break;

						}

						bool isRight = true;

						for (int i = 0; i < n; i++)
							for (int j = 0; j < n; j++)
								if (board[i + (m - 1)][j + (m - 1)] == 0) {
									isRight = false;
									break;
								}

						if (isRight == true) {
							answer = true;
							break;
						}

					}

				}

				vector<vector<int>> temp;
				temp.assign(key.begin(), key.end());

				for (int i = 0; i < m; i++) {
					for (int j = 0; j < m; j++) {
						key[j][m - i - 1] = temp[i][j];
					}
				}

			}

			return answer;
		}

		void execute() {

			vector<int> v;
			vector<vector<int>> key, lock;
			v.push_back(0); v.push_back(0); v.push_back(0);
			key.push_back(v);
			v[0] = 1; v[1] = 0; v[2] = 0;
			key.push_back(v);
			v[0] = 0; v[1] = 1; v[2] = 1;
			key.push_back(v);

			v[0] = 1; v[1] = 1; v[2] = 1;
			lock.push_back(v);
			v[0] = 1; v[1] = 1; v[2] = 0;
			lock.push_back(v);
			v[0] = 1; v[1] = 0; v[2] = 1;
			lock.push_back(v);

			cout << solution(key, lock) << endl;
		}

	}

}