#include "problem27.h"

namespace KakaoWinterIntern2019 {

	namespace problem27 {

		int solution(vector<vector<int>> board, vector<int> moves) {

			// ���� ��ȣ : 1 ~ 100
			// ��ĭ : 0

			// board���� �� ������ �׿��ִ� ���̸� Ȯ���ϰ� ����.
			// �� move�� Ȯ���ϰ� stack�� �̿��ؼ� ������ �����鼭 ��Ʈ����
			// ���� ������ �ִ� ���� ���̸� �����Ѵ�.

			int answer = 0;

			vector<int> heights;
			stack<int> bucket;
			int n = board.size();

			for (int i = 0; i < n; i++) {

				// �ʱ�ȭ
				heights.push_back(n);

				for (int j = 0; j < n; j++) {
					if (board[j][i] != 0) {
						// ���� ���̿� ������ �ִٸ� �������� ����.
						heights[i] = j;
						break;
					}
				}
			}

			// ������ ���̵����͸� �̿��ؼ� �� move�� ����.

			for (int move : moves) {

				// ������ ���� �ٱ��Ͽ� �����鼭 �Ͷ߸� Ȯ���ϰ�,
				// ������ ���� ��ġ�� ���� ����.

				int index = move - 1;

				if (heights[index] < n) {

					int dollNum = board[heights[index]][index]; // ���� ������ȣ

					if (bucket.empty() == true) {
						// ����ִٸ� �ٱ��Ͽ� ���.
						bucket.push(dollNum);
					}
					else {

						if (bucket.top() == dollNum) {
							// ���ӵ� �����̶�� �Ͷ߸�
							answer += 2;
							bucket.pop();
						}
						else {
							// ���ӵ� ������ �ƴ϶�� �ٱ��Ͽ� ���.
							bucket.push(dollNum);
						}
					}

					heights[index]++; // ���� ����.
				}
			}

			return answer;
		}

		void execute() {


		}
	}
}