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

    friend void PreOrderTraverse(const Node *node, vector<int> &order);
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
    } else {
        if (rChild) {
            rChild->addNode(i);
        } else {
            rChild = new Node(i);
        }
    }
}

void PreOrderTraverse(const Node *node, vector<int> &order) {
    if (node) {
        order.push_back(node->val);
        PreOrderTraverse(node->lChild, order);
        PreOrderTraverse(node->rChild, order);
    }
}

Node *createTree() {
    Node *root;
    string order;
    getline(cin, order);
    auto size = order.size();
    root = new Node(order[0] - '0');
    for (int i = 1; i < size; ++i) {
        root->addNode(order[i] - '0');
    }
    return root;
}

int main() {
    int n;
    cin >> n;
    getchar();
    while (n) {
        auto tar_root = createTree();
        vector<int> tar_order;
        PreOrderTraverse(tar_root, tar_order);
        for (int i = 0; i < n; ++i) {
            auto root = createTree();
            vector<int> order;
            PreOrderTraverse(root, order);
            if (tar_order == order) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            delete root;
        }
        delete tar_root;
        cin >> n;
        getchar();
    }
}