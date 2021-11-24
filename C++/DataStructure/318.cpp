#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Node {
public:
    char index;
    Node *lchild{}, *rchild{};
    bool isLAssigned = false;
    bool isRAssigned = false;

    explicit Node(char c);
};

Node::Node(char c) : index(c) {}

void PostOrderTraverse(Node *node) {
    if (node) {
        PostOrderTraverse(node->lchild);
        PostOrderTraverse(node->rchild);
        cout << node->index;
    }
}

Node *createTree_VLRandLVR(const string &VLR, string LVR) {
    Node *root{};
    stack<Node *> stk;
    for (char i: VLR) {
        Node *node = new Node(i);
        string::size_type c = LVR.find(i);
        //判断当前结点是否有左右孩子
        if (c == 0 || LVR[c - 1] == CHAR_MAX) {
            node->isLAssigned = true;
        }
        if (c + 1 >= LVR.size() || LVR[c + 1] == CHAR_MAX) {
            node->isRAssigned = true;
        }
        if (!root) {
            root = node;
            stk.push(node);
            LVR[c] = CHAR_MAX;
            continue;
        }
        //处理当前结点和父节点的关系
        auto top = stk.top();
        while (top->isLAssigned && top->isRAssigned) {
            stk.pop();
            top = stk.top();
        }
        if (!top->isLAssigned) {
            top->lchild = node;
            top->isLAssigned = true;
        } else {
            top->rchild = node;
            top->isRAssigned = true;
        }
        stk.push(node);
        LVR[c] = CHAR_MAX;
    }
    return root;
}

int main() {
    string VLR; //先序序列
    string LVR; //中序序列
    cin >> VLR >> LVR;
    Node *root = createTree_VLRandLVR(VLR, LVR);
    PostOrderTraverse(root);
}