#include "problem24.h"

int solution(vector<string> words) {

	int answer = 0;
	
	map<string, int> m;

	for (string str : words) {

		string temp = "";

		for (char ch : str) {
			temp += ch;
			m[temp]++;
		}
	}

	for (string word : words) {

		string temp = "";

		for (int i = 0; i < word.length(); i++) {
			temp += word[i];
			if (m[temp] == 1 || i == word.length() - 1) {
				answer += temp.length();
				break;
			}
		}
	}

	return answer;
}

namespace KakaoBlind2018 {

	namespace problem24 {

		void execute() {

			vector<string> v;
			v.push_back("go");

			v.push_back("gone");
			v.push_back("guild");

			cout << solution(v) << endl;
		}
	}
}