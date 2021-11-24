#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ToSumTree(vector<int>::iterator beg,
              vector<int>::iterator end) { //输入满二叉子树的中序序列 [beg, end)；函数将 mid 置为 mid 左右子树之和，并返回原 mid 子树的和
    if (beg == end - 1) { //如果 mid 没有左右孩子，那么其左右子树之和为 0。mid 子树的和就是 mid 自身
        int val = *beg;
        *beg = 0;
        return val;
    }
    auto mid = beg + (end - beg) / 2;
    int val = *mid;
    *mid = ToSumTree(beg, mid) + ToSumTree(mid + 1, end);
    return val + *mid;
}

int main() {
    int n;
    cin >> n;
    //满二叉树，只需中序就可还原出二叉树，无需提供先序序列。这是本题的 bug，这里把先序忽略掉
    string unused;
    getline(cin, unused); //先把换行读掉
    getline(cin, unused); //输入了但是不用
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    ToSumTree(vec.begin(), vec.end());
    for (int i: vec) {
        cout << i << " ";
    }
}