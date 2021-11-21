#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <cmath>

using namespace std;

int calc(unsigned m, unsigned n) {
    unsigned m_layer = log2(m); //计算 m 在二叉树的第几层。从 0 开始计数
    unsigned n_layer = log2(n); //计算 n 在二叉树的第几层。
    unsigned depth = n_layer - m_layer; //m 所在的子树的深度（这里平凡树的深度为 0）
    unsigned bottom = exp2(depth - 1); 的上一层有多少元素
    unsigned ans = exp2(depth) - 1; //在 m 子树中，n 所在层上面有多少元素
    int front = m * exp2(depth);
    ans += (n >= front) ? n - front + 1 : 0;
    return ans;
}

int main() {
    unsigned m, n;
    do {
        cin >> m >> n;
        cout << calc(m, n) << endl;
    } while (!((m == 0) && (n == 0)));
}