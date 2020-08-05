#include "problem22.h"

namespace KakaoBlind2018 {

	namespace problem22 {

		bool comp(pair<int, int> lhs, pair<int, int> rhs) {
			if (lhs.second > rhs.second)
				return true;
			else if (lhs.second == rhs.second)
				if (lhs.first < rhs.first)
					return true;
			return false;
		}

		// string�� �ð� -> int�� ������ ��ȯ�ϴ� �Լ�.
		int time_to_min(string time) {

			int hour = stoi(time.substr(0, 2));
			int min = stoi(time.substr(3, 2));

			min += (hour * 60);

			return min;
		}

		// # ���� ������ �ҹ��ڷ� ����. (ex) C# -> c)
		string changeMelody(string str) {
			string result = "";
			for (int i = 0; i < str.length(); i++) {
				if (str[i] == '#')
					result[result.size() - 1] = tolower(result[result.size() - 1]);
				else
					result += str[i];
			}

			return result;
		}

		string solution(string m, vector<string> musicinfos) {

			// m = ���� ���� ��ε�
			// �� ����ð�, ���̸�, ���ε�� �̷���� string �迭.

			// 1. ����ð���ŭ ���ε��� ��ε� �迭 ���ϱ�
			// 2. ���� ���� ��ε�� ��ġ�ϴ� ���Ʈ �̱�.
			// 3. ���� ����Ʈ�� ����ð��� ���� �� ���� ��.
			// 4. ���� ����ð��� ���� ���� ��������� ���� ��ϵ� ���� ��.
			// 5. ���� ���� ��� "(None)" ���.

			string answer = "";

			// �� ���� ����ð�, ���̸�, ��ε� ������ ����.
			// �� map�� key = musicinfos���� �� ���� index
			map<int, int> timeMap;
			map<int, string> nameMap;
			map<int, string> melodyMap;

			m = changeMelody(m);

			for (int i = 0; i < musicinfos.size(); i++) {

				string music = musicinfos[i];

				string startTime, finishTime, name, melody;

				startTime = music.substr(0, music.find(","));
				music = music.substr(music.find(",") + 1);
				finishTime = music.substr(0, music.find(","));
				music = music.substr(music.find(",") + 1);
				name = music.substr(0, music.find(","));
				melody = music.substr(music.find(",") + 1);

				melody = changeMelody(melody);

				int melodySize = melody.length();
				int runTime = time_to_min(finishTime) - time_to_min(startTime);

				string runMelody = "";

				for (int j = 0; j < runTime; j++) {
					runMelody += melody[j % melodySize];
				}

				timeMap[i] = runTime;
				nameMap[i] = name;
				melodyMap[i] = runMelody;
			}

			vector<pair<int, int>> containedSong;

			// ���� ��ε�� ��ġ�ϴ� �� ������.
			for (auto a : melodyMap) {
				int findIndex = a.second.find(m);
				// pair.first = ���� index, pair.second = �� ����ð�
				if (0 <= findIndex && findIndex <= a.second.length() - 1)
					containedSong.push_back(make_pair<int, int>((int)a.first, (int)timeMap[a.first]));
			}

			if (containedSong.empty() == true) {
				// ��ġ�ϴ� ���� ���ٸ� "(None)" ���
				answer = "(None)";
			}
			else {
				// ��ġ�ϴ� ��� sorting.
				// 1. �� ����ð� ������ sorting.
				// 2. �� ����ð��� ������ �� ��� ������ sorting (�� index)
				sort(containedSong.begin(), containedSong.end(), comp);
				answer = nameMap[containedSong[0].first];
			}


			return answer;
		}

		void execute() {

			string m = "CC#BCC#BCC#BCC#B";
			vector<string> v;

			v.push_back("03:00,03:30,FOO,CC#B");
			v.push_back("04:00,04:08,BAR,CC#BCC#BCC#B");

			cout << solution(m, v) << endl;
		}
	}
}