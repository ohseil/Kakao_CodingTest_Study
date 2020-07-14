#include "problem12.h"

class NodeTree {

private:

    class Node {

    public:
        int number = 0;
        int x = 0;
        int y = 0;
        Node* parent = nullptr;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(int number, int x, int y, Node* parent, Node* left, Node* right)
        : number(number), x(x), y(y), parent(parent), left(left), right(right) {

        }
    };

public:

    Node* root = nullptr;

    NodeTree(Node* node) {
        root = node;
    }

    void insert(Node* node) {

        Node* n = root;

        // 1. y 검사.
        // y가 현재노드보다 입력노드가 클 경우, 현재 노드자리에 삽입
        
        // 삽입할 때 x를 보고 현재노드를 입력노드의 어느쪽 자식에 삽입할건지 확인하고 삽입.
        // 현재노드의 부모노드를 입력노드의 부모로 바꾸고 현재노드를 입력노드로 바꾸고 입력노드의 자식으로 현재노드 삽입.

        // y가 작을 경우, x를 보고 현재 노드의 왼쪽자식인지 오른쪽 자식인지 확인.
        // 자식 자리에 노드가 있을 경우 해당 노드로 이동.
        // 자식 자리에 노드가 없을 경우 해당 노드 자리에 삽입.
        
        bool isInput = false;
        
        while (isInput == false) {

            if (n->y < node->y) {
                // 삽입

                if (n->x < node->x) {
                    Node* temp = n;
                    node->left = temp;
                    node->parent = temp->parent;
                    temp->parent = node;
                    //node->parent->
                    //n = node;
                }
                else {

                }

                isInput = true;
            }
            else {
                if (n->x < node->x) {
                    if (n->right == nullptr) {
                        // 삽입

                        isInput = true;
                    }
                    else {
                        // 노드이동
                    }
                }
                else {
                    if (n->left == nullptr) {
                        // 삽입

                        isInput = true;
                    }
                    else {
                        // 노드이동
                    }
                }
            }
        }
    }

    // 전위순회
    void preorder() {

    }

    // 후위순회
    void postorder() {

    }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    vector<vector<int>> answer;
    
    return answer;
}

void KakaoBlind2019::problem12::execute() {

}