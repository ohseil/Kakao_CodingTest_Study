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

			map<string, map<string, double>> scoreMap; // �������� url�� key�� ������ ������ ���� map.
			map<int, int> alphaMap; // �빮�� �ҹ��� mapping map.
			vector<string> urls; // page�� index�� url�� mapping �س��� vector.

			for (int i = 65; i <= 90; i++) {
				alphaMap[i] = i + 32;
				alphaMap[i + 32] = i;
			}

			for (int i = 0; i < pages.size(); i++) {

				// ���ڿ� �˻��ϸ鼭 ���� �� ������
				// 1. word�� ��ġ�ϴ� �ܾ� �� (�⺻����)
				// 2. �������� url
				// 3. <a herf�� �� (�ܺθ�ũ ��)
				// 4. <a herf�� url (��ũ ������ �ش� �������鿡�� ������Ʈ �ϱ� ����.)

				// url ���ϱ� ==============================================
				string url;

				string metaStr = pages[i].substr(pages[i].find("<meta property="));

				int urlStartIndex = metaStr.find("https://");
				int urlEndIndex = metaStr.substr(metaStr.find("https://")).find("\"");

				url = metaStr.substr(urlStartIndex, urlEndIndex);
				// ===========================================================

				// �⺻ ���� ���ϱ� ================================================
				int bodyStartIndex = pages[i].find("<body") + 7;
				int bodyEndIndex = pages[i].find("</body") - 1;

				string bodyStr = pages[i].substr(bodyStartIndex, bodyEndIndex - bodyStartIndex);

				// �ٷ� ���� ���ڸ� ������ ����
				int beforeChar = '@';
				// ��ġ�ϴ� ����(�⺻����)
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

				// �ܺθ�ũ ���ϱ� ===============================================
				vector<string> hrefUrls = ahrefCount(bodyStr);

				double Linkscore = (double)sameNum / hrefUrls.size();
				for (string hrefurl : hrefUrls) {
					// �⺻���� / �ܺθ�ũ�� ���� �� �ܺθ�ũ �������� ��ũ������ +
					scoreMap[hrefurl]["score3"] += Linkscore;
				}
				// ==================================================================

				// �⺻���� = smenum
				// �ܺθ�ũ�� = hrefUrls.size()
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