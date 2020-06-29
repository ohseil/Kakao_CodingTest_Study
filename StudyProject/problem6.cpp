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

    // padding 작업
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

    // 시작점 설정.
    machine start;
    start.pos.push_back(make_pair<int,int>(1,1)), start.pos.push_back(make_pair<int, int>(1, 2));
    start.time = 0;

    visited[start.pos] = 1;

    st.push(start);

    // BFS
    while (!st.empty()) {

        machine top = st.front();
        st.pop();

        // n, n 위치에 도착.
        if ((top.pos[0].first == n && top.pos[0].second == n)
            || (top.pos[1].first == n && top.pos[1].second == n)) {
            answer = top.time;
            return answer;
        }

        vector<vector<pair<int, int>>> canMove;
        vector<pair<int, int>> temp;

        // 좌표 기준을 잡기 위해 x,y 좌표들 정렬해서
        // 항상 더 왼쪽, 더 위쪽이 첫번째 노드로 오도록 정렬한다.
        sort(top.pos.begin(), top.pos.end());

        // 모든 움직일 수 있는 경우를 보고 경우가 있다면 stack에 넣고
        // 아무 경우도 없다면 stack.pop();

        // 현재 기계의 모양 확인. ㅇ-ㅇ 인지 ㅇ 인지.
        //                                   ㅣ
        //                                   ㅇ
        
        int y1 = top.pos[0].first, y2 = top.pos[1].first;
        int x1 = top.pos[0].second, x2 = top.pos[1].second;

        if (y1 == y2) {
            // 가로 모양.

            // 1. 오른쪽으로 이동.
            if (paddingBoard[y2][x2 + 1] == 0) {
                temp = top.pos;
                temp[1].second++, temp[0].second++;
                canMove.push_back(temp);
            }
            // 2. 왼쪽으로 이동.
            // 조건 검사는 오른쪽 이동과 같음.
            if (paddingBoard[y1][x1 - 1] == 0) {
                temp = top.pos;
                temp[0].second--, temp[1].second--;
                canMove.push_back(temp);
            }
            // 3. 위쪽으로 이동.
            // a. 벽이 없고 b. 위에 두 지점중 하나라도 (현재시간보다 잛거나 가본 위치가 아닐경우의) 조건이 맞는 경우
            if (paddingBoard[y1 - 1][x1] == 0 && paddingBoard[y2 - 1][x2] == 0) {
                temp = top.pos;
                temp[0].first--, temp[1].first--;
                canMove.push_back(temp);
            }
            // 4. 아래쪽으로 이동.
            // 위로 이동의 조건과 동일.
            if (paddingBoard[y1 + 1][x1] == 0 && paddingBoard[y2 + 1][x2] == 0) {
                temp = top.pos;
                temp[0].first++, temp[1].first++;
                canMove.push_back(temp);
            }
            // 5. 회전
			// 시계방향 2가지 (1번째 노드 움직이기, 2번째 노드 움직이기)
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
			// 반시계방향 2가지
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
            // 세로 모양.
            // 1.오른쪽으로 이동.
            if (paddingBoard[y1][x1 + 1] == 0 && paddingBoard[y2][x2 + 1] == 0) {
                temp = top.pos;
                temp[0].second++, temp[1].second++;
                canMove.push_back(temp);
            }
            // 2. 왼쪽으로 이동.
            if (paddingBoard[y1][x1 - 1] == 0 && paddingBoard[y2][x2 - 1] == 0) {
                temp = top.pos;
                temp[0].second--, temp[1].second--;
                canMove.push_back(temp);
            }
            // 3. 위쪽으로 이동.
            if (paddingBoard[y1 - 1][x1] == 0) {
                temp = top.pos;
                temp[0].first--, temp[1].first--;;
                canMove.push_back(temp);
            }
            // 4. 아래쪽으로 이동.
            if (paddingBoard[y2 + 1][x2] == 0) {
                temp = top.pos;
                temp[1].first++, temp[0].first++;
                canMove.push_back(temp);
            }
            // 5. 회전
		    // 시계방향 2가지
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
			// 반시계방향 2가지
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
                cout << " 좌표 1,3 2,3" << endl;
            }*/
        }

        top.time++;

        for (auto moveData : canMove) {
            // 방문하지 않은 경로라면 큐에 추가하고 방문기록 작성.
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