#include "problem11.h"

int solution(vector<int> food_times, long long k) {

	// food_time : 각 음식 먹는데 걸리는 시간.
	// k : 정전 날때까지 걸리는 시간.

	int answer = 0;

	int food_size = food_times.size();
	long long darkTime = k;

	while ((darkTime / food_size) != 0) {

		int canTime = darkTime / food_size;

		long long nextTotalTime = darkTime % food_size;
		int nextSize = 0;

		for (int i = 0; i < food_times.size(); i++) {
			if (food_times[i] != 0) {
				if (food_times[i] <= canTime) {
					nextTotalTime += (canTime - food_times[i]);
					food_times[i] = 0;
				}
				else {
					food_times[i] -= canTime;
					nextSize++;
				}
			}
		}

		food_size = nextSize;
		darkTime = nextTotalTime;

		if (food_size == 0)
			return -1;
	}

	for (int i = 0; i < food_times.size(); i++) {

		if (food_times[i] != 0) {
			// 남아있는 음식
			if (darkTime == 0) {
				answer = i + 1;
				break;
			}

			darkTime--;
		}
	}


	return answer;
}

void KakaoBlind2019::problem11::execute() {

	vector<int> v;
	int k = 5;

	v.push_back(3);
	v.push_back(1);
	v.push_back(2);

	cout << solution(v, k) << endl;

}