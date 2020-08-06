#include "problem24.h"

namespace KakaoBlind2018 {

	namespace problem24 {

		class SI_Trie {

		public:

			class Node {

			public:

				char ch = NULL; // �ش� ����� ����
				int stringNum = 1; // �ش� ��带 ���� ����� ���ڿ��� �� ����.
				vector<Node*> children; // �ڽ� ��� ����

				Node() {}

				Node(char ch) { this->ch = ch; }

			};

			// root node init.
			Node* root = new Node();

			void insert(string str, int length) {

				Node* node = root;

				// ���ڿ��� �� ���� ����.
				for (int i = 0; i < length; i++) {

					char inputCh = str[i];
					bool isChar = false;

					for (Node* n : node->children) {
						if (n->ch == inputCh) {
							node = n;
							node->stringNum++; // �ش� ���ڸ� �����Ͽ� �Էµ� ���ڿ� ���� ++
							isChar = true;
							break;
						}
					}

					// ���ڰ� �ԷµǾ� ���� ���� ��� �� node �߰�.
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

					// ���ڿ��� �����ڱ��� �˻��Ѵٸ� ��� ���ڸ� Ÿ���� �ؾ��Ѵ�.
					if (i == length - 1)
						return length;

					char findCh = str[i];

					for (Node* n : node->children) {
						if (n->ch == findCh) {
							node = n;

							// �ش� ��带 ������ ���ڿ��� 1�����,
							// ���̻� �˻��� �ʿ䰡 ����.
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

			// �ڷᱸ�� Trie
			SI_Trie trie;

			// Trie ���ڿ� ����
			for (string word : words)
				trie.insert(word, word.length());

			// Trie ���ڿ� �˻�
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