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

				// url 구하기 ==============================================
				string url;

				string metaStr = page.substr(page.find("<meta property="));
				int urlStartIndex = metaStr.find("https://");
				int urlEndIndex = metaStr.substr(metaStr.find("https://")).find("\"");
				url = metaStr.substr(urlStartIndex, urlEndIndex);
				cout << urlStartIndex << " " << urlEndIndex << " " << url << endl;
				// ===========================================================



			}

			return answer;
		}

		void execute() {

			string word = "blind";
			vector<string> pages;

			pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>");
			pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>");
			pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>");
		
			solution(word, pages);
		}
	}
}