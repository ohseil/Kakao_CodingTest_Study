#include "problem4.h"

namespace KakaoBlind2020 {

	namespace problem4 {

		int cFrame[101][101] = { {}, };
		int bFrame[101][101] = { {}, };

		// �� ����Ȯ�� �Լ�
		bool checkB(int x, int y) {

			// ���� �� �κ��� ��� ��
			// ���� �� �κ��� �ٸ� ���� ���� ����

			if (cFrame[x][y - 1] == 1 || cFrame[x + 1][y - 1] == 1) return true;
			if (x > 0 && bFrame[x - 1][y] == 1 && x < 100 && bFrame[x + 1][y] == 1) return true;

			return false;
		}

		// ��� ����Ȯ�� �Լ�
		bool checkC(int x, int y) {

			// �ٴ� ��
			// �� ���� �� ��
			// �ٸ� ��� ��
			if (y == 0) return true;
			if (x > 0 && bFrame[x - 1][y] == 1) return true;
			if (bFrame[x][y] == 1) return true;
			if (cFrame[x][y - 1] == 1) return true;

			return false;
		}

		// ���� ��ġ�� ��� ��հ� ���� ���� ���� �˻��ϴ� �Լ�.
		bool checkFrame() {

			for (int i = 0; i < 101; i++) {
				for (int j = 0; j < 101; j++) {
					if ((bFrame[i][j] == 1 && checkB(i, j) == false) || (cFrame[i][j] == 1 && checkC(i, j) == false))
						return false;
				}
			}

			return true;
		}

		vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {

			vector<vector<int>> answer;

			for (auto frame : build_frame) {

				if (frame[3] == 0) {
					// ����

					if (frame[2] == 0) {
						// ���
						cFrame[frame[0]][frame[1]] = 0;
						if (checkFrame() == false)
							cFrame[frame[0]][frame[1]] = 1;
					}
					else {
						// ��
						bFrame[frame[0]][frame[1]] = 0;
						if (checkFrame() == false)
							bFrame[frame[0]][frame[1]] = 1;
					}
				}
				else {
					// ��ġ
					if (frame[2] == 0) {
						// ���
						if (checkC(frame[0], frame[1]) == true) {
							cFrame[frame[0]][frame[1]] = 1;
						}
					}
					else {
						// ��
						if (checkB(frame[0], frame[1]) == true) {
							bFrame[frame[0]][frame[1]] = 1;
						}
					}
				}

			}

			for (int i = 0; i < 101; i++) {
				for (int j = 0; j < 101; j++) {
					if (cFrame[i][j] == 1) {
						vector<int> temp;
						temp.push_back(i);
						temp.push_back(j);
						temp.push_back(0);
						answer.push_back(temp);
					}
					if (bFrame[i][j] == 1) {
						vector<int> temp;
						temp.push_back(i);
						temp.push_back(j);
						temp.push_back(1);
						answer.push_back(temp);
					}
				}
			}

			return answer;
		}

		void execute() {


		}

	}

}