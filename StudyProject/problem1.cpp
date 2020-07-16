#include "problem1.h"

namespace KakaoBlind2020 {

	namespace problem1 {

		int solution(string s) {

			int answer = s.length();

			// 2�� �������� ���ڿ����� / 2 �������� �߶� Ȯ���غ���
			// ���� ���� ���ڿ� ���� ���.
			for (int i = 1; i <= s.length() / 2; i++) {

				// i �������� �߶� ���ڿ� ���� Ȯ��.

				string str = ""; // ���� ���ڿ�.
				int strLength = 0; // i ������ �߶��� ���� ���ڿ� ����.
				int sameNum = 0; // ���� ���� ���߰� �ִ� ���ڿ��� ���� ����.

				// i ������ �����̸鼭 Ȯ��
				for (int j = 0; j < s.length(); j += i) {

					// ������ ���ڿ��� i �������� ���̰� ���� ���ڿ��� ���
					// ���� ���ڿ� ���� ��� �߰�.
					if (j > s.length() - i) {

						strLength += (s.length() - j);

						if (sameNum > 98) // ���� ���ڿ��� 99�� �̻��̸� ���� ���ڿ� ���� 100�� �̻��̹Ƿ� 3�ڸ� �߰�.
							strLength += 3;
						else if (sameNum > 8) // 9�� �̻��̸� ���� ���� 10�� �̻��̹Ƿ� 2�ڸ� �߰�.
							strLength += 2;
						else if (sameNum > 0) // 1�� �̻��̸� ���� ���� 2�� �̻��̹Ƿ� 1�ڸ� �߰�.(1���� ǥ�� ����.)
							strLength += 1;

						break;
					}

					// ���� ��ġ�������� i ������ ���ڿ� ���ϱ�.
					//string checkStr = s.substr(j, i);
					string checkStr = "";
					for (int k = j; k < j + i; k++)
						checkStr += s[k];

					// ���� Ȯ���ߴ� ���ڿ��� ��.
					// ó���̶�� ���� ���ڿ��� ""�̴�.e
					if (!str.compare(checkStr)) {
						// ���� ���ڿ��� ���� ���
						// ���� ���ڿ��� ������ + ����.
						sameNum++;

						if (j == s.length() - i) {
							if (sameNum > 98) // ���� ���ڿ��� 99�� �̻��̸� ���� ���ڿ� ���� 100�� �̻��̹Ƿ� 3�ڸ� �߰�.
								strLength += 3;
							else if (sameNum > 8) // 9�� �̻��̸� ���� ���� 10�� �̻��̹Ƿ� 2�ڸ� �߰�.
								strLength += 2;
							else if (sameNum > 0) // 1�� �̻��̸� ���� ���� 2�� �̻��̹Ƿ� 1�ڸ� �߰�.(1���� ǥ�� ����.)
								strLength += 1;

							sameNum = 0;
						}
					}
					else {
						// ó�� ���ڿ��̰ų� ���� ���ڿ��� �ٸ� ���
						// �� ���ڿ��� ���̸� + ���ְ�
						// Ȥ�� ���������� ���ڿ��� ������ �������� ���
						// ������ ǥ�����ִ� ���ڸ�ŭ ���� + ���ֱ�.
						strLength += i;//checkStr.length(); // i ���� �߰�.
						str = checkStr; // Ȯ���� ���ڿ��� �ٲ�.

						if (sameNum > 98) // ���� ���ڿ��� 99�� �̻��̸� ���� ���ڿ� ���� 100�� �̻��̹Ƿ� 3�ڸ� �߰�.
							strLength += 3;
						else if (sameNum > 8) // 9�� �̻��̸� ���� ���� 10�� �̻��̹Ƿ� 2�ڸ� �߰�.
							strLength += 2;
						else if (sameNum > 0) // 1�� �̻��̸� ���� ���� 2�� �̻��̹Ƿ� 1�ڸ� �߰�.(1���� ǥ�� ����.)
							strLength += 1;

						sameNum = 0;
					}

				}

				// ���� ������ �߶��� ����� ���ڿ� ���̿� ���ؼ�
				// �� ª���� ����.
				if (answer > strLength)
					answer = strLength;
			}

			return answer;
		}


		void execute() {

			string str = "abcabcdede";
			cout << solution(str) << endl;

		}

	}

}