#include "problem5.h"

namespace KakaoBlind2020 {

	namespace problem5 {

		int solution(int n, vector<int> weak, vector<int> dist) {

			int answer = 0;

			vector<int> tempDist;

			// 내림차순으로 정렬된 임시 벡터 생성
			for (int i = dist.size() - 1; i >= 0; i--)
				tempDist.push_back(dist[i]);

			// 가장 길게 확인할 수 있는 순서대로 친구들이 정렬됨.
			// 순서대로 1명, 2명, 3명 ~ n명까지 뽑아내서 permutation 돌려서 모든 경우 검사.
			for (int i = 0; i < tempDist.size(); i++) {

				vector<int> checkSample;

				// 긴거리 갈 수 있는 순으로 친구 i + 1 명 뽑기.
				for (int j = 0; j <= i; j++)
					checkSample.push_back(tempDist[j]);

				// permutation 쓰기 위해서 오름차순으로 정렬.
				sort(checkSample.begin(), checkSample.end());

				// permutation 돌려서 모든 경우 확인.
				do {
					// 모든 취약지점을 확인할 수 있는지 확인하는 부분.
					for (int startPoint = 0; startPoint < weak.size(); startPoint++) {

						int curIndex = startPoint; // 현재 검사필요한 취약지점 인덱스

						int weakNum = 0; // 현재 확인한 취약지점 개수.

						for (auto friendDist : checkSample) {

							int curDist = friendDist;

							for (int wk = curIndex; wk < weak.size(); wk = (wk + 1) % weak.size()) {

								// 현재취약지점index까지 왔다는 건 이 지점 하나는 검사하고 시작한다는 의미.
								weakNum++;

								// 취약점 모두 검사완료.
								if (weakNum == weak.size()) {
									answer = checkSample.size(); // sample로 뽑은 친구들의 수가 정답.
									return answer;
								}

								// 현재 취약지점으로 투입했을 때 다음 취약지점까지의 거리
								int weakDist = 0;

								if (wk == weak.size() - 1)
									weakDist = (n - weak[wk]) + weak[0];
								else
									weakDist = weak[wk + 1] - weak[wk];

								// 다음 취약지점까지의 거리 구하고 다음 것까지 검사할 수 있는지 확인
								if (weakDist > curDist) {
									// 다음 취약지점 검사 불가.
									curIndex = (wk + 1) % weak.size();
									break;
								}
								else {
									// 다음 취약지점까지 검사 가능.
									curDist -= weakDist;
								}
							}


						}
					}


				} while (next_permutation(checkSample.begin(), checkSample.end()));

			}

			// routine 안에서 return 되지 않았다면 모든 경우의 수에서
			// 모든 취약지점을 확인하는 경우가 없다는 의미이므로 -1 출력.
			answer = -1;

			return answer;
		}

		void execute() {

			int n = 12;
			vector<int> weak, dist;

			weak.push_back(1);
			weak.push_back(5);
			weak.push_back(6);
			//weak.push_back(9);
			weak.push_back(10);

			dist.push_back(1);
			dist.push_back(2);
			dist.push_back(3);
			dist.push_back(4);

			cout << solution(n, weak, dist) << endl;

		}

	}

}