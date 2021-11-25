#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using iter = vector<int>::iterator;

class Node {
public:
    int m_val;
    Node *lchild{}, *rchild{};

    explicit Node(int val);
};

Node::Node(int val) : m_val(val) {}

//返回由 [LVR_begin, LVR_end) 构建的二叉树的根结点；LT 是层序，LVR 是中序
Node *createBiTreeByLTAndLVR(const vector<int> &LT, iter LVR_begin, iter LVR_end) { //在分析时，将整个二叉树分解成只有根结点和左右孩子的最小子树
    Node *root{};
    if (LVR_begin < LVR_end) {
        iter LVR_root;
        for (int i: LT) {
            if ((LVR_root = find(LVR_begin, LVR_end, i)) != LVR_end) { //遍历层序，第一个属于该子树的结点就是该子树的根结点
                break;
            }
        }
        root = new Node(*LVR_root);
        root->lchild = createBiTreeByLTAndLVR(LT, LVR_begin, LVR_root);
        root->rchild = createBiTreeByLTAndLVR(LT, LVR_root + 1, LVR_end);
    }
    return root;
}

void printLeaf(Node *node) {
    if (node) {
        if (!node->lchild && !node->rchild) {
            cout << node->m_val << " ";
        } else {
            printLeaf(node->lchild);
            printLeaf(node->rchild);
        }
    }
}

void PreOrderTraverse(Node *node) {
    if (node) {
        cout << node->m_val << " ";
        PreOrderTraverse(node->lchild);
        PreOrderTraverse(node->rchild);
    }
}

void PostOrderTraverse(Node *node) {
    if (node) {
        PostOrderTraverse(node->lchild);
        PostOrderTraverse(node->rchild);
        cout << node->m_val << " ";
    }
}

int main() {
    vector<int> LT;  //层次遍历序列
    vector<int> LVR; //中序遍历序列
    //输入层次和中序序列
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        LT.push_back(temp);
    }
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        LVR.push_back(temp);
    }
    Node *root = createBiTreeByLTAndLVR(LT, LVR.begin(), LVR.end());
    printLeaf(root);
    cout << endl;
    PreOrderTraverse(root);
    cout << endl;
    PostOrderTraverse(root);
}