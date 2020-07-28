#include "problem16.h"

namespace KakaoBlind2018 {

    namespace problem16 {

        int solution(string str1, string str2) {

            // ��ī�� ���絵 ���.
            // �� ���ڿ��� ���ڸ� 2���� �ڸ���.
            // ex) french -> fr, re, en, nc ,ch

            // �� ���ڿ��� ������ �����հ� ������ ���� ���ϰ� ������ ��ī�� ���絵 Ȯ��.
            // (������ ���� �� �ߺ� ���� �� ����ؾ� ��.)
            // ������� 65536�� ���ϰ� �Ҽ��� ���� ������ ���.

            int answer = 0;

            vector<pair<string, int>> map1, map2;

            double intersectionCount = 0;

            // ���� �ҹ��ڷ� ��ȯ
            for (int i = 0; i < str1.length(); i++)
                str1[i] = tolower(str1[i]);
            for (int i = 0; i < str2.length(); i++)
                str2[i] = tolower(str2[i]);

            for (int i = 0; i < str1.length() - 1; i++) {

                // �ΰ� ���� ��� ���ĺ��� ��쿡�� ���ҷ� ä��.
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
                // �� �� ������.
                answer = 65536;
            }
            else {

                // ������ ���� ���ϱ�.
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