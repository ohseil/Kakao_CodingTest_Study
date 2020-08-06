#include "problem26.h"

namespace KakaoBlind2018 {

    namespace problem26 {

        // ���� 0 ~ 15������ char�� mapping array
        char numList[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

        // ���ڸ� ������ ���� string������ ��ȯ
        string ChangeNumber(int num, int n) {

            // ���ڰ� 0�̸� "0" ��ȯ
            if (num == 0)
                return "0";

            string temp = "", result = "";

            while (num != 0) {
                temp += numList[num % n];
                num /= n;
            }

            for (int i = temp.length() - 1; i >= 0; i--)
                result += temp[i];

            return result;
        }

        string solution(int n, int t, int m, int p) {

            // n : ����
            // t : ���ؾ� �ϴ� ���� ����
            // m : ���ӿ� ������ ��� ��
            // p : �� ����

            // ó�� ���� ���� �� ������ p.
            // �ι�° ���ʹ� p + m
            // t ���� ���Ϸ��� p + m * (t - 1) ���� ���ڸ� ���ؾ��Ѵ�.
            // ������ Ȯ���ϰ� ���� ������ŭ ���ڸ� ���Ѵ�.

            // 10���������� ���ڸ� �ִ�.
            // 11 ~ 16������ A,B,C,D,E,F �� ���´�.

            string answer = "";
            string num_to_string = "";

            int needNum = p + m * (t - 1); // �ʿ��� ���� ����
            int num = 0; // ���� ����
            int curTurn = p; // ���� ����

            // ���ؾ� �ϴ� �������� �ö����� ����.
            while (curTurn <= needNum) {

                // ���� ���ڸ� �ش� �������� ��ȯ �� string���� ��ȯ�Ͽ� ���̱�
                num_to_string += ChangeNumber(num, n);

                // ���ݱ��� ���� ������ ������ ���� �� �������� ������
                // ���� ���������� ���� ���ڸ� ���� �� �����Ƿ� answer�� + ���ְ�
                // ���� ������ �Ѿ��.
                if (num_to_string.length() >= curTurn) {
                    answer += num_to_string[curTurn - 1];
                    curTurn += m;
                }

                num++;
            }

            return answer;
        }

        void execute() {

            int n = 16;
            int t = 16;
            int m = 2;
            int p = 1;

            cout << solution(n, t, m, p) << endl;

        }
    }
}