#include "problem23.h"

namespace KakaoBlind2018 {

	namespace problem23 {

		// 사전 검색 함수
		int findMap(vector<string> strMap, string str) {
			for (int i = 0; i < strMap.size(); i++)
				if (strMap[i] == str)
					return i;
			return -1;
		}

		vector<int> solution(string msg) {

			// 문자열 압축 알고리즘 LZW 구현

			vector<int> answer;

			vector<string> strMap;

			// 길이 1 문자열 "A" ~ "Z" 사전 구성.
			for (int i = 65; i <= 90; i++) {
				string temp(1, (char)i);
				strMap.push_back(temp);
			}

			int foundNum = 0;

			for (int i = 0; i < msg.length(); i += foundNum) {

				string check = "";
				foundNum = 0;

				for (int j = i; j < msg.length(); j++) {

					check += msg[j];
					int findIndex = findMap(strMap, check);
					if (findIndex != -1) {
						// 사전에 등록되어있다면
						foundNum++;

						// 마지막 문자가 포함된 문자열이라면
						if (j == msg.length() - 1) {
							answer.push_back(findIndex + 1);
							foundNum = msg.length();
							break;
						}
					}
					else {
						// 등록되어있지 않다면 이전 문자열 index 출력, 현재 문자열 사전 등록.
						answer.push_back(findMap(strMap, check.substr(0, check.length() - 1)) + 1);
						strMap.push_back(check);
						break;
					}
				}
			}


			return answer;
		}

		void execute() {

			string str = "TOBEORNOTTOBEORTOBEORNOT";

			vector<int> v = solution(str);

			for (auto a : v)
				cout << a << " ";
			cout << endl;

		}
	}
}