#include "problem17.h"

int time_to_min(string time) {

	int hour = stoi(time.substr(0, 2));
	int min = stoi(time.substr(3, 2));

	min += (hour * 60);

	return min;
}

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

	// n * m = 총 버스에 탑승할 수 있는 크루 수.
	// 여기서 젤 늦게 타면 된다.

	// lastTime = 마지막 버스 도착시간.

	// 크루의 도착시간을 오름차순으로 정렬.

	// 각 크루의 도착시간을 보고 마지막 버스 도착시간보다 같거나 빠르면
	// 탑승할 수 있는 크루 수 -1 을 한다.
	// 마지막 탑승하는 승객의 시간보다 1분 일찍 오는 시간이 답이다.
	// 만약 버스에 탑승 가능한 총 크루 수보다 적은 크루가 탔다면
	// 그냥 마지막 버스 도착시간이 답이된다.

	int totalCount = n * m;



	string answer = "";

	return answer;
}

namespace KakaoBlind2018 {

	namespace problem17 {

		void execute() {

			string time = "09:12";
			int min = time_to_min(time);
			cout << time_to_min(time) << " " << min << endl;
			cout << min_to_time(min) << endl;
		}
	}
}