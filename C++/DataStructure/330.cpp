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

    int addNode(int i);
};

Node::Node(int i) : val(i) {}

Node::~Node() {
    delete lChild;
    delete rChild;
}

int Node::addNode(int i) {
    if (i < val) {
        if (lChild) {
            return lChild->addNode(i);
        } else {
            lChild = new Node(i);
            return val;
        }
    } else {
        if (rChild) {
            return rChild->addNode(i);
        } else {
            rChild = new Node(i);
            return val;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int j;
    cin >> j;
    auto root = new Node(j);
    cout << -1 << endl;
    for (int i = 1; i < n; ++i) {
        cin >> j;
        cout << root->addNode(j) << endl;
    }
}