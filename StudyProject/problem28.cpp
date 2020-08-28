#include "problem28.h"

namespace KakaoWinterIntern2019 {

	namespace problem28 {

		bool comp(pair<int, int> lhs, pair<int, int> rhs) {
			if (lhs.second >= rhs.second)
				return true;
			return false;
		}

		vector<int> solution(string s) {

			// ������ ������ map�� ����Ͽ� ����.
			// ���� ���� ���� ������� ���Ұ� ������ ���� ��.

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

			// map�� sort by value �ϱ� ���ؼ� ���
			vector<pair<int, int>> sortingV;

			for (auto p : m)
				sortingV.push_back(p);

			// ������ ���� ���� ������� ����
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