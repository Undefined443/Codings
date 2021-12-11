#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int **Tree;

bool checkTree(int root) {
    if (root != -1) {
        int lChild = Tree[root][1];
        int rChild = Tree[root][2];
        if (lChild != -1 && Tree[root][0] < Tree[lChild][0]) {
            return false;
        } else if (rChild != -1 && Tree[root][0] > Tree[rChild][0]) {
            return false;
        } else if (checkTree(lChild) && checkTree(rChild)) {
            return true;
        }
    }
    return true;
}

int main() {
    int n, r;
    cin >> n >> r;
    --r;
    Tree = new int *[n];
    for (int i = 0; i < n; ++i) {
        Tree[i] = new int[3];
    }
    for (int i = 0; i < n; ++i) {
        cin >> Tree[i][0] >> Tree[i][1] >> Tree[i][2];
        --Tree[i][1];
        --Tree[i][2];
    }
    cout << (checkTree(r) ? "true" : "false");
}