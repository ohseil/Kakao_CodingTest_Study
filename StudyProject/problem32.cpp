#include "problem32.h"

namespace KakaoIntern2020 {

	namespace problem32 {

		// Ű ������ �Ÿ���� �Լ�
		int distanceKey(pair<int, int> pos1, pair<int, int> pos2) {
			return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
		}

		string solution(vector<int> numbers, string hand) {

			string answer = "";

			// Ű�е� ��ǥ ����
			map<int, pair<int, int>> m;
			m[1].first = 0, m[1].second = 3;
			m[2].first = 1, m[2].second = 3;
			m[3].first = 2, m[3].second = 3;
			m[4].first = 0, m[4].second = 2;
			m[5].first = 1, m[5].second = 2;
			m[6].first = 2, m[6].second = 2;
			m[7].first = 0, m[7].second = 1;
			m[8].first = 1, m[8].second = 1;
			m[9].first = 2, m[9].second = 1;
			m[0].first = 1, m[0].second = 0;

			// �޼�, ������ ��ǥ �ʱ�ȭ
			pair<int, int> posL, posR;
			posL.first = 0, posL.second = 0;
			posR.first = 2, posR.second = 0;

			for (int number : numbers) {

				if (number == 1 || number == 4 || number == 7) {
					// �޼� Ű�е�
					answer += "L";
					posL = m[number];
				}
				else if (number == 3 || number == 6 || number == 9) {
					// ������ Ű�е�
					answer += "R";
					posR = m[number];
				}
				else {
					// �߰� Ű�е�
					if (distanceKey(posL, m[number]) < distanceKey(posR, m[number])) {
						// �޼� �Ÿ��� �� ������
						answer += "L";
						posL = m[number];
					}
					else if (distanceKey(posL, m[number]) > distanceKey(posR, m[number])) {
						// ������ �Ÿ��� �� ������
						answer += "R";
						posR = m[number];
					}
					else {
						// �Ÿ��� ������� �������������� �޼��������� Ȯ��
						if (hand == "left") {
							answer += "L";
							posL = m[number];
						}
						else {
							answer += "R";
							posR = m[number];
						}
					}
				}
			}

			return answer;
		}

		void execute() {

			vector<int> numbers;
			string hand = "left";
			numbers.push_back(7);
			numbers.push_back(0);
			numbers.push_back(8);
			numbers.push_back(2);
			numbers.push_back(8);
			numbers.push_back(3);
			numbers.push_back(1);
			numbers.push_back(5);
			numbers.push_back(7);
			numbers.push_back(6);
			numbers.push_back(2);

			cout << solution(numbers, hand) << endl;
		}
	}
}