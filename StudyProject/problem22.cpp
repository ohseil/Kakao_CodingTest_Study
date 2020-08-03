#include "problem22.h"

bool comp(pair<int, int> lhs, pair<int, int> rhs) {
    if (lhs.second > rhs.second)
        return true;
    else if (lhs.second == rhs.second)
        if (lhs.first < rhs.second)
            return true;
    return false;
}
/*
bool isConatinMelody(vector<string> m, vector<string> contained) {

    for (int i = 0; i < contained.size(); i++) {
        if (contained[i] == m[0]) {
            bool isContained = true;

            int containNum = 0;
            int index = i + 1;
            for (int j = 1; j < m.size(); j++) {
                if (m[j] == contained[index])
            }
        }
    }
}*/

// string형 시간 -> int형 분으로 변환하는 함수.
int time_to_min(string time) {

    int hour = stoi(time.substr(0, 2));
    int min = stoi(time.substr(3, 2));

    min += (hour * 60);

    return min;
}

vector<string> changeMelody(string str) {
    
    vector<string> result;

    for (int i = 0; i < str.length(); i++) {

        if (str[i] == '#') {
            result[result.size() - 1] += '#';
        }
        else {
            string st = "";
            st += str[i];
            result.push_back(st);
        }
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

    for (int i = 0; i < musicinfos.size(); i++) {

        string music = musicinfos[i];

        string startTime, finishTime, name, melody;
        
        startTime = music.substr(0, music.find(","));
        music = music.substr(music.find(",") + 1);
        finishTime = music.substr(0, music.find(","));
        music = music.substr(music.find(",") + 1);
        name = music.substr(0, music.find(","));
        melody = music.substr(music.find(",") + 1);

        vector<string> changedMelody = changeMelody(melody);
        int melodySize = changedMelody.size();
        int runTime = time_to_min(finishTime) - time_to_min(startTime);

        string runMelody = "";

        for (int j = 0; j < runTime; j++) {
            runMelody += changedMelody[j % melodySize];
        }

        timeMap[i] = runTime;
        nameMap[i] = name;
        melodyMap[i] = runMelody;
    }

    vector<pair<int, int>> containedSong;

    for (auto a : melodyMap) {
        int findIndex = a.second.find(m);
        if (0 <= findIndex && findIndex <= a.second.length() - 1)
            containedSong.push_back(make_pair<int,int>((int)a.first, (int)timeMap[a.first]));
    }

    sort(containedSong.begin(), containedSong.end(), comp);

    answer = nameMap[containedSong[0].first];

    return answer;
}

namespace KakaoBlind2018 {

    namespace problem22 {

        void execute() {

            string m = "ABCDEFG";
            vector<string> v;

            v.push_back("12:00,12:14,HELLO,CDEFGAB");
            v.push_back("13:00,13:05,WORLD,ABCDEF");

            cout << solution(m, v) << endl;
        }
    }
}