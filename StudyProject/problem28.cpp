#include "problem28.h"

namespace KakaoWinterIntern2019 {

	namespace problem28 {

		bool comp(pair<int, int> lhs, pair<int, int> rhs) {
			if (lhs.second >= rhs.second)
				return true;
			return false;
		}

		vector<int> solution(string s) {

			// 원소의 개수를 map을 사용하여 저장.
			// 가장 많은 개수 순서대로 원소가 나열된 것이 답.

			vector<int> answer;
			map<int, int> m;
			queue<char> q;

			for (int i = 0; i < s.length(); i++) {

				if (48 <= s[i] && s[i] <= 57) {
					q.push(s[i]);
				}
				else {

					if (q.empty() == false) {
						string str = "";
						while (q.empty() == false) {
							str += q.front();
							q.pop();
						}

						m[stoi(str)]++;
					}
				}
			}

			// map을 sort by value 하기 위해서 사용
			vector<pair<int, int>> sortingV;

			for (auto p : m)
				sortingV.push_back(p);

			// 개수가 많은 원소 순서대로 정렬
			sort(sortingV.begin(), sortingV.end(), comp);

			for (auto p : sortingV)
				answer.push_back(p.first);

			return answer;
		}

		void execute() {

			string str = "{{2},{2,1},{2,1,3},{2,1,3,4}}";

			solution(str);
		}
	}
}