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

// string�� �ð� -> int�� ������ ��ȯ�ϴ� �Լ�.
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