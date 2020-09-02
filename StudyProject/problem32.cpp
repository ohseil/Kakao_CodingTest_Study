#include "problem32.h"

namespace KakaoIntern2020 {

	namespace problem32 {

		// 키 사이의 거리계산 함수
		int distanceKey(pair<int, int> pos1, pair<int, int> pos2) {
			return abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second);
		}

		string solution(vector<int> numbers, string hand) {

			string answer = "";

			// 키패드 좌표 설정
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

			// 왼손, 오른손 좌표 초기화
			pair<int, int> posL, posR;
			posL.first = 0, posL.second = 0;
			posR.first = 2, posR.second = 0;

			for (int number : numbers) {

				if (number == 1 || number == 4 || number == 7) {
					// 왼손 키패드
					answer += "L";
					posL = m[number];
				}
				else if (number == 3 || number == 6 || number == 9) {
					// 오른손 키패드
					answer += "R";
					posR = m[number];
				}
				else {
					// 중간 키패드
					if (distanceKey(posL, m[number]) < distanceKey(posR, m[number])) {
						// 왼손 거리가 더 가깝다
						answer += "L";
						posL = m[number];
					}
					else if (distanceKey(posL, m[number]) > distanceKey(posR, m[number])) {
						// 오른손 거리가 더 가깝다
						answer += "R";
						posR = m[number];
					}
					else {
						// 거리가 같은경우 오른손잡이인지 왼손잡이인지 확인
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