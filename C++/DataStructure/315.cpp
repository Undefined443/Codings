#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Node {
public:
    char m_val;
    Node *lchild = NULL;
    Node *rchild = NULL;
    bool isLAssigned = false;
    bool isRAssigned = false;

    explicit Node(int val);
};

Node::Node(int val) : m_val(val) {}

Node *createNode(char c);

void InOrderTraverse(Node *n);

int main() {
    string str;
    cin >> str;
    Node *root = NULL;
    Node *cur = NULL;
    stack<Node *> nodeStack;
    for (char i: str) {
        if (!cur) {
            Node *newNode = new Node(i);
            root = newNode;
            cur = newNode;
            continue;
        }
        while (cur->isLAssigned && cur->isRAssigned) {
            cur = nodeStack.top();
            nodeStack.pop();
        }
        if (!cur->isLAssigned) {
            cur->isLAssigned = true;
            cur->lchild = createNode(i);
            if (cur->lchild) {
                nodeStack.push(cur);
                cur = cur->lchild;
            }
        } else if (!cur->isRAssigned) {
            cur->isRAssigned = true;
            cur->rchild = createNode(i);
            if (cur->rchild) {
                nodeStack.push(cur);
                cur = cur->rchild;
            }
        }
    }
    InOrderTraverse(root);
}

Node *createNode(char c) {
    if (c != '#') {
        return new Node(c);
    }
    return NULL;
}

void InOrderTraverse(Node *n) {
    if (n) {
        InOrderTraverse(n->lchild);
        cout << n->m_val << " ";
        InOrderTraverse(n->rchild);
    }
}