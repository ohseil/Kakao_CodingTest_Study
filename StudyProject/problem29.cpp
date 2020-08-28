#include "problem29.h"

namespace KakaoWinterIntern2019 {

	namespace problem29 {

		// banned_id와 user_id가 일치하는지 확인하는 함수
		bool isBan(string userId, string banId) {

			if (userId.length() != banId.length())
				return false;

			int sameCount = 0;

			for (int i = 0; i < userId.length(); i++) {
				if (banId[i] == '*' || banId[i] == userId[i])
					sameCount++;
			}

			if (sameCount != userId.length())
				return false;

			return true;
		}

		int solution(vector<string> user_id, vector<string> banned_id) {

			// 각 banned_id마다 일치하는 user_id를 리스팅.
			// 리스팅한 데이터를 조합하여 모든 목록 만들기.
			// 이때 같은 user_id가 포함될 수 있으므로 check 필요.

			int answer = 0;

			vector<vector<string>> ban_list;

			for (string banId : banned_id) {
				vector<string> id_list;
				for (string userId : user_id) {
					if (isBan(userId, banId) == true)
						id_list.push_back(userId);
				}
				ban_list.push_back(id_list);
			}

			// 모든 목록 생성
			queue<map<string, int>> q;

			if (ban_list.empty() == false) {
				for (auto a : ban_list[0]) {
					map<string, int> temp;
					temp[a]++;
					q.push(temp);
				}
			}

			// 내부에 중복 아이디가 없는 목록의 경우들 생성.
			for (int i = 1; i < ban_list.size(); i++) {

				int qSize = q.size();

				for (int qs = 0; qs < qSize; qs++) {
					for (auto a : ban_list[i]) {
						map<string, int> data = q.front();
						data[a]++;
						if (data[a] == 1)
							q.push(data);
					}
					q.pop();
				}
			}

			map<map<string, int>, int> dupCheckM;

			while (q.empty() == false) {

				map<string, int> list = q.front();

				// 확인했던 목록과 중복이 없다면 목록 추가.
				dupCheckM[list]++;
				if (dupCheckM[list] == 1)
					answer++;

				q.pop();
			}

			return answer;
		}

		void execute() {

			vector<string> user_id, ban_id;

			user_id.push_back("frodo");
			user_id.push_back("fradi");
			user_id.push_back("crodo");
			user_id.push_back("abc123");
			user_id.push_back("frodoc");
			ban_id.push_back("*rodo");
			ban_id.push_back("*rodo");
			ban_id.push_back("******");

			cout << solution(user_id, ban_id) << endl;
		}
	}
}