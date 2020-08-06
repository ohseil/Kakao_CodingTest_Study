#include "problem25.h"

namespace KakaoBlind2018 {

    namespace problem25 {

        // sorting 함수
        bool comp(pair<string, pair<string, int>> p1, pair<string, pair<string, int>> p2) {
            // first : head, second : number
            pair<string, int> lhs = p1.second, rhs = p2.second;

            if (lhs.first < rhs.first)
                return true;
            else if (lhs.first == rhs.first)
                if (lhs.second < rhs.second)
                    return true;
            return false;
        }

        // 데이터 가공 함수
        pair<string, int> OrganizeData(string file) {

            pair<string, int> result;
            string head = "", number = "";

            // 모두 소문자로 변경.
            for (int i = 0; i < file.length(); i++)
                file[i] = tolower(file[i]);

            // head 데이터 가공
            for (int i = 0; i < file.length(); i++) {
                if (48 <= file[i] && file[i] <= 57) {// 숫자가 나오면
                    head = file.substr(0, i);
                    file = file.substr(i);
                    break;
                }
            }

            // number 데이터 가공
            for (int i = 0; i < file.length(); i++) {
                // 문자가 나오거나 숫자 5개가 넘어가거나
                if (!(48 <= file[i] && file[i] <= 57) || i > 4) {
                    number = file.substr(0, i);
                    break;
                }
                else {
                    // 마지막 문자
                    if (i == file.length() - 1)
                        number = file.substr(0);
                }
            }

            result = make_pair<string, int>((string)head, stoi(number));

            return result;
        }

        vector<string> solution(vector<string> files) {

            // 정렬 알고리즘.
            // HEAD, NUMBER, TAIL
            // number 숫자는 5자리까지 가능.
            // tail에는 숫자나 문자 아무거나 가능.
            // %주의 : number 다음에 tail에 바로 숫자가 올 수 있으므로,
            // 숫자가 5자리가 넘어가는 부분을 고려.

            // [ 정렬 조건 ]
            // 1. HEAD의 문자열의 사전순. (대소문자 고려 안함.)
            // 2. 위의 조건이 같다면 숫자 작은 순으로.

            vector<string> answer;

            vector<pair<string, pair<string, int>>> v;

            for (string file : files) {
                pair<string, pair<string, int>> data;
                data.first = file;
                data.second = OrganizeData(file);
                v.push_back(data);
            }

            // 일반 sort는 퀵정렬로 구현되어 있어 불안정 정렬이다.
            // stable_sort는 버블정렬로 구현되어 있어 안정 정렬이다.
            stable_sort(v.begin(), v.end(), comp);

            for (auto file : v)
                answer.push_back(file.first);

            return answer;
        }

        void execute() {

            vector<string> files;
            files.push_back("img12.png");
            files.push_back("img10.png");
            files.push_back("img02.png");
            files.push_back("img1.png");
            files.push_back("IMG01.GIF");
            files.push_back("img2.JPG");

            vector<string> result = solution(files);

            for (string file : result)
                cout << file << endl;

        }
    }
}