#include "problem6.h"

int paddingBoard[102][102] = { {}, };
int dp[102][102] = { {}, };

int KakaoBlind2020::problem6::solution(vector<vector<int>> board) {
    
    int answer = 0;
    int n = board.size();

    // padding �۾�
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
                paddingBoard[i][j] = 1;
            else {
                paddingBoard[i][j] = board[i - 1][j - 1];
                dp[i][j] = -1; // �� ��ġ�� �ð��� -1�� �ʱ�ȭ.
            }
        }
    }

    stack<vector<pair<int, int>>> st;

    // ������ ����.
    vector<pair<int, int>> curPos;
    curPos.push_back(make_pair<int, int>(1, 1));
    curPos.push_back(make_pair<int, int>(1, 2));

    st.push(curPos);

    // DFS
    while (!st.empty()) {

        vector<pair<int, int>> top = st.top();

        // ��� ������ �� �ִ� ��츦 ���� ��찡 �ִٸ� stack�� �ְ�
        // �ƹ� ��쵵 ���ٸ� stack.pop();

        // ���� ����� ��� Ȯ��. ��-�� ���� �� ����.
        //                                   ��
        //                                   ��
        
        int y1 = top[0].first, y2 = top[1].first;
        int x1 = top[0].second, x2 = top[1].second;

        if (y1 == y2) {
            // ���� ���.

            // 1. ���������� �̵�.
            // a. ���� ���� b. �ش� �ð��� ���� �ð����� ª�ų� ���� ���� ��ġ�� �ƴ� ���
            if (paddingBoard[y2][x2 + 1] == 0
                && (dp[y2][x2 + 1] == -1 || dp[y2][x2 + 1] > dp[y2][x2] + 1)) {
                top[1].second++;
                st.push(top);
                dp[top[1].first][top[1].second] = dp[y2][x2] + 1;
            }
            // 2. �������� �̵�.
            // ���� �˻�� ������ �̵��� ����.
            else if (paddingBoard[y1][x1 - 1] == 0
                && (dp[y1][x1 - 1] == -1 || dp[y1][x1 - 1] > dp[y1][x1] + 1)) {
                top[0].second--;
                st.push(top);
                dp[top[0].first][top[0].second] = dp[y1][x1] + 1;
            }
            // 3. �������� �̵�.
            // a. ���� ���� b. 
            //else if ()
            // 4. �Ʒ������� �̵�.
            // 5. �ð� �������� ȸ��.
            // 6. �ݽð� �������� ȸ��.
        }
        else {
            // ���� ���.
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