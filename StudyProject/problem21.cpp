#include "problem21.h"

namespace KakaoBlind2018 {

    namespace problem21 {

        int solution(string dartResult) {

            // S : single -> ����^1
            // D : double -> ����^2
            // T : triple -> ����^3
            // * : ��Ÿ -> ��������*2, �̹�����*2 (ó���������� �ɸ� ��� ó�������� 2��)
            // # : ���� -> ���� * (-1)

            int answer = 0;

            // �� ������ ������ ����
            vector<int> scores;

            int score = 0; // ���� ����
            bool finishScore = false; // ���� ������ ���ʽ�, �ɼǱ��� ����� ���������� ���� Flag.

            for (int i = 0; i < dartResult.length(); i++) {

                if (48 <= dartResult[i] && dartResult[i] <= 57) {
                    // ����
                    if (dartResult[i] == 48) {
                        // ���� 0�� ��� 10���̳� 0��.
                        if (i - 1 >= 0 && dartResult[i - 1] == 49)
                            score = 10;
                        else
                            score = 0;
                    }
                    else
                        score = dartResult[i] - 48;
                }
                else if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
                    // ���ʽ�
                    if (dartResult[i] == 'D')
                        score *= score;
                    else if (dartResult[i] == 'T')
                        score = (score * score * score);

                    if (i + 1 != dartResult.size()) {

                        if (dartResult[i + 1] == '*') {
                            score *= 2;
                            // ���� ������ �ִٸ� ���� ���� * 2
                            if (scores.empty() == false)
                                scores[scores.size() - 1] *= 2;
                        }
                        else if (dartResult[i + 1] == '#') {
                            score *= (-1);
                        }
                    }

                    finishScore = true; // ���� ������ ���ʽ�, �ɼǱ��� ��� �Ϸ�.
                }

                // ��� �Ϸ� ���� ���Ϳ� ����.
                if (finishScore == true) {
                    scores.push_back(score);
                    score = 0;
                    finishScore = false;
                }
            }

            // ��� ������ ����.
            for (int score : scores)
                answer += score;

            return answer;
        }

        void execute() {

            string str = "1S2D*3T";

            cout << solution(str) << endl;
        }
    }
}