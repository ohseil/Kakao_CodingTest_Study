#include "problem30.h"

namespace KakaoWinterIntern2019 {

	namespace problem30 {

		vector<long long> solution(long long k, vector<long long> room_number) {

			// map을 이용해서 각 방이 다음 비어있는 방을 가리키는 구조로 만든다.
			// queue는 다음 방을 찾았을 때, 이전에 찾기위해 거쳐왔던 방들을
			// 저장해 두었다가 빈방의 정보를 갱신해주기 위해 사용.

			vector<long long> answer;

			map<long long, long long> m;
			queue<long long> q;

			for (auto num : room_number) {

				while (m[num] != 0) {
					q.push(num);
					num = m[num];
				}

				while (q.empty() == false) {
					long long data = q.front();
					q.pop();
					m[data] = num + 1;
				}

				m[num] = num + 1;
				answer.push_back(num);
			}

			return answer;
		}

		void execute() {

		}
	}
}