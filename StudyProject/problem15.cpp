#include "problem15.h"

namespace KakaoBlind2018 {

	namespace problem15 {

		bool comp(pair<double, double> lhs, pair<double, double> rhs) {
			if (lhs.first <= rhs.first)
				return true;
			return false;
		}

		int solution(vector<string> lines) {

			int answer = 0;

			vector<pair<int, int>> datas;

			for (string line : lines) {

				// line에서 날짜 빼고 시간, 분, 초를 초로 환산한다.

				string str = line.substr(11); // 년,월,일 짜르기

				double hour, min, sec;

				hour = stod(str.substr(0, 2));
				min = stod(str.substr(3, 2));
				sec = stod(str.substr(6, 6));

				min += hour * 60;
				sec += min * (double)60; // 완료시간을 초로 환산한 결과.

				// 시작시간을 초로 환산한 결과
				double startSec = sec - stod(str.substr(0, str.length() - 1).substr(13)) + 0.001;

				// 소수점 없애고 int형으로 변환.
				startSec = round(startSec *= 1000);
				sec = round(sec *= 1000);

				// 환산 결과를 시작시간, 완료시간 두가지 페어로 벡터에 저장.
				datas.push_back(make_pair<int, int>((int)startSec, (int)sec));

			}

			// 시작시간 기준 오름차순으로 정렬
			sort(datas.begin(), datas.end(), comp);

			// 각 데이터마다 데이터의 시작시간을 포함하도록 1초 구간을 설정하여
			// 큐를 이용하여 구간마다 개수 확인.
			// 위의 방식으로 마지막 데이터까지 검색.
			// 이 중 가장 많은 개수가 포함된 구간 출력.

			queue<int> q;

			for (auto data : datas) {

				// 새로운 데이터의 시작시간을 포함한 1초구간에서
				// 이전 구간에 포함되어 있던 데이터 중
				// 포함되지 않는 데이터 큐에서 제거
				int sTime = data.first - 1000 + 1;

				if (!q.empty()) {

					int qSize = q.size();

					for (int i = 0; i < qSize; i++) {
						int comparing = q.front();
						q.pop();
						if (sTime <= comparing) {
							q.push(comparing);
						}
					}
				}

				q.push(data.second);

				// 현재 1초 구간에서 포함되어 있는 데이터 개수 확인.
				if (answer < q.size())
					answer = q.size();

			}

			return answer;
		}

		void execute() {

			vector<string> lines;
			lines.push_back("2016-09-15 00:59:57.421 0.351s");
			lines.push_back("2016-09-15 00:59:58.233 1.181s");
			lines.push_back("2016-09-15 00:59:58.299 0.8s");
			lines.push_back("2016-09-15 00:59:58.688 1.041s");
			lines.push_back("2016-09-15 00:59:59.591 1.412s");
			lines.push_back("2016-09-15 01:00:00.464 1.466s");
			lines.push_back("2016-09-15 01:00:00.741 1.581s");
			lines.push_back("2016-09-15 01:00:00.748 2.31s");
			lines.push_back("2016-09-15 01:00:00.966 0.381s");
			lines.push_back("2016-09-15 01:00:02.066 2.62s");

			cout << solution(lines) << endl;
		}
	}
}