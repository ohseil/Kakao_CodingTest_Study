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

	// n * m = �� ������ ž���� �� �ִ� ũ�� ��.
	// ���⼭ �� �ʰ� Ÿ�� �ȴ�.

	// lastTime = ������ ���� �����ð�.

	// ũ���� �����ð��� ������������ ����.

	// �� ũ���� �����ð��� ���� ������ ���� �����ð����� ���ų� ������
	// ž���� �� �ִ� ũ�� �� -1 �� �Ѵ�.
	// ������ ž���ϴ� �°��� �ð����� 1�� ���� ���� �ð��� ���̴�.
	// ���� ������ ž�� ������ �� ũ�� ������ ���� ũ�簡 ���ٸ�
	// �׳� ������ ���� �����ð��� ���̵ȴ�.

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