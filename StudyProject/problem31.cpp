#include "problem31.h"

namespace KakaoWinterIntern2019 {

	namespace problem31 {

		// 입력한 친구들이 징검다리를 모두 건넜을 경우,
		// 가장 긴 연속된 0보다 작은 숫자들의 길이 반환.
		int zeroNum(vector<int> stones, int friends) {

			int num = 0;
			int biggest = 0;

			for (int i = 0; i < stones.size(); i++) {
				if (stones[i] - friends <= 0) {
					num++;
				}
				else
					num = 0;

				if (biggest < num)
					biggest = num;
			}

			return biggest;
		}

		int solution(vector<int> stones, int k) {

			// 이진탐색 사용.

			int answer = 0;

			int left = 1, right = 0, mid = 0;

			for (int stone : stones)
				if (right < stone)
					right = stone;

			while (left <= right) {

				mid = (left + right) / 2;

				if (zeroNum(stones, mid) >= k) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}

			answer = left;

			return answer;
		}

		void execute() {

			vector<int> stones(10, 0);
			int k = 3;

			stones[0] = 2;
			stones[1] = 4;
			stones[2] = 5;
			stones[3] = 3;
			stones[4] = 2;
			stones[5] = 1;
			stones[6] = 4;
			stones[7] = 2;
			stones[8] = 5;
			stones[9] = 1;

			cout << solution(stones, k);

		}
	}
}