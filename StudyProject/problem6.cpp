#include "problem6.h"


int paddingBoard[102][102] = { {}, };

struct machine {
    vector<pair<int, int>> pos;
    int time = 0;
};

bool isVisited(vector<pair<int, int>> checkData, vector<vector<pair<int,int>>> visited) {
    for (auto a : visited)
		if (a[0].first == checkData[0].first && a[0].second == checkData[0].second
			&& a[1].first == checkData[1].first && a[1].second == checkData[1].second)
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

    vector<vector<pair<int,int>>> visited;
    
    queue<machine> st;

    // 시작점 설정.
    machine start;
    start.pos.push_back(make_pair<int,int>(1,1)), start.pos.push_back(make_pair<int, int>(1, 2));
    start.time = 0;

	visited.push_back(start.pos);

    st.push(start);
	int num = 0;
    // BFS
    while (!st.empty()) {
		cout << st.size() << " ";
        machine top = st.front();
        st.pop();
		
		cout << "(" << top.pos[0].first << "," << top.pos[0].second << ")(" << top.pos[1].first << "," << top.pos[1].second << ") ";
        // n, n 위치에 도착.
        if ((top.pos[0].first == n && top.pos[0].second == n)
            || (top.pos[1].first == n && top.pos[1].second == n)) {
            answer = top.time;
            return answer;
        }

        vector<vector<pair<int, int>>> canMove;
        machine temp;

        // 좌표 기준을 잡기 위해 x,y 좌표들 정렬해서
        // 항상 더 왼쪽, 더 위쪽이 첫번째 노드로 오도록 정렬한다.
        //sort(top.pos.begin(), top.pos.end());

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
                temp = top;
                temp.pos[1].second++, temp.pos[0].second++;

				if (isVisited(temp.pos, visited) == false) {
					temp.time++;
					st.push(temp);
					visited.push_back(temp.pos);
					cout << "in:[" << temp.pos[0].first << "," << temp.pos[0].second << "][" << temp.pos[1].first << "," << temp.pos[1].second << "] ";
				}
            }
            // 2. 왼쪽으로 이동.
            // 조건 검사는 오른쪽 이동과 같음.
            if (paddingBoard[y1][x1 - 1] == 0) {
                temp = top;
                temp.pos[0].second--, temp.pos[1].second--;
                
				if (isVisited(temp.pos, visited) == false) {
					temp.time++;
					st.push(temp);
					visited.push_back(temp.pos); cout << "in:[" << temp.pos[0].first << "," << temp.pos[0].second << "][" << temp.pos[1].first << "," << temp.pos[1].second << "] ";
				}
            }
            // 3. 위쪽으로 이동.
            // a. 벽이 없고 b. 위에 두 지점중 하나라도 (현재시간보다 잛거나 가본 위치가 아닐경우의) 조건이 맞는 경우
            if (paddingBoard[y1 - 1][x1] == 0 && paddingBoard[y2 - 1][x2] == 0) {
                temp = top;
                temp.pos[0].first--, temp.pos[1].first--;
                
				if (isVisited(temp.pos, visited) == false) {
					temp.time++;
					st.push(temp);
					visited.push_back(temp.pos); cout << "in:[" << temp.pos[0].first << "," << temp.pos[0].second << "][" << temp.pos[1].first << "," << temp.pos[1].second << "] ";
				}
            }
            // 4. 아래쪽으로 이동.
            // 위로 이동의 조건과 동일.
            if (paddingBoard[y1 + 1][x1] == 0 && paddingBoard[y2 + 1][x2] == 0) {
                temp = top;
                temp.pos[0].first++, temp.pos[1].first++;
                
				if (isVisited(temp.pos, visited) == false) {
					temp.time++;
					st.push(temp);
					visited.push_back(temp.pos); cout << "in:[" << temp.pos[0].first << "," << temp.pos[0].second << "][" << temp.pos[1].first << "," << temp.pos[1].second << "] ";
				}
            }
            // 5. 회전
			// 시계방향 2가지 (1번째 노드 움직이기, 2번째 노드 움직이기)
			if (paddingBoard[y1 - 1][x1 + 1] == 0 && paddingBoard[y1 - 1][x1] == 0) {
				temp = top;
				temp.pos[0].first--, temp.pos[0].second++;
				sort(temp.pos.begin(), temp.pos.end());
				if (isVisited(temp.pos, visited) == false) {
					temp.time++;
					sort(temp.pos.begin(), temp.pos.end());
					st.push(temp);
					visited.push_back(temp.pos); cout << "in:[" << temp.pos[0].first << "," << temp.pos[0].second << "][" << temp.pos[1].first << "," << temp.pos[1].second << "] ";
				}
			}
			if (paddingBoard[y2 + 1][x2 - 1] == 0 && paddingBoard[y2 + 1][x2] == 0) {
				temp = top;
				temp.pos[1].first++, temp.pos[1].second--;
				sort(temp.pos.begin(), temp.pos.end());
				if (isVisited(temp.pos, visited) == false) {
					temp.time++;
					sort(temp.pos.begin(), temp.pos.end());
					st.push(temp);
					visited.push_back(temp.pos); cout << "in:[" << temp.pos[0].first << "," << temp.pos[0].second << "][" << temp.pos[1].first << "," << temp.pos[1].second << "] ";
				}
			}
			// 반시계방향 2가지
			if (paddingBoard[y2 - 1][x2 - 1] == 0 && paddingBoard[y2 - 1][x2] == 0) {
				temp = top;
				temp.pos[1].first--, temp.pos[1].second--;
				sort(temp.pos.begin(), temp.pos.end());
				/*if (top.pos[0].first == 2 && top.pos[0].second == 1 && top.pos[1].first == 2 && top.pos[1].second == 2) {
					cout << endl << "그좌표 " << isVisited(temp.pos, visited) << endl;
				}*/

				if (isVisited(temp.pos, visited) == false) {
					temp.time++;
					sort(temp.pos.begin(), temp.pos.end());
					st.push(temp);
					visited.push_back(temp.pos); cout << "in:[" << temp.pos[0].first << "," << temp.pos[0].second << "][" << temp.pos[1].first << "," << temp.pos[1].second << "] ";
				}
			}
			if (paddingBoard[y1 + 1][x1 + 1] == 0 && paddingBoard[y1 + 1][x1] == 0) {
				temp = top;
				temp.pos[0].first++, temp.pos[0].second++;
				sort(temp.pos.begin(), temp.pos.end());
				if (isVisited(temp.pos, visited) == false) {
					temp.time++;
					sort(temp.pos.begin(), temp.pos.end());
					st.push(temp);
					visited.push_back(temp.pos); cout << "in:[" << temp.pos[0].first << "," << temp.pos[0].second << "][" << temp.pos[1].first << "," << temp.pos[1].second << "] ";
				}
			}
            
        }
        else {
            // 세로 모양.
            // 1.오른쪽으로 이동.
            if (paddingBoard[y1][x1 + 1] == 0 && paddingBoard[y2][x2 + 1] == 0) {
                temp = top;
                temp.pos[0].second++, temp.pos[1].second++;
                
				if (isVisited(temp.pos, visited) == false) {
					temp.time++;
					st.push(temp);
					visited.push_back(temp.pos); cout << "in:[" << temp.pos[0].first << "," << temp.pos[0].second << "][" << temp.pos[1].first << "," << temp.pos[1].second << "] ";
				}
            }
            // 2. 왼쪽으로 이동.
            if (paddingBoard[y1][x1 - 1] == 0 && paddingBoard[y2][x2 - 1] == 0) {
                temp = top;
                temp.pos[0].second--, temp.pos[1].second--;
                
				if (isVisited(temp.pos, visited) == false) {
					temp.time++;
					st.push(temp);
					visited.push_back(temp.pos); cout << "in:[" << temp.pos[0].first << "," << temp.pos[0].second << "][" << temp.pos[1].first << "," << temp.pos[1].second << "] ";
				}
            }
            // 3. 위쪽으로 이동.
            if (paddingBoard[y1 - 1][x1] == 0) {
                temp = top;
                temp.pos[0].first--, temp.pos[1].first--;;
                
				if (isVisited(temp.pos, visited) == false) {
					temp.time++;
					st.push(temp);
					visited.push_back(temp.pos); cout << "in:[" << temp.pos[0].first << "," << temp.pos[0].second << "][" << temp.pos[1].first << "," << temp.pos[1].second << "] ";
				}
            }
            // 4. 아래쪽으로 이동.
            if (paddingBoard[y2 + 1][x2] == 0) {
                temp = top;
                temp.pos[1].first++, temp.pos[0].first++;
                
				if (isVisited(temp.pos, visited) == false) {
					temp.time++;
					st.push(temp);
					visited.push_back(temp.pos); cout << "in:[" << temp.pos[0].first << "," << temp.pos[0].second << "][" << temp.pos[1].first << "," << temp.pos[1].second << "] ";
				}
            }
            // 5. 회전
		    // 시계방향 2가지
			if (paddingBoard[y1 + 1][x1 + 1] == 0 && paddingBoard[y1][x1 + 1] == 0) {
				temp = top;
				temp.pos[0].first++, temp.pos[0].second++;
				sort(temp.pos.begin(), temp.pos.end());
				if (isVisited(temp.pos, visited) == false) {
					temp.time++;
					sort(temp.pos.begin(), temp.pos.end());
					st.push(temp);
					visited.push_back(temp.pos); cout << "in:[" << temp.pos[0].first << "," << temp.pos[0].second << "][" << temp.pos[1].first << "," << temp.pos[1].second << "] ";
				}
			}
			if (paddingBoard[y2 - 1][x2 - 1] == 0 && paddingBoard[y2][x2 - 1] == 0) {
				temp = top;
				temp.pos[1].first--, temp.pos[1].second--;
				sort(temp.pos.begin(), temp.pos.end());
				if (isVisited(temp.pos, visited) == false) {
					temp.time++;
					sort(temp.pos.begin(), temp.pos.end());
					st.push(temp);
					visited.push_back(temp.pos); cout << "in:[" << temp.pos[0].first << "," << temp.pos[0].second << "][" << temp.pos[1].first << "," << temp.pos[1].second << "] ";
				}
			}
			// 반시계방향 2가지
			if (paddingBoard[y1 + 1][x1 - 1] == 0 && paddingBoard[y1][x1 - 1] == 0) {
				temp = top;
				temp.pos[0].first++, temp.pos[0].second--;
				sort(temp.pos.begin(), temp.pos.end());
				if (isVisited(temp.pos, visited) == false) {
					temp.time++;
					sort(temp.pos.begin(), temp.pos.end());
					st.push(temp);
					visited.push_back(temp.pos); cout << "in:[" << temp.pos[0].first << "," << temp.pos[0].second << "][" << temp.pos[1].first << "," << temp.pos[1].second << "] ";
				}
			}
			if (paddingBoard[y2 - 1][x2 + 1] == 0 && paddingBoard[y2][x2 + 1] == 0) {
				temp = top;
				temp.pos[1].first--, temp.pos[1].second++;
				sort(temp.pos.begin(), temp.pos.end());
				if (isVisited(temp.pos, visited) == false) {
					temp.time++;
					sort(temp.pos.begin(), temp.pos.end());
					st.push(temp);
					visited.push_back(temp.pos); cout << "in:[" << temp.pos[0].first << "," << temp.pos[0].second << "][" << temp.pos[1].first << "," << temp.pos[1].second << "] ";
				}
			}

        }
        
    }

    answer = -1;
    
    return answer;
}

struct pos {
	int y[2], x[2];
	int dir[2];
};
int n;
int dy[] = { 0,1,0,-1 };  // -> 0 / 아래 1 / <- 2 / 위 3
int dx[] = { 1,0,-1,0 };
bool chk[101][101][4];

bool range(int y1, int x1, int y2, int x2, int dir1, int dir2, vector<vector<int>>& mp) {
	return !(y1 < 0 || y1 >= n || x1 < 0 || x1 >= n || y2 < 0 || y2 >= n || x2 < 0 || x2 >= n || mp[y1][x1] || mp[y2][x2]);
}

int solution2(vector<vector<int>> mp) {
	n = mp.size();
	queue<pos> q;
	// -> 0 / 아래 1 / <- 2 / 위 3
	chk[0][0][0] = chk[0][1][2] = true;
	q.push({ 0,0,0,1,0,2 });
	int timer = 0;
	int num = 0;
	while (!q.empty()) {
		int l = q.size();
		while (l--) {
			cout << q.size() << " ";
			pos f = q.front();
			q.pop();
			cout << "(" << f.y[0] + 1 << "," << f.x[0] + 1 << ")(" << f.y[1] + 1 << "," << f.x[1] + 1 << ") ";
			if ((f.y[0] == n - 1 && f.x[0] == n - 1) || (f.y[1] == n - 1 && f.x[1] == n - 1)) return timer;

			for (int dir = 0; dir < 4; dir++) {
				int ny1 = f.y[0] + dy[dir], nx1 = f.x[0] + dx[dir];
				int ny2 = f.y[1] + dy[dir], nx2 = f.x[1] + dx[dir];
				int dir1 = f.dir[0], dir2 = f.dir[1];

				if (!range(ny1, nx1, ny2, nx2, dir1, dir2, mp) || chk[ny1][nx1][dir1] || chk[ny2][nx2][dir2]) continue;
				chk[ny1][nx1][dir1] = chk[ny2][nx2][dir2] = true;
				q.push({ ny1, ny2, nx1, nx2, dir1, dir2 });
				cout << "in:[" << ny1 + 1 << "," << nx1 + 1 << "][" << ny2 + 1 << "," << nx2 + 1 << "] ";
			}

			for (int i = -1; i <= 1; i++) {
				if (i == 0) continue;
				for (int j = 0; j < 2; j++) {
					int y = f.y[j], x = f.x[j];

					int dir = (f.dir[j] + i + 4) % 4;
					int prev_dir = (dir - i + 4) % 4;
					int oppo_dir = (dir + 2) % 4;

					int ny2 = y + dy[dir], nx2 = x + dx[dir];
					int ny3 = y + dy[dir] + dy[prev_dir], nx3 = x + dx[dir] + dx[prev_dir];

					if (!range(ny2, nx2, ny3, nx3, dir, oppo_dir, mp) || chk[y][x][dir] || chk[ny2][nx2][oppo_dir]) continue;
					chk[y][x][dir] = chk[ny2][nx2][oppo_dir] = true;
					q.push({ y, ny2, x, nx2, dir, oppo_dir });

					cout << "in:[" << y + 1 << "," << x + 1 << "][" << ny2 + 1 << "," << nx2 + 1 << "] ";
				}
			}
		}
		timer += 1;
	}
	return -1;
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
    
    cout << solution(v) << endl << endl << endl;

	cout << solution2(v) << endl;

    
}