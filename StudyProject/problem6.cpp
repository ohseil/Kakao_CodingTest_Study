#include "problem6.h"

struct machine {
    vector<pair<int, int>> pos;
    int time = 0;

	machine() {}

	machine(int x1, int y1, int x2, int y2) {
		pos.push_back(make_pair<int, int>((int)x1, (int)y1));
		pos.push_back(make_pair<int, int>((int)x2, (int)y2));
	}
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

	int paddingBoard[102][102] = { {}, };
	int mx[] = { 1,0,-1,0 };
	int my[] = { 0,1,0,-1 };
	int rotate[] = { 1,-1 };

	vector<vector<pair<int, int>>> visited; // 방문기록   
	queue<machine> q; // BFS queue.

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

    // 시작점 설정.
    machine start(1,1,1,2);
	visited.push_back(start.pos);
    q.push(start);

    // BFS
    while (!q.empty()) {

		vector<machine> canMove;
		machine temp;

        machine top = q.front();
        q.pop();
	
		// n, n 위치에 도착.
        if ((top.pos[0].first == n && top.pos[0].second == n)
            || (top.pos[1].first == n && top.pos[1].second == n)) {
            answer = top.time;
            return answer;
        }

		// 이동
		for (int i = 0; i < 4; i++) {
			if (paddingBoard[top.pos[0].first + my[i]][top.pos[0].second + mx[i]] == 0
				&& paddingBoard[top.pos[1].first + my[i]][top.pos[1].second + mx[i]] == 0) {
				temp = top;
				temp.pos[0].first += my[i], temp.pos[0].second += mx[i];
				temp.pos[1].first += my[i], temp.pos[1].second += mx[i];
				canMove.push_back(temp);
			}
		}

		// 회전
		if (top.pos[0].first == top.pos[1].first) {
			// 가로 모양
			for (int r : rotate) {
				if (paddingBoard[top.pos[0].first + r][top.pos[0].second] == 0
					&& paddingBoard[top.pos[1].first + r][top.pos[1].second] == 0) {
					temp = top;
					temp.pos[1].first = temp.pos[0].first + r;
					temp.pos[1].second = temp.pos[0].second;
					sort(temp.pos.begin(), temp.pos.end());
					canMove.push_back(temp);

					temp = top;
					temp.pos[0].first = temp.pos[1].first + r;
					temp.pos[0].second = temp.pos[1].second;
					sort(temp.pos.begin(), temp.pos.end());
					canMove.push_back(temp);
				}
			}
		}
		else {
			// 세로 모양
			for (int r : rotate) {
				if (paddingBoard[top.pos[0].first][top.pos[0].second + r] == 0
					&& paddingBoard[top.pos[1].first][top.pos[1].second + r] == 0) {
					temp = top;
					temp.pos[1].first = temp.pos[0].first;
					temp.pos[1].second = temp.pos[0].second + r;
					sort(temp.pos.begin(), temp.pos.end());
					canMove.push_back(temp);

					temp = top;
					temp.pos[0].first = temp.pos[1].first;
					temp.pos[0].second = temp.pos[1].second + r;
					sort(temp.pos.begin(), temp.pos.end());
					canMove.push_back(temp);
				}
			}
		}

		for (machine move : canMove) {
			if (isVisited(move.pos, visited) == false) {
				visited.push_back(move.pos);
				move.time++;
				q.push(move);
			}
		}
        
    }

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