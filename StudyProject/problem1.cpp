#include "problem1.h"

namespace KakaoBlind2020 {

	namespace problem1 {

		int solution(string s) {

			int answer = s.length();

			// 2개 단위부터 문자열길이 / 2 단위까지 잘라서 확인해보고
			// 가장 작은 문자열 길이 출력.
			for (int i = 1; i <= s.length() / 2; i++) {

				// i 단위에서 잘라서 문자열 길이 확인.

				string str = ""; // 이전 문자열.
				int strLength = 0; // i 단위로 잘랐을 때의 문자열 길이.
				int sameNum = 0; // 현재 초점 맞추고 있는 문자열의 같은 개수.

				// i 단위씩 움직이면서 확인
				for (int j = 0; j < s.length(); j += i) {

					// 마지막 문자열이 i 단위보다 길이가 작은 문자열일 경우
					// 남은 문자열 길이 모두 추가.
					if (j > s.length() - i) {

						strLength += (s.length() - j);

						if (sameNum > 98) // 같은 문자열이 99개 이상이면 현재 문자열 포함 100개 이상이므로 3자리 추가.
							strLength += 3;
						else if (sameNum > 8) // 9개 이상이면 현재 포함 10개 이상이므로 2자리 추가.
							strLength += 2;
						else if (sameNum > 0) // 1개 이상이면 현재 포함 2개 이상이므로 1자리 추가.(1개는 표시 안함.)
							strLength += 1;

						break;
					}

					// 현재 위치에서부터 i 길이의 문자열 구하기.
					//string checkStr = s.substr(j, i);
					string checkStr = "";
					for (int k = j; k < j + i; k++)
						checkStr += s[k];

					// 이전 확인했던 문자열과 비교.
					// 처음이라면 이전 문자열은 ""이다.e
					if (!str.compare(checkStr)) {
						// 이전 문자열과 같은 경우
						// 같은 문자열의 개수를 + 해줌.
						sameNum++;

						if (j == s.length() - i) {
							if (sameNum > 98) // 같은 문자열이 99개 이상이면 현재 문자열 포함 100개 이상이므로 3자리 추가.
								strLength += 3;
							else if (sameNum > 8) // 9개 이상이면 현재 포함 10개 이상이므로 2자리 추가.
								strLength += 2;
							else if (sameNum > 0) // 1개 이상이면 현재 포함 2개 이상이므로 1자리 추가.(1개는 표시 안함.)
								strLength += 1;

							sameNum = 0;
						}
					}
					else {
						// 처음 문자열이거나 이전 문자열과 다를 경우
						// 새 문자열의 길이를 + 해주고
						// 혹시 이전까지의 문자열의 개수가 여러개일 경우
						// 개수를 표시해주는 숫자만큼 길이 + 해주기.
						strLength += i;//checkStr.length(); // i 길이 추가.
						str = checkStr; // 확인할 문자열을 바꿈.

						if (sameNum > 98) // 같은 문자열이 99개 이상이면 현재 문자열 포함 100개 이상이므로 3자리 추가.
							strLength += 3;
						else if (sameNum > 8) // 9개 이상이면 현재 포함 10개 이상이므로 2자리 추가.
							strLength += 2;
						else if (sameNum > 0) // 1개 이상이면 현재 포함 2개 이상이므로 1자리 추가.(1개는 표시 안함.)
							strLength += 1;

						sameNum = 0;
					}

				}

				// 이전 단위로 잘랐을 경우의 문자열 길이와 비교해서
				// 더 짧으면 변경.
				if (answer > strLength)
					answer = strLength;
			}

			return answer;
		}


		void execute() {

			string str = "abcabcdede";
			cout << solution(str) << endl;

		}

	}

}