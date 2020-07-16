#include "problem2.h"

namespace KakaoBlind2020 {

	namespace problem2 {

		string process1(string str);

		// �ùٸ� ���ڿ����� Ȯ���ϴ� �Լ�
		bool isRight(string str) {

			stack<char> st;

			for (char ch : str) {
				if (ch == '(') {
					st.push(ch);
				}
				else {
					if (!st.empty())
						st.pop();
				}
			}

			if (st.empty() == true)
				return true;
			else
				return false;
		}

		string process2(string u, string v) {
			string subU;

			for (int i = 1; i < u.length() - 1; i++) {
				if (u[i] == '(')
					subU += ')';
				else
					subU += '(';
			}

			return "(" + process1(v) + ")" + subU;
		}

		string process1(string str) {

			if (str == "")
				return "";

			string u, v;

			int lNum = 0, rNum = 0;

			for (int i = 0; i < str.length(); i++) {
				if (str[i] == '(')
					lNum++;
				else
					rNum++;

				if (lNum == rNum) {
					u = str.substr(0, i + 1);
					for (int j = i + 1; j < str.length(); j++)
						v += str[j];
					break;
				}
			}

			if (isRight(u) == true) {
				return u + process1(v);
			}
			else {
				return process2(u, v);
			}
		}

		string solution(string str) {
			return process1(str);
		}

		void execute() {
			cout << solution("(()())()") << endl;
		}

	}

}