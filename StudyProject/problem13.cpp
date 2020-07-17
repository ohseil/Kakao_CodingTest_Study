#include "problem13.h"

namespace KakaoBlind2019 {

	namespace problem13 {

		int solution(string word, vector<string> pages) {

			int answer = 0;

			map<string, map<string, double>> scoreMap; // 페이지의 url을 key로 점수를 저장해 놓은 map.
			vector<string> urls; // page의 index와 url을 mapping 해놓은 vector.

			for (string page : pages) {

				// 문자열 검색하면서 얻어야 할 데이터
				// 1. word와 일치하는 단어 수 (기본점수)
				// 2. 페이지의 url
				// 3. <a herf의 수 (외부링크 수)
				// 4. <a herf의 url (링크 점수를 해당 페이지들에게 업데이트 하기 위함.)

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