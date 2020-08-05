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

		// string형 시간 -> int형 분으로 변환하는 함수.
		int time_to_min(string time) {

			int hour = stoi(time.substr(0, 2));
			int min = stoi(time.substr(3, 2));

			min += (hour * 60);

			return min;
		}

		// # 붙은 음들을 소문자로 변경. (ex) C# -> c)
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

			// m = 내가 들은 멜로디
			// 곡 재생시간, 곡이름, 곡멜로디로 이루어진 string 배열.

			// 1. 재생시간만큼 곡멜로디의 멜로디 배열 구하기
			// 2. 내가 들은 멜로디와 일치하는 곡리스트 뽑기.
			// 3. 뽑은 리스트중 재생시간이 가장 긴 곡이 답.
			// 4. 만약 재생시간이 같은 곡이 여러개라면 먼저 등록된 곡이 답.
			// 5. 답이 없을 경우 "(None)" 출력.

			string answer = "";

			// 각 곡의 재생시간, 곡이름, 멜로디를 맵으로 생성.
			// 각 map의 key = musicinfos에서 각 곡의 index
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

			// 나의 멜로디와 일치하는 곡 리스팅.
			for (auto a : melodyMap) {
				int findIndex = a.second.find(m);
				// pair.first = 곡의 index, pair.second = 곡 재생시간
				if (0 <= findIndex && findIndex <= a.second.length() - 1)
					containedSong.push_back(make_pair<int, int>((int)a.first, (int)timeMap[a.first]));
			}

			if (containedSong.empty() == true) {
				// 일치하는 곡이 없다면 "(None)" 출력
				answer = "(None)";
			}
			else {
				// 일치하는 곡들 sorting.
				// 1. 곡 재생시간 순으로 sorting.
				// 2. 곡 재생시간이 같으면 곡 등록 순으로 sorting (곡 index)
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