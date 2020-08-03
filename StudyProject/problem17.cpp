#include "problem17.h"

namespace KakaoBlind2018 {

	namespace problem17 {

		// string형 시간 -> int형 분으로 변환하는 함수.
		int time_to_min(string time) {

			int hour = stoi(time.substr(0, 2));
			int min = stoi(time.substr(3, 2));

			min += (hour * 60);

			return min;
		}

		// int형 분 -> string형 시간으로 변환하는 함수.
		string min_to_time(int min) {

			string time;

			int hour = min / 60;

			min %= 60;

			string strHour = "", strMin = "";

			if (to_string(hour).length() == 1)
				strHour += "0";
			if (to_string(min).length() == 1)
				strMin += "0";

			strHour += to_string(hour);
			strMin += to_string(min);

			time += (strHour + ":" + strMin);

			return time;
		}

		string solution(int n, int t, int m, vector<string> timetable) {

			// timetalbe의 데이터를 분으로 환산해서 vector로 생성 후 오름차순으로 정렬.
			// 버스의 데이터를 map으로 생성. ( key = 버스의 도착시간, data = 현재 버스의 탑승 가능한 좌석 수. )
			// 빠른 승객부터 탑승가능한 버스에 탑승.
			// 모든 승객을 확인한 후,
			// 마지막 버스에 자리가 남아있다면 마지막 버스 도착시간이 정답.
			// 자리가 없다면, 마지막 탑승한 승객보다 1분 일찍 오는것이 정답.

			string answer = "";

			vector<int> mintable;
			map<int, int> busMap;

			int lastPersonTime = 0; // 마지막 탑승승객의 도착시간.
			int lastBusTime = time_to_min("09:00") + (n - 1) * t; // 마지막 버스 도착시간.

			// 각 버스의 탑승 가능시간 범위 map으로 생성.
			for (int i = 0; i < n; i++)
				busMap[time_to_min("09:00") + (i * t)] = m;

			// time table 데이터를 분 단위로 변환.
			for (string time : timetable)
				mintable.push_back(time_to_min(time));

			// 오름차순으로 정렬.
			sort(mintable.begin(), mintable.end());

			for (int min : mintable) {

				for (auto bTime : busMap) {

					// 빨리 도착하는 버스 순으로 확인.
					// 해당 버스에 탑승가능하면 탑승.

					if (min <= bTime.first && busMap[bTime.first] > 0) {
						busMap[bTime.first]--; // 버스 남는자리 하나씩 감소.
						lastPersonTime = min;
						break;
					}
				}
			}

			if (busMap[lastBusTime] > 0) {
				// 마지막 버스에 자리가 남았을 경우
				answer = min_to_time(lastBusTime);
			}
			else {
				// 자리가 없을 경우 마지막으로 탑승한 사람보다 1분 일찍탑승.
				answer = min_to_time(lastPersonTime - 1);
			}

			return answer;
		}

		void execute() {

		}
	}
}