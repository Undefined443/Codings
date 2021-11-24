#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using iter = vector<int>::iterator;

class Node {
public:
    int m_val;
    Node *lchild, *rchild;
    
    Node(int val);
};

Node::Node(int val) : m_val(val) {}

//在分析时，将整个二叉树分解成只有根结点和左右孩子的最小子树
Node *createBiTreeByLTAndLVR(iter LT_begin, iter LT_end, iter LVR_begin, iter LVR_end) { //返回由 [LVR_begin, LVR_end) 构建的二叉树的根结点；LT 是层序，LVR 是中序
    Node *root{};
    if (LVR_begin < LVR_end) {
      root = new Node(*LT_begin); //层序的首结点为根结点
      iter LVR_root = find(LVR_begin, LVR_end, root->m_val); //在中序中定位根结点
      root->lchild = createTreeByLTAndLVR(LT_begin + 1, LT_end, LVR_begin, LVR_root);
      root->rchild = createTreeByLTAndLVR(LT_begin + 2, LT_end, LVR_root + 1, LVR_end);
    }
    return root;
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
        PreOrderTraverse(node->lchild);
        PreOrderTraverse(node->rchild);
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
    Node *root = createBiTreeByLTAndLVR(LT.begin(), LT.end(), LVR.begin(), LVR.end());
    PreOrderTraverse(root);
    cout << endl;
    PostOrderTraverse(root);
}