#include "problem12.h"

namespace KakaoBlind2019 {

	namespace problem12 {

		class Node {

		public:

			int number = 0; // 노드 번호
			int x = 0;
			int y = 0;

			Node* left = nullptr;
			Node* right = nullptr;

			Node(int number, int x, int y)
				: number(number), x(x), y(y) {

			}
		};

		class NodeTree {

		public:

			Node* root = nullptr;

			NodeTree(Node* node) {
				root = node;
			}

			// 삽입
			void insert(Node* node) {

				// 삽입 전 노드 데이터 배열이 y값 기준으로 내림차순 정렬한 상태이므로,
				// y값은 고려할 필요가 없다.
				// x값만 비교 후 삽입 또는 노드 이동(비어있는 노드에 도착할 때까지).

				Node** n = &root;

				while ((*n) != nullptr) {

					if ((*n)->x < node->x)
						n = &(*n)->right;
					else
						n = &(*n)->left;
				}
				*n = node;

			}

			// 전위순회
			vector<int> preorder() {

				vector<int> result;

				stack<Node*> st;
				map<int, int> m; // 한번 들렀던 곳을 확인하기 위한 맵.

				st.push(root);
				m[root->number] = 1;

				result.push_back(root->number);

				while (!st.empty()) {

					Node* n = st.top();

					if (n->left != nullptr && m[n->left->number] != 1) {
						st.push(n->left);
						m[n->left->number] = 1;
						result.push_back(n->left->number);
					}
					else if (n->right != nullptr && m[n->right->number] != 1) {
						st.push(n->right);
						m[n->right->number] = 1;
						result.push_back(n->right->number);
					}
					else {
						st.pop();
					}
				}

				return result;
			}

			// 후위순회
			vector<int> postorder() {

				vector<int> result;

				stack<Node*> st;
				map<int, int> m;

				st.push(root);
				m[root->number] = 1;

				while (!st.empty()) {

					Node* n = st.top();

					if (n->left != nullptr && m[n->left->number] != 1) {
						st.push(n->left);
						m[n->left->number] = 1;
					}
					else if (n->right != nullptr && m[n->right->number] != 1) {
						st.push(n->right);
						m[n->right->number] = 1;
					}
					else {
						st.pop();
						result.push_back(n->number);
					}
				}

				return result;
			}
		};

		bool comp(vector<int> lhs, vector<int> rhs) {
			if (lhs[1] <= rhs[1])
				return false;
			return true;
		}

		vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

			vector<vector<int>> answer;

			// 3번째 index에 노드번호 추가.
			for (int i = 0; i < nodeinfo.size(); i++)
				nodeinfo[i].push_back(i + 1);

			// y값 내림차순으로 정렬
			sort(nodeinfo.begin(), nodeinfo.end(), comp);

			// 트리 생성
			NodeTree nt(new Node(nodeinfo[0][2], nodeinfo[0][0], nodeinfo[0][1]));

			// 트리에 노드 삽입.
			for (int i = 1; i < nodeinfo.size(); i++)
				nt.insert(new Node(nodeinfo[i][2], nodeinfo[i][0], nodeinfo[i][1]));

			// 전위순회, 후위순회 결과값 입력.
			answer.push_back(nt.preorder());
			answer.push_back(nt.postorder());

			return answer;
		}

		void execute() {

			vector<vector<int>> v;
			vector<int> vv;
			vv.push_back(5); vv.push_back(3);
			v.push_back(vv);
			vv[0] = 11; vv[1] = 5;
			v.push_back(vv);
			vv[0] = 13; vv[1] = 3;
			v.push_back(vv);
			vv[0] = 3; vv[1] = 5;
			v.push_back(vv);
			vv[0] = 6; vv[1] = 1;
			v.push_back(vv);
			vv[0] = 1; vv[1] = 3;
			v.push_back(vv);
			vv[0] = 8; vv[1] = 6;
			v.push_back(vv);
			vv[0] = 7; vv[1] = 2;
			v.push_back(vv);
			vv[0] = 2; vv[1] = 2;
			v.push_back(vv);

			vector<vector<int>> an = solution(v);

			for (auto a : an) {
				for (auto aa : a)
					cout << aa << " ";
				cout << endl;
			}

			/*Node* nn = new Node(1, 1, 1);
			Node* nn1 = new Node(2, 2, 2);
			Node** nn2 = &nn->left;
			*nn2 = nn1;

			cout << nn->left->number << endl;*/
		}

	}

}

