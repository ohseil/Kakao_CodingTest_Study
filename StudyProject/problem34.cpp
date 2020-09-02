#include "problem34.h"

namespace KakaoIntern2020 {

	namespace problem34 {

		vector<int> solution(vector<string> gems) {

			vector<int> answer;

			// gem을 처음부터 쭉 순회하는데,
			// map을 사용해서 각 보석의 개수를 저장하면서 간다.
			// 처음 모든 보석이 포함한 범위를 찾았다면
			// 범위를 고정한 상태에서 왼쪽 index를 오른쪽으로 옮기면서
			// 모든 보석이 포함한 범위인지 확인한다.
			// 오른쪽으로 옮기다 조건이 맞지 않으면 그만하고
			// 가장 최근에 만족한 범위가 처음 구한 범위이다.

			// 범위를 한번 구했다면,
			// 이 다음부터는 왼쪽index와 오른쪽index 둘다 옮기면서 만족하는 범위인지 확인한다.
			// 또 범위를 찾았다면 왼쪽 index만 움직여 최소범위를 찾고
			// 이전에 만족한 범위보다 작다면 찾아낸 범위가 정답에 가깝게 된다.

			// 위의 방식대로 순회를 한다.

			int sIndex = 0, fIndex = 0; // 현재 확인하고 있는 범위
			int rsIndex = 0, rfIndex = 0; // 현재 모든 보석을 포함한 가장 짧은 범위

			int gemSize = 0, gemsLength = gems.size();

			bool isFirst = true;

			map<string, int> gemMap;

			// 서로 다른 잼의 개수 확인.
			for (string gem : gems)
				gemMap[gem] = 1;

			gemSize = gemMap.size();

			gemMap.clear();

			for (int i = 0; i < gemsLength; i++) {

				if (isFirst == true) {
					// 아직 모든 보석을 포함한 구간 찾기 전
					gemMap[gems[i]]++;
					fIndex = i;
					if (gemMap.size() == gemSize) {
						// 모든 보석을 포함한 구간을 찾은 경우
						// 왼쪽 index를 옮기며 더 좁은 구간을 찾아본다.
						rsIndex = sIndex, rfIndex = fIndex;
						for (int j = sIndex; j <= fIndex; j++) {
							if (gemMap[gems[j]] - 1 == 0) {
								break;
							}
							else {
								gemMap[gems[j]]--;
								rsIndex = sIndex = j + 1;
							}
						}

						isFirst = false;
					}
				}
				else {
					// 한번 이상 모든 보석을 포함한 구간 찾은 후
					// 범위를 고정한 상태에서 왼쪽,오른쪽 index를 모두 옮기며 검색.
					gemMap[gems[sIndex]]--;
					gemMap[gems[i]]++;
					if (gemMap[gems[sIndex]] == 0) {
						gemMap.erase(gems[sIndex]);

					}

					sIndex++;
					fIndex = i;

					// 또다시 조건에 맞는 구간을 찾았다면
					// 또다시 더 좁은 구간을 찾는다.
					if (gemMap.size() == gemSize) {

						for (int j = sIndex; j <= fIndex; j++) {
							if (gemMap[gems[j]] - 1 == 0) {
								break;
							}
							else {
								gemMap[gems[j]]--;
								rsIndex = sIndex = j + 1;
								rfIndex = fIndex;
							}
						}
					}
				}
			}

			answer.push_back(rsIndex + 1);
			answer.push_back(rfIndex + 1);

			return answer;
		}

		void execute() {

		}
	}
}