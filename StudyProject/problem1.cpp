#include "problem1.h"


int KakaoBlind2020::problem1::solution(string s) {

	int answer = s.length();

	/*// 2�� �������� (���ڿ� ���� / 2) ���� ���� �߶󺸱�.
	for (int i = 1; i <= s.length() / 2; i++) {

		string str = "";

		int strLength = i;
		int sameStr = 0;

		// ó�� i ������ ���ڿ��� ����.
		for (int j = 0; j < i; j++)
			str += s[j];

		for (int j = i; j < s.length(); j+=i) {

			if (j > s.length() - i) {
				// ���� ���ڿ� ���� �߰��ϰ� break.
				strLength += (s.length() - j);
				break;
			}

			string checkStr = "";

			for (int k = j; k < j + i; k++) {
				checkStr += s[k];
			}

			if (str != checkStr) {
				// ���� ���ڿ��� ���� ����
				// ������ �񱳹��ڿ��� �ٲ�
				str = checkStr;

				strLength += i; // �ٲ��� ���ڿ��� ���� �߰�.

				// ������ ���� ���ڿ��� ���� ���
				if (sameStr > 100) {
					strLength += 3;
				}
				else if (sameStr > 10) {
					strLength += 2;
				}
				else if (sameStr > 0) {
					strLength += 1;
				}

				sameStr = 0;
			}
			else {
				// ���� ���ڿ��� ����.
				sameStr++; // ���� ���ڿ� ���� ����.

				if (j + i > s.length() - i) {
					// ������ ���� ���ڿ��� ���� ���
					if (sameStr > 100) {
						strLength += 3;
					}
					else if (sameStr > 10) {
						strLength += 2;
					}
					else if (sameStr > 0) {
						strLength += 1;
					}
				}

			}
		}

		if (answer > strLength)
			answer = strLength;

	}*/

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

			/*if (j + i >= s.length()) {
				if (sameNum != 0) {
					strLength += to_string(sameNum).length();
					break;
				}
			}*/
		}

		// ���� ������ �߶��� ����� ���ڿ� ���̿� ���ؼ�
		// �� ª���� ����.
		if (answer > strLength)
			answer = strLength;
	}

	return answer;
}


void KakaoBlind2020::problem1::execute() {

	string str = "abcabcdede";
	cout << solution(str) << endl;

}

/*
// ���� �ڵ�
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
			//if (j > s.length() - i) {
				//strLength += (s.length() - j);
				//break;
			//}

			// ���� ��ġ�������� i ������ ���ڿ� ���ϱ�.
			string checkStr = s.substr(j, i);
			//for (int k = j; k < j + i; k++)
				//checkStr += s[k];

			// ���� Ȯ���ߴ� ���ڿ��� ��.
			// ó���̶�� ���� ���ڿ��� ""�̴�.e
			if (!str.compare(checkStr)) {
				// ���� ���ڿ��� ���� ���
				// ���� ���ڿ��� ������ + ����.
				sameNum++;

				//if (j == s.length() - i) {
					//if (sameNum > 98) // ���� ���ڿ��� 99�� �̻��̸� ���� ���ڿ� ���� 100�� �̻��̹Ƿ� 3�ڸ� �߰�.
						//strLength += 3;
					//else if (sameNum > 8) // 9�� �̻��̸� ���� ���� 10�� �̻��̹Ƿ� 2�ڸ� �߰�.
						//strLength += 2;
					//else if (sameNum > 0) // 1�� �̻��̸� ���� ���� 2�� �̻��̹Ƿ� 1�ڸ� �߰�.(1���� ǥ�� ����.)
						//strLength += 1;

					//sameNum = 0;
				}
			}
			else {
				// ó�� ���ڿ��̰ų� ���� ���ڿ��� �ٸ� ���
				// �� ���ڿ��� ���̸� + ���ְ�
				// Ȥ�� ���������� ���ڿ��� ������ �������� ���
				// ������ ǥ�����ִ� ���ڸ�ŭ ���� + ���ֱ�.
				strLength += checkStr.length(); // i ���� �߰�.
				str = checkStr; // Ȯ���� ���ڿ��� �ٲ�.

				if (sameNum > 98) // ���� ���ڿ��� 99�� �̻��̸� ���� ���ڿ� ���� 100�� �̻��̹Ƿ� 3�ڸ� �߰�.
					strLength += 3;
				else if (sameNum > 8) // 9�� �̻��̸� ���� ���� 10�� �̻��̹Ƿ� 2�ڸ� �߰�.
					strLength += 2;
				else if (sameNum > 0) // 1�� �̻��̸� ���� ���� 2�� �̻��̹Ƿ� 1�ڸ� �߰�.(1���� ǥ�� ����.)
					strLength += 1;

				sameNum = 0;
			}

			if (j + i >= s.length()) {
				if (sameNum != 0) {
					strLength += to_string(sameNum).length();
					break;
				}
			}
		}

		// ���� ������ �߶��� ����� ���ڿ� ���̿� ���ؼ�
		// �� ª���� ����.
		if (answer > strLength)
			answer = strLength;
	}

	return answer;
}*/