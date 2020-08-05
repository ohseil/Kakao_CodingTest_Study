#include "problem23.h"

namespace KakaoBlind2018 {

	namespace problem23 {

		// ���� �˻� �Լ�
		int findMap(vector<string> strMap, string str) {
			for (int i = 0; i < strMap.size(); i++)
				if (strMap[i] == str)
					return i;
			return -1;
		}

		vector<int> solution(string msg) {

			// ���ڿ� ���� �˰��� LZW ����

			vector<int> answer;

			vector<string> strMap;

			// ���� 1 ���ڿ� "A" ~ "Z" ���� ����.
			for (int i = 65; i <= 90; i++) {
				string temp(1, (char)i);
				strMap.push_back(temp);
			}

			int foundNum = 0;

			for (int i = 0; i < msg.length(); i += foundNum) {

				string check = "";
				foundNum = 0;

				for (int j = i; j < msg.length(); j++) {

					check += msg[j];
					int findIndex = findMap(strMap, check);
					if (findIndex != -1) {
						// ������ ��ϵǾ��ִٸ�
						foundNum++;

						// ������ ���ڰ� ���Ե� ���ڿ��̶��
						if (j == msg.length() - 1) {
							answer.push_back(findIndex + 1);
							foundNum = msg.length();
							break;
						}
					}
					else {
						// ��ϵǾ����� �ʴٸ� ���� ���ڿ� index ���, ���� ���ڿ� ���� ���.
						answer.push_back(findMap(strMap, check.substr(0, check.length() - 1)) + 1);
						strMap.push_back(check);
						break;
					}
				}
			}


			return answer;
		}

		void execute() {

			string str = "TOBEORNOTTOBEORTOBEORNOT";

			vector<int> v = solution(str);

			for (auto a : v)
				cout << a << " ";
			cout << endl;

		}
	}
}