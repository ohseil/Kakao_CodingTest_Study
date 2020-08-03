#include "problem18.h"

namespace KakaoBlind2018 {

    namespace problem18 {

        // 2 x 2 사각형의 각 블록이 같은 문자인지 확인하는 함수
        bool canErased(char ch1, char ch2, char ch3, char ch4) {
            return ch1 == ch2 && ch2 == ch3 && ch3 == ch4;
        }

        int solution(int m, int n, vector<string> board) {

            // m : 높이, n : 가로
            // 블록 종류 : A ~ Z
            // 빈공간 : @으로 설정.

            int answer = 0;

            set<pair<int, int>> erased;

            while (true) {

                erased.clear();

                for (int i = 0; i < m - 1; i++) {
                    for (int j = 0; j < n - 1; j++) {

                        // 2 x 2 사각형 지워지는 조건 충족.
                        if (board[i][j] != '@' && canErased(board[i][j], board[i + 1][j], board[i][j + 1], board[i + 1][j + 1]) == true) {
                            erased.insert(make_pair<int, int>((int)i, (int)j));
                            erased.insert(make_pair<int, int>((int)i + 1, (int)j));
                            erased.insert(make_pair<int, int>((int)i, (int)j + 1));
                            erased.insert(make_pair<int, int>((int)i + 1, (int)j + 1));
                        }

                    }
                }

                // 지워지는 블록이 있는 경우
                if (!erased.empty()) {

                    answer += erased.size();

                    // 지워진 블록 표시
                    for (auto block : erased)
                        board[block.first][block.second] = '@';

                    // 위에있는 블록들 아래로 채우기.
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
                    // 지워지는 블록이 없는 경우 break.
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