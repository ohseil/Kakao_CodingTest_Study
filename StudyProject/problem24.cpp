#include "problem24.h"

namespace KakaoBlind2018 {

	namespace problem24 {

		class SI_Trie {

		public:

			class Node {

			public:

				char ch = NULL; // 해당 노드의 문자
				int stringNum = 1; // 해당 노드를 거쳐 저장된 문자열의 총 개수.
				vector<Node*> children; // 자식 노드 벡터

				Node() {}

				Node(char ch) { this->ch = ch; }

			};

			// root node init.
			Node* root = new Node();

			void insert(string str, int length) {

				Node* node = root;

				// 문자열의 각 문자 삽입.
				for (int i = 0; i < length; i++) {

					char inputCh = str[i];
					bool isChar = false;

					for (Node* n : node->children) {
						if (n->ch == inputCh) {
							node = n;
							node->stringNum++; // 해당 문자를 포함하여 입력된 문자열 개수 ++
							isChar = true;
							break;
						}
					}

					// 문자가 입력되어 있지 않은 경우 새 node 추가.
					if (isChar == false) {
						Node* inputNode = new Node(inputCh);
						node->children.push_back(inputNode);
						node = inputNode;
					}
				}
			}

			int find(string str, int length) {

				Node* node = root;

				for (int i = 0; i < length; i++) {

					// 문자열의 끝문자까지 검색한다면 모든 문자를 타이핑 해야한다.
					if (i == length - 1)
						return length;

					char findCh = str[i];

					for (Node* n : node->children) {
						if (n->ch == findCh) {
							node = n;

							// 해당 노드를 포함한 문자열이 1개라면,
							// 더이상 검색할 필요가 없다.
							if (node->stringNum == 1)
								return i + 1;
							break;
						}
					}
				}

				return -1;
			}
		};

		int solution(vector<string> words) {

			int answer = 0;

			// 자료구조 Trie
			SI_Trie trie;

			// Trie 문자열 삽입
			for (string word : words)
				trie.insert(word, word.length());

			// Trie 문자열 검색
			for (string word : words)
				answer += trie.find(word, word.length());

			return answer;
		}

		void execute() {

			vector<string> v;
			v.push_back("go");

			v.push_back("gone");
			v.push_back("guild");

			cout << solution(v) << endl;
		}
	}
}