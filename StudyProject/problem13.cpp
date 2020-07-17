#include "problem13.h"

namespace KakaoBlind2019 {

	namespace problem13 {

		bool isAlpha(int code) {
			return (65 <= code && code <= 90) || (97 <= code && code <= 122);
		}

		bool isSameString(string word, string str, map<int, int> alphaMap) {
			for (int i = 0; i < word.length(); i++)
				if (word[i] != str[i] && alphaMap[word[i]] != str[i])
					return false;
			return true;
		}

		vector<string> ahrefCount(string str) {
			vector<string> urls;
			while (str.find("<a href") < str.length()) {
				str = str.substr(str.find("<a href") + 7);
				int urlStartIndex = str.find("https://");
				int urlEndIndex = str.substr(str.find("https://")).find("\"");
				urls.push_back(str.substr(urlStartIndex, urlEndIndex));
			}
			return urls;
		}

		int solution(string word, vector<string> pages) {

			int answer = 0;

			map<string, map<string, double>> scoreMap; // 페이지의 url을 key로 점수를 저장해 놓은 map.
			map<int, int> alphaMap; // 대문자 소문자 mapping map.
			vector<string> urls; // page의 index와 url을 mapping 해놓은 vector.

			for (int i = 65; i <= 90; i++) {
				alphaMap[i] = i + 32;
				alphaMap[i + 32] = i;
			}

			for (int i = 0; i < pages.size(); i++) {

				// 문자열 검색하면서 얻어야 할 데이터
				// 1. word와 일치하는 단어 수 (기본점수)
				// 2. 페이지의 url
				// 3. <a herf의 수 (외부링크 수)
				// 4. <a herf의 url (링크 점수를 해당 페이지들에게 업데이트 하기 위함.)

				// url 구하기 ==============================================
				string url;

				string metaStr = pages[i].substr(pages[i].find("<meta property="));

				int urlStartIndex = metaStr.find("https://");
				int urlEndIndex = metaStr.substr(metaStr.find("https://")).find("\"");

				url = metaStr.substr(urlStartIndex, urlEndIndex);
				// ===========================================================

				// 기본 점수 구하기 ================================================
				int bodyStartIndex = pages[i].find("<body") + 7;
				int bodyEndIndex = pages[i].find("</body") - 1;

				string bodyStr = pages[i].substr(bodyStartIndex, bodyEndIndex - bodyStartIndex);

				// 바로 이전 문자를 저장할 변수
				int beforeChar = '@';
				// 일치하는 개수(기본점수)
				int sameNum = 0;

				int wLength = word.length();
				for (int j = 0; j < bodyStr.length(); j++) {

					if ((bodyStr[j] == word[0] || alphaMap[bodyStr[j]] == word[0]) && !isAlpha(beforeChar)) {

						if (isSameString(word, bodyStr.substr(j, wLength), alphaMap) == true
							&& (j + wLength >= bodyStr.length() - 1 || !isAlpha(bodyStr[j + wLength]))) {
							sameNum++;
						}
					}

					beforeChar = bodyStr[j];
				}

				// ============================================================

				// 외부링크 구하기 ===============================================
				vector<string> hrefUrls = ahrefCount(bodyStr);

				double Linkscore = (double)sameNum / hrefUrls.size();
				for (string hrefurl : hrefUrls) {
					// 기본점수 / 외부링크수 값을 각 외부링크 페이지의 링크점수에 +
					scoreMap[hrefurl]["score3"] += Linkscore;
				}
				// ==================================================================

				// 기본점수 = smenum
				// 외부링크수 = hrefUrls.size()
				scoreMap[url]["score1"] = (double)sameNum;
				scoreMap[url]["score2"] = (double)hrefUrls.size();

				urls.push_back(url);
			}

			double maxScore = 0.0;

			for (int i = 0; i < urls.size(); i++) {
				if (maxScore < scoreMap[urls[i]]["score1"] + scoreMap[urls[i]]["score3"]) {
					maxScore = scoreMap[urls[i]]["score1"] + scoreMap[urls[i]]["score3"];
					answer = i;
				}
			}

			return answer;
		}

		void execute() {

			string word = "blind";
			vector<string> pages;

			pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>");
			pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>");
			pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>");
		
			//pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>");
			//pages.push_back("<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>");

			cout << solution(word, pages) << endl;

		}
	}
}