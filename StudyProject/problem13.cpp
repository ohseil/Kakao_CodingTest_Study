#include "problem13.h"

namespace KakaoBlind2019 {

	namespace problem13 {

		int solution(string word, vector<string> pages) {

			int answer = 0;

			map<string, map<string, double>> scoreMap; // �������� url�� key�� ������ ������ ���� map.
			vector<string> urls; // page�� index�� url�� mapping �س��� vector.

			for (string page : pages) {

				// ���ڿ� �˻��ϸ鼭 ���� �� ������
				// 1. word�� ��ġ�ϴ� �ܾ� �� (�⺻����)
				// 2. �������� url
				// 3. <a herf�� �� (�ܺθ�ũ ��)
				// 4. <a herf�� url (��ũ ������ �ش� �������鿡�� ������Ʈ �ϱ� ����.)

				string url;

				int strLength = page.length();
				/*for (int i = 0; i < strLength; i++) {

					if ()
				}*/


			}

			return answer;
		}

		void execute() {

			string str = "<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>";

			int urlStartIndex = str.substr(str.find("<meta property=")).find("https://");
			int urlEndIndex = str.substr(str.substr(str.find("<meta property=")).find("https://")).find("\"");
			string s = str.substr(str.find("<meta property=")).substr(urlStartIndex, urlEndIndex);
			cout << urlStartIndex << endl << urlEndIndex << endl << s << endl;

			string str2 = "https://a.com\"dfdf";

			cout << endl << str2.find("\"") << endl;
		}
	}
}