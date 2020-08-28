#include "problem29.h"

namespace KakaoWinterIntern2019 {

	namespace problem29 {

		// banned_id�� user_id�� ��ġ�ϴ��� Ȯ���ϴ� �Լ�
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

			// �� banned_id���� ��ġ�ϴ� user_id�� ������.
			// �������� �����͸� �����Ͽ� ��� ��� �����.
			// �̶� ���� user_id�� ���Ե� �� �����Ƿ� check �ʿ�.

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

			// ��� ��� ����
			queue<map<string, int>> q;

			if (ban_list.empty() == false) {
				for (auto a : ban_list[0]) {
					map<string, int> temp;
					temp[a]++;
					q.push(temp);
				}
			}

			// ���ο� �ߺ� ���̵� ���� ����� ���� ����.
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

				// Ȯ���ߴ� ��ϰ� �ߺ��� ���ٸ� ��� �߰�.
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