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

        // 1. y �˻�.
        // y�� �����庸�� �Է³�尡 Ŭ ���, ���� ����ڸ��� ����
        
        // ������ �� x�� ���� �����带 �Է³���� ����� �ڽĿ� �����Ұ��� Ȯ���ϰ� ����.
        // �������� �θ��带 �Է³���� �θ�� �ٲٰ� �����带 �Է³��� �ٲٰ� �Է³���� �ڽ����� ������ ����.

        // y�� ���� ���, x�� ���� ���� ����� �����ڽ����� ������ �ڽ����� Ȯ��.
        // �ڽ� �ڸ��� ��尡 ���� ��� �ش� ���� �̵�.
        // �ڽ� �ڸ��� ��尡 ���� ��� �ش� ��� �ڸ��� ����.
        
        bool isInput = false;
        
        while (isInput == false) {

            if (n->y < node->y) {
                // ����

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
                        // ����

                        isInput = true;
                    }
                    else {
                        // ����̵�
                    }
                }
                else {
                    if (n->left == nullptr) {
                        // ����

                        isInput = true;
                    }
                    else {
                        // ����̵�
                    }
                }
            }
        }
    }

    // ������ȸ
    void preorder() {

    }

    // ������ȸ
    void postorder() {

    }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    vector<vector<int>> answer;
    
    return answer;
}

void KakaoBlind2019::problem12::execute() {

}