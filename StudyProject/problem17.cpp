#include "problem17.h"

namespace KakaoBlind2018 {

	namespace problem17 {

		// string�� �ð� -> int�� ������ ��ȯ�ϴ� �Լ�.
		int time_to_min(string time) {

			int hour = stoi(time.substr(0, 2));
			int min = stoi(time.substr(3, 2));

			min += (hour * 60);

			return min;
		}

		// int�� �� -> string�� �ð����� ��ȯ�ϴ� �Լ�.
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

			// timetalbe�� �����͸� ������ ȯ���ؼ� vector�� ���� �� ������������ ����.
			// ������ �����͸� map���� ����. ( key = ������ �����ð�, data = ���� ������ ž�� ������ �¼� ��. )
			// ���� �°����� ž�°����� ������ ž��.
			// ��� �°��� Ȯ���� ��,
			// ������ ������ �ڸ��� �����ִٸ� ������ ���� �����ð��� ����.
			// �ڸ��� ���ٸ�, ������ ž���� �°����� 1�� ���� ���°��� ����.

			string answer = "";

			vector<int> mintable;
			map<int, int> busMap;

			int lastPersonTime = 0; // ������ ž�½°��� �����ð�.
			int lastBusTime = time_to_min("09:00") + (n - 1) * t; // ������ ���� �����ð�.

			// �� ������ ž�� ���ɽð� ���� map���� ����.
			for (int i = 0; i < n; i++)
				busMap[time_to_min("09:00") + (i * t)] = m;

			// time table �����͸� �� ������ ��ȯ.
			for (string time : timetable)
				mintable.push_back(time_to_min(time));

			// ������������ ����.
			sort(mintable.begin(), mintable.end());

			for (int min : mintable) {

				for (auto bTime : busMap) {

					// ���� �����ϴ� ���� ������ Ȯ��.
					// �ش� ������ ž�°����ϸ� ž��.

					if (min <= bTime.first && busMap[bTime.first] > 0) {
						busMap[bTime.first]--; // ���� �����ڸ� �ϳ��� ����.
						lastPersonTime = min;
						break;
					}
				}
			}

			if (busMap[lastBusTime] > 0) {
				// ������ ������ �ڸ��� ������ ���
				answer = min_to_time(lastBusTime);
			}
			else {
				// �ڸ��� ���� ��� ���������� ž���� ������� 1�� ����ž��.
				answer = min_to_time(lastPersonTime - 1);
			}

			return answer;
		}

		void execute() {

		}
	}
}