#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Node {
    int val;
    Node *lChild{};
    Node *rChild{};

public:
    explicit Node(int i);

    ~Node();

    void addNode(int i);

    friend void PreOrderTraverse(const Node *node);

    friend void InOrderTraverse(const Node *node);

    friend void PostOrderTraverse(const Node *node);
};

Node::Node(int i) : val(i) {}

Node::~Node() {
    delete lChild;
    delete rChild;
}

void Node::addNode(int i) {
    if (i < val) {
        if (lChild) {
            lChild->addNode(i);
        } else {
            lChild = new Node(i);
        }
    } else if (i > val) {
        if (rChild) {
            rChild->addNode(i);
        } else {
            rChild = new Node(i);
        }
    }
}

void PreOrderTraverse(const Node *node) {
    if (node) {
        cout << node->val << " ";
        PreOrderTraverse(node->lChild);
        PreOrderTraverse(node->rChild);
    }
}

void InOrderTraverse(const Node *node) {
    if (node) {
        InOrderTraverse(node->lChild);
        cout << node->val << " ";
        InOrderTraverse(node->rChild);
    }
}

void PostOrderTraverse(const Node *node) {
    if (node) {
        PostOrderTraverse(node->lChild);
        PostOrderTraverse(node->rChild);
        cout << node->val << " ";
    }
}

Node *createTree(int n) {
    Node *root;
    int x;
    cin >> x;
    root = new Node(x);
    for (int i = 1; i < n; ++i) {
        cin >> x;
        root->addNode(x);
    }
    return root;
}

int main() {
    int n;
    cin >> n;
    auto root = createTree(n);
    PreOrderTraverse(root);
    cout << endl;
    InOrderTraverse(root);
    cout << endl;
    PostOrderTraverse(root);
    cout << endl;
}