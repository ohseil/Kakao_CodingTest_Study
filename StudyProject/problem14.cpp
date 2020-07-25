#include "problem14.h"

namespace KakaoBlind2019 {

	namespace problem14 {

		int solution(vector<vector<int>> board) {

			int answer = 0;
			int size = board.size();

			int erased = 1;

			// �� ������ ������ �������� ä�����ϴ��� ���� ����
			int* pos = new int[size];
			for (int i = 0; i < size; i++)
				pos[i] = 0;

			// ������ ���� ���������� ����
			while (erased != 0) {

				erased = 0;

				// �� ������ ���������� �ɸ��µ����� ä���
				for (int i = 0; i < size; i++) {

					for (int j = pos[i]; j < size; j++) {
						if (board[j][i] == 0) {
							board[j][i] = -1;
						}
						else if (board[j][i] != -1) {
							// �� ����
							break;
						}

						pos[i] = j + 1;
					}
				}


				// ������ ���� �ִ��� Ȯ���ϰ� �����.
				// 2x3 �簢�� ������� Ȯ��
				for (int i = 0; i < size - 1; i++) {
					for (int j = 0; j < size - 2; j++) {

						int blockNum = -1;
						set<int> checkBlockCount;
						bool canErase = true;
						vector<pair<int, int>> v;
						for (int x = i; x <= i + 1; x++) {
							for (int y = j; y <= j + 2; y++) {
								if (board[x][y] == 0) {
									canErase = false;
									break;
								}
								else if (board[x][y] != -1) {

									blockNum = board[x][y];
									checkBlockCount.insert(blockNum);
									v.push_back(make_pair<int, int>((int)x, (int)y));
								}
							}
						}

						if (canErase == true && blockNum != -1 && v.size() == 4 && checkBlockCount.size() == 1) {
							// ���� �� �ִ� �� �����.
							for (auto a : v) {
								board[a.first][a.second] = 0;
							}
							erased++;
							answer++;
						}

					}
				}

				// 3x2 �簢�� ������� Ȯ��
				for (int i = 0; i < size - 2; i++) {
					for (int j = 0; j < size - 1; j++) {

						int blockNum = -1;
						set<int> checkBlockCount;
						bool canErase = true;
						vector<pair<int, int>> v;
						for (int x = i; x <= i + 2; x++) {
							for (int y = j; y <= j + 1; y++) {
								if (board[x][y] == 0) {
									canErase = false;
									break;
								}
								else if (board[x][y] != -1) {

									blockNum = board[x][y];
									checkBlockCount.insert(blockNum);
									v.push_back(make_pair<int, int>((int)x, (int)y));
								}
							}
						}

						if (canErase == true && blockNum != -1 && v.size() == 4 && checkBlockCount.size() == 1) {
							// ���� �� �ִ� �� �����.
							for (auto a : v) {
								board[a.first][a.second] = 0;
							}
							erased++;
							answer++;
						}
					}
				}
			}

			return answer;
		}

		void execute() {

			vector<vector<int>> board;
			vector<int> b;
			b.push_back(0); b.push_back(0); b.push_back(0); b.push_back(0); b.push_back(0);
			b.push_back(0); b.push_back(0); b.push_back(0); b.push_back(0); b.push_back(0);
			board.push_back(b);
			b[0] = 0; b[1] = 0; b[2] = 0; b[3] = 0; b[4] = 0; b[5] = 0; b[6] = 0; b[7] = 0; b[8] = 0; b[9] = 0;
			board.push_back(b);
			b[0] = 0; b[1] = 0; b[2] = 0; b[3] = 0; b[4] = 0; b[5] = 0; b[6] = 0; b[7] = 0; b[8] = 0; b[9] = 0;
			board.push_back(b);
			b[0] = 0; b[1] = 0; b[2] = 0; b[3] = 0; b[4] = 0; b[5] = 0; b[6] = 0; b[7] = 0; b[8] = 0; b[9] = 0;
			board.push_back(b);
			b[0] = 0; b[1] = 0; b[2] = 0; b[3] = 0; b[4] = 0; b[5] = 0; b[6] = 4; b[7] = 0; b[8] = 0; b[9] = 0;
			board.push_back(b);
			b[0] = 0; b[1] = 0; b[2] = 0; b[3] = 0; b[4] = 0; b[5] = 4; b[6] = 4; b[7] = 0; b[8] = 0; b[9] = 0;
			board.push_back(b);
			b[0] = 0; b[1] = 0; b[2] = 0; b[3] = 0; b[4] = 3; b[5] = 0; b[6] = 4; b[7] = 0; b[8] = 0; b[9] = 0;
			board.push_back(b);
			b[0] = 0; b[1] = 0; b[2] = 0; b[3] = 2; b[4] = 3; b[5] = 0; b[6] = 0; b[7] = 0; b[8] = 5; b[9] = 5;
			board.push_back(b);
			b[0] = 1; b[1] = 2; b[2] = 2; b[3] = 2; b[4] = 3; b[5] = 3; b[6] = 0; b[7] = 0; b[8] = 0; b[9] = 5;
			board.push_back(b);
			b[0] = 1; b[1] = 1; b[2] = 1; b[3] = 0; b[4] = 0; b[5] = 0; b[6] = 0; b[7] = 0; b[8] = 0; b[9] = 5;
			board.push_back(b);

			cout << solution(board) << endl;

		}
	}
}