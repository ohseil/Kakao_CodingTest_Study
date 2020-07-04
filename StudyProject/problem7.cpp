#include "problem7.h"

// Trie 자료구조를 이용한 풀이.
class SI_Trie {

public:

	class Node {

	public:
		char data;
		vector<Node*> nextList;
        map<int, int> m;

		Node(char ch) { data = ch; }
	};

	SI_Trie() {
		head = new Node(NULL);
	};

	void insert(string str, int length) {

		Node* node = head;
        node->m[length] += 1;

        for (int i = 0; i < str.length(); i++) {

			bool isData = false;

            for (Node* n : node->nextList) {
				if (n->data == str[i]) {
					node = n;
                    node->m[length] += 1;
					isData = true;
					break;
				}
			}

			if (isData == false) {
				
                Node* input = new Node(str[i]);
                input->m[length] += 1;
				
                node->nextList.push_back(input);
				node = input;
			}
		}
	};

	int findNum(string str, int length) {

        Node* node = head;

        for (char ch : str) {

            if (ch == '?') {
                return node->m[length];
            }
            else {

                bool isData = false;

                for (Node* n : node->nextList) {
                    if (ch == n->data) {
                        node = n;
                        isData = true;
                        break;
                    }
                }

                if (isData == false) {
                    return 0;
                }
            }

		}
	}

private:

    Node* head;

};

vector<int> solution(vector<string> words, vector<string> queries) {

    vector<int> answer;

    SI_Trie trie, rtrie;

    for (string word : words) {
        trie.insert(word, word.length());
        reverse(word.begin(), word.end());
        rtrie.insert(word, word.length());
    }

    for (string query : queries) {
        if (query[0] == '?') {
            reverse(query.begin(), query.end());
            answer.push_back(rtrie.findNum(query, query.length()));
        }
        else {
            answer.push_back(trie.findNum(query, query.length()));
        }
    }

    return answer;
}

/*
// 이분탐색을 이용한 풀이
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
}*/

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

    vector<int> aw = solution(w, q);
 
    for (auto a : aw)
        cout << a << " ";
}