#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int **Tree;

void InOrderTraverse(int root, vector<int> &order) {
    if (root != -1) {
        InOrderTraverse(Tree[root][1], order);
        order.push_back(Tree[root][0]);
        InOrderTraverse(Tree[root][2], order);
    }
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
    vector<int> order;
    InOrderTraverse(r, order);
    vector<int> sorted_order(order);
    sort(sorted_order.begin(), sorted_order.end());
    if (sorted_order == order) {
        cout << "true";
    } else {
        cout << "false";
    }
}