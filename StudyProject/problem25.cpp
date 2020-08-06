#include "problem25.h"

namespace KakaoBlind2018 {

    namespace problem25 {

        // sorting �Լ�
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

        // ������ ���� �Լ�
        pair<string, int> OrganizeData(string file) {

            pair<string, int> result;
            string head = "", number = "";

            // ��� �ҹ��ڷ� ����.
            for (int i = 0; i < file.length(); i++)
                file[i] = tolower(file[i]);

            // head ������ ����
            for (int i = 0; i < file.length(); i++) {
                if (48 <= file[i] && file[i] <= 57) {// ���ڰ� ������
                    head = file.substr(0, i);
                    file = file.substr(i);
                    break;
                }
            }

            // number ������ ����
            for (int i = 0; i < file.length(); i++) {
                // ���ڰ� �����ų� ���� 5���� �Ѿ�ų�
                if (!(48 <= file[i] && file[i] <= 57) || i > 4) {
                    number = file.substr(0, i);
                    break;
                }
                else {
                    // ������ ����
                    if (i == file.length() - 1)
                        number = file.substr(0);
                }
            }

            result = make_pair<string, int>((string)head, stoi(number));

            return result;
        }

        vector<string> solution(vector<string> files) {

            // ���� �˰���.
            // HEAD, NUMBER, TAIL
            // number ���ڴ� 5�ڸ����� ����.
            // tail���� ���ڳ� ���� �ƹ��ų� ����.
            // %���� : number ������ tail�� �ٷ� ���ڰ� �� �� �����Ƿ�,
            // ���ڰ� 5�ڸ��� �Ѿ�� �κ��� ���.

            // [ ���� ���� ]
            // 1. HEAD�� ���ڿ��� ������. (��ҹ��� ��� ����.)
            // 2. ���� ������ ���ٸ� ���� ���� ������.

            vector<string> answer;

            vector<pair<string, pair<string, int>>> v;

            for (string file : files) {
                pair<string, pair<string, int>> data;
                data.first = file;
                data.second = OrganizeData(file);
                v.push_back(data);
            }

            // �Ϲ� sort�� �����ķ� �����Ǿ� �־� �Ҿ��� �����̴�.
            // stable_sort�� �������ķ� �����Ǿ� �־� ���� �����̴�.
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