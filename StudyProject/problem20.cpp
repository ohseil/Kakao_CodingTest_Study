#include "problem20.h"

namespace KakaoBlind2018 {

    namespace problem20 {

        // 이진수로 변환하는 함수
        vector<int> toBinary(int num, int n) {

            vector<int> binaryNum, result;

            while (num != 0) {
                binaryNum.push_back(num % 2);
                num /= 2;
            }

            if (binaryNum.size() == n) {
                for (int i = binaryNum.size() - 1; i >= 0; i--)
                    result.push_back(binaryNum[i]);
            }
            else {
                for (int i = 0; i < n - binaryNum.size(); i++)
                    result.push_back(0);
                for (int i = binaryNum.size() - 1; i >= 0; i--)
                    result.push_back(binaryNum[i]);
            }

            return result;
        }

        vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

            // 벽 = 1 = '#'
            // 공백 = 0 = ' '

            vector<string> answer;

            vector<vector<int>> map1, map2;

            // 이진수로 변환하여 map 생성.
            for (auto a : arr1)
                map1.push_back(toBinary(a, n));
            for (auto a : arr2)
                map2.push_back(toBinary(a, n));

            // 지도 2개를 비교하여 문자열 생성
            for (int i = 0; i < n; i++) {

                string str = "";

                for (int j = 0; j < n; j++) {

                    if (map1[i][j] == 1 || map2[i][j] == 1)
                        str += '#';
                    else
                        str += ' ';
                }

                answer.push_back(str);
            }

            return answer;
        }

        void execute() {

            vector<int> arr1, arr2;

            arr1.push_back(9);
            arr1.push_back(20);
            arr1.push_back(28);
            arr1.push_back(18);
            arr1.push_back(11);

            arr2.push_back(30);
            arr2.push_back(1);
            arr2.push_back(21);
            arr2.push_back(17);
            arr2.push_back(28);

            vector<string> result = solution(5, arr1, arr2);

            for (string str : result)
                cout << str << endl;
            cout << endl;
        }
    }
}