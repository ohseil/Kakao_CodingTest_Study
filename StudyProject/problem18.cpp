#include "problem18.h"

namespace KakaoBlind2018 {

    namespace problem18 {

        // 2 x 2 �簢���� �� ����� ���� �������� Ȯ���ϴ� �Լ�
        bool canErased(char ch1, char ch2, char ch3, char ch4) {
            return ch1 == ch2 && ch2 == ch3 && ch3 == ch4;
        }

        int solution(int m, int n, vector<string> board) {

            // m : ����, n : ����
            // ��� ���� : A ~ Z
            // ����� : @���� ����.

            int answer = 0;

            set<pair<int, int>> erased;

            while (true) {

                erased.clear();

                for (int i = 0; i < m - 1; i++) {
                    for (int j = 0; j < n - 1; j++) {

                        // 2 x 2 �簢�� �������� ���� ����.
                        if (board[i][j] != '@' && canErased(board[i][j], board[i + 1][j], board[i][j + 1], board[i + 1][j + 1]) == true) {
                            erased.insert(make_pair<int, int>((int)i, (int)j));
                            erased.insert(make_pair<int, int>((int)i + 1, (int)j));
                            erased.insert(make_pair<int, int>((int)i, (int)j + 1));
                            erased.insert(make_pair<int, int>((int)i + 1, (int)j + 1));
                        }

                    }
                }

                // �������� ����� �ִ� ���
                if (!erased.empty()) {

                    answer += erased.size();

                    // ������ ��� ǥ��
                    for (auto block : erased)
                        board[block.first][block.second] = '@';

                    // �����ִ� ��ϵ� �Ʒ��� ä���.
                    for (int i = 0; i < n; i++) {
                        vector<char> chv;
                        int erasedNum = 0;
                        for (int j = 0; j < m; j++) {
                            if (board[j][i] == '@')
                                erasedNum++;
                            else
                                chv.push_back(board[j][i]);
                        }

                        for (int j = 0; j < erasedNum; j++)
                            board[j][i] = '@';
                        for (int j = erasedNum; j < m; j++)
                            board[j][i] = chv[j - erasedNum];
                    }
                }
                else {
                    // �������� ����� ���� ��� break.
                    break;
                }
            }

            return answer;
        }

        void execute() {

            int m = 4, n = 5;
            vector<string> board;
            board.push_back("CCBDE");
            board.push_back("AAADE");
            board.push_back("AAABF");
            board.push_back("CCBBF");

            cout << solution(m, n, board) << endl;
        }
    }
}