#include "problem16.h"

namespace KakaoBlind2018 {

    namespace problem16 {

        int solution(string str1, string str2) {

            // 자카드 유사도 출력.
            // 각 문자열의 문자를 2개씩 자른다.
            // ex) french -> fr, re, en, nc ,ch

            // 각 문자열의 집합중 합집합과 교집합 개수 구하고 나누어 자카드 유사도 확인.
            // (교집합 구할 때 중복 원소 잘 고려해야 함.)
            // 결과값에 65536을 곱하고 소수점 밑은 버리고 출력.

            int answer = 0;

            vector<pair<string, int>> map1, map2;

            double intersectionCount = 0;

            // 전부 소문자로 변환
            for (int i = 0; i < str1.length(); i++)
                str1[i] = tolower(str1[i]);
            for (int i = 0; i < str2.length(); i++)
                str2[i] = tolower(str2[i]);

            for (int i = 0; i < str1.length() - 1; i++) {

                // 두개 문자 모두 알파벳인 경우에만 원소로 채택.
                if (97 <= (int)str1[i] && (int)str1[i] <= 122
                    && 97 <= (int)str1[i + 1] && (int)str1[i + 1] <= 122) {
                    string temp = "";
                    temp += str1[i];
                    temp += str1[i + 1];
                    map1.push_back(make_pair<string, int>((string)temp, 1));
                }
            }
            for (int i = 0; i < str2.length() - 1; i++) {
                if (97 <= (int)str2[i] && (int)str2[i] <= 122
                    && 97 <= (int)str2[i + 1] && (int)str2[i + 1] <= 122) {
                    string temp = "";
                    temp += str2[i];
                    temp += str2[i + 1];
                    map2.push_back(make_pair<string, int>((string)temp, 1));
                }
            }

            if (map1.empty() && map2.empty()) {
                // 둘 다 공집합.
                answer = 65536;
            }
            else {

                // 교집합 개수 구하기.
                for (int i = 0; i < map1.size(); i++) {
                    for (int j = 0; j < map2.size(); j++) {
                        if (map1[i].first == map2[j].first && map2[j].second == 1) {
                            intersectionCount += 1;
                            map2[j].second = -1;
                            break;
                        }
                    }
                }

                double result = (intersectionCount / (map1.size() + map2.size() - intersectionCount)) * 65536;

                answer = (int)result;
            }

            return answer;
        }

        void execute() {

            string str1 = "aa1+aa2";
            string str2 = "AAAA12";

            cout << solution(str1, str2) << endl;
        }
    }
}