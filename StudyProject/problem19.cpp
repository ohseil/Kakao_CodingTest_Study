#include "problem19.h"

namespace KakaoBlind2018 {

    namespace problem19 {

        int solution(int cacheSize, vector<string> cities) {

            // cahce size가 0일 경우
            if (cacheSize == 0)
                return 5 * cities.size();

            int answer = 0;

            string* cache = new string[cacheSize];
            int* cacheTime = new int[cacheSize];

            // 배열 초기화
            for (int i = 0; i < cacheSize; i++) {
                cache[i] = "";
                cacheTime[i] = 0;
            }

            for (string city : cities) {

                // cache 전체 시간 +

                // if cache hit
                // cache time 초기화

                // else if cache miss
                // cache data 갱신

                // 소문자로 변경
                for (int i = 0; i < city.length(); i++)
                    city[i] = tolower(city[i]);

                int hitIndex = -1;
                bool isHit = false;

                for (int i = 0; i < cacheSize; i++)
                    cacheTime[i]++;

                for (int i = 0; i < cacheSize; i++) {
                    // cache hit.
                    if (cache[i] == city) {
                        isHit = true;
                        hitIndex = i;
                        break;
                    }
                }

                if (isHit == true) {
                    // cache hit.
                    answer += 1;
                    cacheTime[hitIndex] = 0;
                }
                else {
                    // cache miss.
                    int longestTime = 0;
                    int longestIndex = 0;
                    for (int i = 0; i < cacheSize; i++) {
                        if (longestTime < cacheTime[i]) {
                            longestTime = cacheTime[i];
                            longestIndex = i;
                        }
                    }

                    cache[longestIndex] = city;
                    cacheTime[longestIndex] = 0;
                    answer += 5;
                }

            }

            return answer;
        }

        void execute() {


        }
    }
}