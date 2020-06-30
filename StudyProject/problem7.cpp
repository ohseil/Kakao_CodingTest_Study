#include "problem7.h"

bool Comp(string lhs, string rhs) {
    if (lhs.length() < rhs.length())
        return true;
    else if (lhs.length() == rhs.length())
        if (lhs < rhs)
            return true;
    return false;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    
    vector<int> answer;

    vector<string> rwords = words;
    for (int i = 0; i < rwords.size(); i++) reverse(rwords[i].begin(), rwords[i].end());
    
    sort(words.begin(), words.end(), Comp);
    sort(rwords.begin(), rwords.end(), Comp);

    for (auto query : queries) {

        vector<string>::iterator answerStart, answerEnd;

        if (query[0] == '?') {
            reverse(query.begin(), query.end());
 
            string queryA = query, queryZ = query;

            //int startIndex = query.find_first_of('?');
            for (int i = 0; i < query.size(); i++) {
                if (queryA[i] == '?') {
                    queryA[i] = 'a';
                    queryZ[i] = 'z';
                }
            }

            answerStart = lower_bound(rwords.begin(), rwords.end(), queryA, Comp);
            answerEnd = upper_bound(rwords.begin(), rwords.end(), queryZ, Comp);

        }
        else {

            string queryA = query, queryZ = query;

            //int startIndex = query.find_first_of('?');
            for (int i = 0; i < query.size(); i++) {
                if (queryA[i] == '?') {
                    queryA[i] = 'a';
                    queryZ[i] = 'z';
                }
            }

            answerStart = lower_bound(words.begin(), words.end(), queryA, Comp);
            answerEnd = upper_bound(words.begin(), words.end(), queryZ, Comp);
        }

        answer.push_back(answerEnd - answerStart);
    }

    return answer;
}


void changeV(vector<string> v) {
    for (int i = 0; i < v.size(); i++)
        v[i] = "a";
}

void KakaoBlind2020::problem7::execute() {

    vector<string> w, q;

    w.push_back("frodo");
    w.push_back("front");
    w.push_back("frost");
    w.push_back("frozen");
    w.push_back("frame");
    w.push_back("kakao");

    q.push_back("fro??");
    q.push_back("????o");
    q.push_back("fr???");
    q.push_back("fro???");
    q.push_back("pro?");

    //solution(w, q);
    changeV(w);

    for (string str : w)
        cout << str << " ";

    cout << endl;
}