#include "problem26.h"

namespace KakaoBlind2018 {

    namespace problem26 {

        // 숫자 0 ~ 15까지의 char형 mapping array
        char numList[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

        // 숫자를 진법에 맞춰 string형으로 반환
        string ChangeNumber(int num, int n) {

            // 숫자가 0이면 "0" 반환
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

            // n : 진법
            // t : 말해야 하는 숫자 개수
            // m : 게임에 참여한 사람 수
            // p : 내 순서

            // 처음 내가 말할 때 순서는 p.
            // 두번째 부터는 p + m
            // t 개를 말하려면 p + m * (t - 1) 개의 문자를 구해야한다.
            // 진법을 확인하고 위의 개수만큼 숫자를 구한다.

            // 10진법까지는 숫자만 있다.
            // 11 ~ 16진법은 A,B,C,D,E,F 도 나온다.

            string answer = "";
            string num_to_string = "";

            int needNum = p + m * (t - 1); // 필요한 문자 개수
            int num = 0; // 시작 숫자
            int curTurn = p; // 현재 순서

            // 구해야 하는 순서까지 올때까지 진행.
            while (curTurn <= needNum) {

                // 현재 숫자를 해당 진법으로 변환 후 string으로 반환하여 붙이기
                num_to_string += ChangeNumber(num, n);

                // 지금까지 구한 문자의 개수가 현재 내 순서보다 많으면
                // 현재 내순서에서 말할 문자를 구할 수 있으므로 answer에 + 해주고
                // 다음 순서로 넘어가기.
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