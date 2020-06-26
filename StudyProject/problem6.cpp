#include "problem6.h"

int paddingBoard[102][102] = { {}, };
int dp[102][102] = { {}, };

int KakaoBlind2020::problem6::solution(vector<vector<int>> board) {
    
    int answer = 0;
    int n = board.size();

    // padding 작업
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
                paddingBoard[i][j] = 1;
            else {
                paddingBoard[i][j] = board[i - 1][j - 1];
                dp[i][j] = -1; // 각 위치의 시간을 -1로 초기화.
            }
        }
    }

    stack<vector<pair<int, int>>> st;

    // 시작점 설정.
    vector<pair<int, int>> curPos;
    curPos.push_back(make_pair<int, int>(1, 1));
    curPos.push_back(make_pair<int, int>(1, 2));

    st.push(curPos);

    // DFS
    while (!st.empty()) {

        vector<pair<int, int>> top = st.top();

        // 모든 움직일 수 있는 경우를 보고 경우가 있다면 stack에 넣고
        // 아무 경우도 없다면 stack.pop();

        // 현재 기계의 모양 확인. ㅇ-ㅇ 인지 ㅇ 인지.
        //                                   ㅣ
        //                                   ㅇ
        
        int y1 = top[0].first, y2 = top[1].first;
        int x1 = top[0].second, x2 = top[1].second;

        if (y1 == y2) {
            // 가로 모양.

            // 1. 오른쪽으로 이동.
            // a. 벽이 없고 b. 해당 시간이 현재 시간보다 짧거나 아직 가본 위치가 아닐 경우
            if (paddingBoard[y2][x2 + 1] == 0
                && (dp[y2][x2 + 1] == -1 || dp[y2][x2 + 1] > dp[y2][x2] + 1)) {
                top[1].second++;
                st.push(top);
                dp[top[1].first][top[1].second] = dp[y2][x2] + 1;
            }
            // 2. 왼쪽으로 이동.
            // 조건 검사는 오른쪽 이동과 같음.
            else if (paddingBoard[y1][x1 - 1] == 0
                && (dp[y1][x1 - 1] == -1 || dp[y1][x1 - 1] > dp[y1][x1] + 1)) {
                top[0].second--;
                st.push(top);
                dp[top[0].first][top[0].second] = dp[y1][x1] + 1;
            }
            // 3. 위쪽으로 이동.
            // a. 벽이 없고 b. 
            //else if ()
            // 4. 아래쪽으로 이동.
            // 5. 시계 방향으로 회전.
            // 6. 반시계 방향으로 회전.
        }
        else {
            // 세로 모양.
        }

        
    }

    

    return answer;
}

void KakaoBlind2020::problem6::execute() {

   /* vector<vector<int>> v;
    vector<int> temp;
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    v.push_back(temp);
    v.push_back(temp);
    v.push_back(temp);
    
    solution(v);*/

    vector<pair<int,int>> v;

    v.push_back(make_pair<int, int>(1, 3));
    v.push_back(make_pair<int, int>(3, 4));
    v.push_back(make_pair<int, int>(3, 3));
    v.push_back(make_pair<int, int>(2, 3));

    for (auto a : v)
        cout << "(" << a.first << "," << a.second << ")" << " ";

    cout << endl << endl;

    sort(v.begin(), v.end());


    for (auto a : v)
        cout << "(" << a.first << "," << a.second << ")" << " ";

}