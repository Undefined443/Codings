#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <cmath>

using namespace std;

unsigned calc(unsigned m, unsigned n) {
    auto m_layer = (unsigned) log2(m);           //计算 m 在二叉树的第几层。从 0 开始计数
    auto n_layer = (unsigned) log2(n);           //计算 n 在二叉树的第几层
    unsigned depth = n_layer - m_layer;          // m 子树的深度（平凡树的深度为 0）
    unsigned ans = (unsigned) exp2(depth) - 1;   //在 m 子树中，n 所在层上面有多少元素
    unsigned front = m * (unsigned) exp2(depth); //在 m 子树中，n 所在层的第一个元素的索引值
    ans += (n >= front) ? n - front + 1 : 0;
    unsigned back = front + (front / m) - 1;     //在 m 子树中，n 所在层的最后一个元素的索引值。(front / m) 是 n 所在行的元素数
    ans -= (n >= back) ? n - back : 0;
    return ans;
}

int main() {
    unsigned m, n;
    cin >> m >> n;
    while (!((m == 0) && (n == 0))) {
        cout << calc(m, n) << endl;
        cin >> m >> n;
    }
}