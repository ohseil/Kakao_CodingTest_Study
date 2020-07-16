#include "problem8.h"

namespace KakaoBlind2019 {

	namespace problem8 {

		vector<string> solution(vector<string> record) {

			vector<string> answer;
			map<string, string> nickMap;
			map<char, int> idIndexMap;
			vector<pair<int, string>> tempV;


			// 주어지는 record 수 -> 100000 (10만개)

			idIndexMap['E'] = 6, idIndexMap['L'] = 6, idIndexMap['C'] = 7;

			for (string r : record) {

				// 1. Enter
				// 입력 str -> Enter id nickname

				// 2. Leave
				// 입력 str -> Leave id

				// 3. Change
				// 입력 str -> Change id nickname

				// nickname 변경되는 경우 -> Enter or Change.

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
					result = nickMap[id] + "님이 들어왔습니다.";
				}
				else {
					// Leave
					result = nickMap[id] + "님이 나갔습니다.";
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