#include "problem6.h"

int paddingBoard[102][102] = { {}, };

struct machine {
    vector<pair<int, int>> pos;
    int time = 0;
};

bool isVisited(vector<pair<int, int>> checkData, map<vector<pair<int,int>>, int> visited) {
    if (visited[checkData] == 1)
        return true;
    return false;
}

int KakaoBlind2020::problem6::solution(vector<vector<int>> board) {
    
    int answer = 0;
    int n = board.size();

    // padding �۾�
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
                paddingBoard[i][j] = 1;
            else
                paddingBoard[i][j] = board[i - 1][j - 1];
        }
    }

    map<vector<pair<int,int>>, int> visited;
    
    queue<machine> st;

    // ������ ����.
    machine start;
    start.pos.push_back(make_pair<int,int>(1,1)), start.pos.push_back(make_pair<int, int>(1, 2));
    start.time = 0;

    visited[start.pos] = 1;

    st.push(start);

    // BFS
    while (!st.empty()) {

        machine top = st.front();
        st.pop();

        // n, n ��ġ�� ����.
        if ((top.pos[0].first == n && top.pos[0].second == n)
            || (top.pos[1].first == n && top.pos[1].second == n)) {
            answer = top.time;
            return answer;
        }

        vector<vector<pair<int, int>>> canMove;
        vector<pair<int, int>> temp;

        // ��ǥ ������ ��� ���� x,y ��ǥ�� �����ؼ�
        // �׻� �� ����, �� ������ ù��° ���� ������ �����Ѵ�.
        sort(top.pos.begin(), top.pos.end());

        // ��� ������ �� �ִ� ��츦 ���� ��찡 �ִٸ� stack�� �ְ�
        // �ƹ� ��쵵 ���ٸ� stack.pop();

        // ���� ����� ��� Ȯ��. ��-�� ���� �� ����.
        //                                   ��
        //                                   ��
        
        int y1 = top.pos[0].first, y2 = top.pos[1].first;
        int x1 = top.pos[0].second, x2 = top.pos[1].second;

        if (y1 == y2) {
            // ���� ���.

            // 1. ���������� �̵�.
            if (paddingBoard[y2][x2 + 1] == 0) {
                temp = top.pos;
                temp[1].second++, temp[0].second++;
                canMove.push_back(temp);
            }
            // 2. �������� �̵�.
            // ���� �˻�� ������ �̵��� ����.
            if (paddingBoard[y1][x1 - 1] == 0) {
                temp = top.pos;
                temp[0].second--, temp[1].second--;
                canMove.push_back(temp);
            }
            // 3. �������� �̵�.
            // a. ���� ���� b. ���� �� ������ �ϳ��� (����ð����� ��ų� ���� ��ġ�� �ƴҰ����) ������ �´� ���
            if (paddingBoard[y1 - 1][x1] == 0 && paddingBoard[y2 - 1][x2] == 0) {
                temp = top.pos;
                temp[0].first--, temp[1].first--;
                canMove.push_back(temp);
            }
            // 4. �Ʒ������� �̵�.
            // ���� �̵��� ���ǰ� ����.
            if (paddingBoard[y1 + 1][x1] == 0 && paddingBoard[y2 + 1][x2] == 0) {
                temp = top.pos;
                temp[0].first++, temp[1].first++;
                canMove.push_back(temp);
            }
            // 5. ȸ��
			// �ð���� 2���� (1��° ��� �����̱�, 2��° ��� �����̱�)
			if (paddingBoard[y1 - 1][x1 + 1] == 0 && paddingBoard[y1 - 1][x1] == 0) {
				temp = top.pos;
				temp[0].first--, temp[0].second++;
				canMove.push_back(temp);
			}
			if (paddingBoard[y2 + 1][x2 - 1] == 0 && paddingBoard[y2 + 1][x2] == 0) {
				temp = top.pos;
				temp[1].first++, temp[1].second--;
				canMove.push_back(temp);
			}
			// �ݽð���� 2����
			if (paddingBoard[y2 - 1][x2 - 1] == 0 && paddingBoard[y2 - 1][x2] == 0) {
				temp = top.pos;
				temp[1].first--, temp[1].second--;
				canMove.push_back(temp);
			}
			if (paddingBoard[y1 + 1][x1 + 1] == 0 && paddingBoard[y1 + 1][x1] == 0) {
				temp = top.pos;
				temp[0].first++, temp[0].second++;
				canMove.push_back(temp);
			}
            
        }
        else {
            // ���� ���.
            // 1.���������� �̵�.
            if (paddingBoard[y1][x1 + 1] == 0 && paddingBoard[y2][x2 + 1] == 0) {
                temp = top.pos;
                temp[0].second++, temp[1].second++;
                canMove.push_back(temp);
            }
            // 2. �������� �̵�.
            if (paddingBoard[y1][x1 - 1] == 0 && paddingBoard[y2][x2 - 1] == 0) {
                temp = top.pos;
                temp[0].second--, temp[1].second--;
                canMove.push_back(temp);
            }
            // 3. �������� �̵�.
            if (paddingBoard[y1 - 1][x1] == 0) {
                temp = top.pos;
                temp[0].first--, temp[1].first--;;
                canMove.push_back(temp);
            }
            // 4. �Ʒ������� �̵�.
            if (paddingBoard[y2 + 1][x2] == 0) {
                temp = top.pos;
                temp[1].first++, temp[0].first++;
                canMove.push_back(temp);
            }
            // 5. ȸ��
		    // �ð���� 2����
			if (paddingBoard[y1 + 1][x1 + 1] == 0 && paddingBoard[y1][x1 + 1] == 0) {
				temp = top.pos;
				temp[0].first++, temp[0].second++;
				canMove.push_back(temp);
			}
			if (paddingBoard[y2 - 1][x2 - 1] == 0 && paddingBoard[y2][x2 - 1] == 0) {
				temp = top.pos;
				temp[1].first--, temp[1].second--;
				canMove.push_back(temp);
			}
			// �ݽð���� 2����
			if (paddingBoard[y1 + 1][x1 - 1] == 0 && paddingBoard[y1][x1 - 1] == 0) {
				temp = top.pos;
				temp[0].first++, temp[0].second--;
				canMove.push_back(temp);
			}
			if (paddingBoard[y2 - 1][x2 + 1] == 0 && paddingBoard[y2][x2 + 1] == 0) {
				temp = top.pos;
				temp[1].first--, temp[1].second++;
				canMove.push_back(temp);
			}
            
            /*
            if (top.pos[0].first == 1 && top.pos[0].second == 3
                && top.pos[1].first == 2 && top.pos[1].second == 3) {
                cout << " ��ǥ 1,3 2,3" << endl;
            }*/
        }

        top.time++;

        for (auto moveData : canMove) {
            // �湮���� ���� ��ζ�� ť�� �߰��ϰ� �湮��� �ۼ�.
            if (isVisited(moveData, visited) == false) {
                top.pos = moveData;
                st.push(top);
                visited[moveData] = 1;
            }
        }
        
    }

    answer = -1;
    
    return answer;
}

void KakaoBlind2020::problem6::execute() {

    vector<vector<int>> v;
    vector<int> temp;
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(1);
    v.push_back(temp);
    temp[0] = 0, temp[1] = 0, temp[2] = 0, temp[3] = 1, temp[4] = 0;
    v.push_back(temp);
    temp[0] = 0, temp[1] = 1, temp[2] = 0, temp[3] = 1, temp[4] = 1;
    v.push_back(temp);
    temp[0] = 1, temp[1] = 1, temp[2] = 0, temp[3] = 0, temp[4] = 1;
    v.push_back(temp);
    temp[0] = 0, temp[1] = 0, temp[2] = 0, temp[3] = 0, temp[4] = 0;
    v.push_back(temp);
    
    cout << solution(v) << endl;

    
}