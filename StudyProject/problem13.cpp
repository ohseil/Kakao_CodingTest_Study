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

				// url ���ϱ� ==============================================
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