#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <string>
#include <stack>

using namespace std;

using size_type = string::size_type;

class Node {
public:
    char index;
    Node *lchild{}, *rchild{};

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

//返回由 [LVR_begin, LVR_end) 构建的二叉树的根结点；VLR 是先序，LVR 是中序
Node *createBiTreeByLTAndLVR(const string &VLR, const string &LVR, size_type LVR_begin, size_type LVR_end) {
    static size_type i;
    Node *root{};
    if (LVR_begin < LVR_end) {
        root = new Node(VLR[i++]); //先序的首结点为根结点
        auto LVR_root = LVR.find(root->index); //在中序中定位根结点
        root->lchild = createBiTreeByLTAndLVR(VLR, LVR, LVR_begin, LVR_root);
        root->rchild = createBiTreeByLTAndLVR(VLR, LVR, LVR_root + 1, LVR_end);
    }
    return root;
}

int main() {
    string VLR; //先序序列
    string LVR; //中序序列
    cin >> VLR >> LVR;
    Node *root = createBiTreeByLTAndLVR(VLR, LVR, 0, LVR.size());
    PostOrderTraverse(root);
}