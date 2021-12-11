#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <map>

using namespace std;

class Node {
    int val;
    Node *lChild{};
    Node *rChild{};

public:
    explicit Node(int i);

    ~Node();

    friend void addNode();
};

Node::Node(int i) : val(i) {}

Node::~Node() {
    delete lChild;
    delete rChild;
}

bool flag;

map<int, Node*> nodeMap;

Node *findNode(int i) {
    if (!nodeMap.at(i)) {
        nodeMap[i] = new Node(i);
    }
    return nodeMap[i];
}

void addNode() {
    int index, lChild, rChild;
    cin >> index >> lChild >> rChild;

    if (index < lChild || index > rChild) {
        flag = false;
    }

    auto root = findNode(index);
    if (lChild) {
        auto root_lChild = findNode(lChild);
        root->lChild = root_lChild;
    }
    if (rChild) {
        auto root_rChild = findNode(rChild);
        root->rChild = root_rChild;
    }
}

