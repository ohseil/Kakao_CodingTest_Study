#include "problem8.h"

namespace KakaoBlind2019 {

	namespace problem8 {

		vector<string> solution(vector<string> record) {

			vector<string> answer;
			map<string, string> nickMap;
			map<char, int> idIndexMap;
			vector<pair<int, string>> tempV;


			// �־����� record �� -> 100000 (10����)

			idIndexMap['E'] = 6, idIndexMap['L'] = 6, idIndexMap['C'] = 7;

			for (string r : record) {

				// 1. Enter
				// �Է� str -> Enter id nickname

				// 2. Leave
				// �Է� str -> Leave id

				// 3. Change
				// �Է� str -> Change id nickname

				// nickname ����Ǵ� ��� -> Enter or Change.

				string id = "";
				string nickname;

				for (int i = idIndexMap[r[0]]; i < r.length(); i++) {

					if (r[i] != ' ') {
						id += r[i];
					}
					else {
						nickname = r.substr(i + 1);
						break;
					}
				}

				if (r[0] == 'E') {
					tempV.push_back(make_pair<int, string>((int)0, (string)id));
					nickMap[id] = nickname;
				}
				else if (r[0] == 'L') {
					tempV.push_back(make_pair<int, string>((int)1, (string)id));
				}
				else if (r[0] == 'C') {
					nickMap[id] = nickname;
				}
			}

			for (pair<int, string> p : tempV) {

				string result = "";

				int code = p.first; // Enter or Leave
				string id = p.second;

				if (code == 0) {
					// Enter
					result = nickMap[id] + "���� ���Խ��ϴ�.";
				}
				else {
					// Leave
					result = nickMap[id] + "���� �������ϴ�.";
				}

				answer.push_back(result);
			}

			return answer;
		}

		void execute() {


			vector<string> v;

			v.push_back("Enter uid1234 Muzi");
			v.push_back("Enter uid4567 Prodo");
			v.push_back("Leave uid1234");
			v.push_back("Enter uid1234 Prodo");
			v.push_back("Change uid4567 Ryan");

			solution(v);
			cout << endl;
		}

	}

}