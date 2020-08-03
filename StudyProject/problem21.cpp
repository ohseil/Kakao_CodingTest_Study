#include "problem21.h"

namespace KakaoBlind2018 {

    namespace problem21 {

        int solution(string dartResult) {

            // S : single -> 점수^1
            // D : double -> 점수^2
            // T : triple -> 점수^3
            // * : 스타 -> 이전점수*2, 이번점수*2 (처음점수에서 걸릴 경우 처음점수만 2배)
            // # : 아차 -> 점수 * (-1)

            int answer = 0;

            // 각 점수를 저장할 벡터
            vector<int> scores;

            int score = 0; // 현재 점수
            bool finishScore = false; // 현재 점수의 보너스, 옵션까지 계산이 끝났는지에 대한 Flag.

            for (int i = 0; i < dartResult.length(); i++) {

                if (48 <= dartResult[i] && dartResult[i] <= 57) {
                    // 숫자
                    if (dartResult[i] == 48) {
                        // 숫자 0인 경우 10점이나 0점.
                        if (i - 1 >= 0 && dartResult[i - 1] == 49)
                            score = 10;
                        else
                            score = 0;
                    }
                    else
                        score = dartResult[i] - 48;
                }
                else if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
                    // 보너스
                    if (dartResult[i] == 'D')
                        score *= score;
                    else if (dartResult[i] == 'T')
                        score = (score * score * score);

                    if (i + 1 != dartResult.size()) {

                        if (dartResult[i + 1] == '*') {
                            score *= 2;
                            // 이전 점수가 있다면 이전 점수 * 2
                            if (scores.empty() == false)
                                scores[scores.size() - 1] *= 2;
                        }
                        else if (dartResult[i + 1] == '#') {
                            score *= (-1);
                        }
                    }

                    finishScore = true; // 현재 점수의 보너스, 옵션까지 계산 완료.
                }

                // 계산 완료 점수 벡터에 저장.
                if (finishScore == true) {
                    scores.push_back(score);
                    score = 0;
                    finishScore = false;
                }
            }

            // 계산 점수들 총합.
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