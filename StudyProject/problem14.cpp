#include "problem14.h"

bool checkBound(int index, int size) { return (0 <= index && index < size); }

vector<vector<pair<int,int>>> checkBlock(int row, int col, int bNum, vector<vector<int>> board, int size) {

	// 되는 블럭의 모양을 확인해서
	// 채워야 하는 블럭 두개를 반환.

	vector<vector<pair<int, int>>> result;
	int minR, maxR, minC, maxC;

	if (checkBound(row - 1, size) == false)
		minR = row;
	else if (checkBound(row - 2, size) == false)
		minR = row - 1;
	else
		minR = row - 2;

	if (checkBound(row + 1, size) == false)
		maxR = row;
	else if (checkBound(row + 2, size) == false)
		maxR = row + 1;
	else
		maxR = row + 2;

	minC = col;

	if (checkBound(col + 1, size) == false)
		maxC = col;
	else if (checkBound(col + 1, size) == false)
		maxC = col + 1;
	else
		maxC = col + 2;

	vector<pair<int, int>> block;

	for (int r = minR; r <= maxR; r++) {
		for (int c = minC; c <= maxC; c++) {
			if (board[r][c] == bNum)
				block.push_back(make_pair<int, int>((int)r, (int)c));
		}
	}

	int minx = block[0].first, miny = block[0].second, maxx = block[0].first, maxy = block[0].second;

	for (auto a : block) {
		if (minx > a.first)
			minx = a.first;
		if (miny > a.second)
			miny = a.second;
		if (maxx < a.first)
			maxx = a.first;
		if (maxy < a.second)
			maxy = a.second;
	}

	vector<pair<int, int>> nonBlock;

	for (int x = minx; x <= maxx; x++)
		for (int y = miny; y <= maxy; y++)
			if (board[x][y] != bNum)
				nonBlock.push_back(make_pair<int, int>((int)x, (int)y));

	result.push_back(block);
	result.push_back(nonBlock);

	return result;
}

int solution(vector<vector<int>> board) {
	
	int answer = 0;
	int size = board.size();

	vector<int> erased;
	
	for (int row = 0; row < size; row++) {

		for (int col = 0; col < size; col++) {

			if (board[row][col] != 0) {
				// 블럭조각 존재
				int bNum = board[row][col]; // block 번호

				if (checkBound(col + 1, size) && board[row][col + 1] < size && board[row][col + 1] == bNum) {
					// 안되는 블럭

				}
				else {
					if ((checkBound(col - 1, size) && board[row][col - 1] >= 0 && board[row][col - 1] == bNum)
						&& !(checkBound(col + 1, size) && board[row][col + 1] < size && board[row][col + 1] == bNum)) {
						// 안되는 블럭
					}
					else if (!(checkBound(col - 1, size) && board[row][col - 1] >= 0 && board[row][col - 1] == bNum)
						&& (checkBound(col + 1, size) && board[row][col + 1] < size && board[row][col + 1] == bNum)) {
						// 안되는 블럭

					}
					else {
						// 되는 블럭
						// 채워야 하는 열이 비활성화된 열인지 확인.

						vector<vector<pair<int, int>>> checkResult = checkBlock(row, col, bNum, board, size);

						bool isErase = true;

						for (auto nonblock : checkResult[1]) {
							int nbRow = nonblock.first;
							int nbCol = nonblock.second;

							for (int r = 0; r <= nbRow; r++) {
								if (board[r][nbCol] != 0) {
									isErase = false;
									break;
								}
							}
						}

						if (isErase == true) {
							// 블럭 지우고 지워진 블럭번호 기록.
							for (auto block : checkResult[0]) {
								int bRow = block.first;
								int bCol = block.second;
								board[bRow][bCol] = 0;
								erased.push_back(bNum);
							}
						}

					}
				}

			}

			for (auto a : board) {
				for (auto aa : a)
					cout << aa << " ";
				cout << endl;
			}
		}
	}
	
	answer = erased.size();

	return answer;
}

namespace KakaoBlind2019 {

	namespace problem14 {

		void execute() {

			vector<vector<int>> board;
			vector<int> b;
			b.push_back(0); b.push_back(0); b.push_back(0); b.push_back(0); b.push_back(0);
			b.push_back(0); b.push_back(0); b.push_back(0); b.push_back(0); b.push_back(0);
			board.push_back(b);
			b[0] = 0; b[1] = 0; b[2] = 0; b[3] = 0; b[4] = 0; b[5] = 0; b[6] = 0; b[7] = 0; b[8] = 0; b[9] = 0;
			board.push_back(b);
			b[0] = 0; b[1] = 0; b[2] = 0; b[3] = 0; b[4] = 0; b[5] = 0; b[6] = 0; b[7] = 0; b[8] = 0; b[9] = 0;
			board.push_back(b);
			b[0] = 0; b[1] = 0; b[2] = 0; b[3] = 0; b[4] = 0; b[5] = 0; b[6] = 0; b[7] = 0; b[8] = 0; b[9] = 0;
			board.push_back(b);
			b[0] = 0; b[1] = 0; b[2] = 0; b[3] = 0; b[4] = 0; b[5] = 0; b[6] = 4; b[7] = 0; b[8] = 0; b[9] = 0;
			board.push_back(b);
			b[0] = 0; b[1] = 0; b[2] = 0; b[3] = 0; b[4] = 0; b[5] = 4; b[6] = 4; b[7] = 0; b[8] = 0; b[9] = 0;
			board.push_back(b);
			b[0] = 0; b[1] = 0; b[2] = 0; b[3] = 0; b[4] = 3; b[5] = 0; b[6] = 4; b[7] = 0; b[8] = 0; b[9] = 0;
			board.push_back(b);
			b[0] = 0; b[1] = 0; b[2] = 0; b[3] = 2; b[4] = 3; b[5] = 0; b[6] = 0; b[7] = 0; b[8] = 5; b[9] = 5;
			board.push_back(b);
			b[0] = 1; b[1] = 2; b[2] = 2; b[3] = 2; b[4] = 3; b[5] = 3; b[6] = 0; b[7] = 0; b[8] = 0; b[9] = 5;
			board.push_back(b);
			b[0] = 1; b[1] = 1; b[2] = 1; b[3] = 0; b[4] = 0; b[5] = 0; b[6] = 0; b[7] = 0; b[8] = 0; b[9] = 5;
			board.push_back(b);

			cout << solution(board) << endl;

		}
	}
}