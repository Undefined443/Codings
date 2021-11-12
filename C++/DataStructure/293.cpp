#pragma GCC diagnostic error "-std=c++14"

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        return 0;
    }
    queue<int> que;
    for (int i = 1; i <= n; ++i) {
        que.push(i);
    }
    int front;
    while (que.size() > 3) {
        auto len = que.size();
        for (int i = 1; i <= len; ++i) {
            if (i % 2 == 0) {
                que.pop();
            } else {
                front = que.front();
                que.pop();
                que.push(front);
            }
        }
        if (que.size() <= 3) break;
        len = que.size();
        for (int i = 1; i <= len; ++i) {
            if (i % 3 == 0) {
                que.pop();
            } else {
                front = que.front();
                que.pop();
                que.push(front);
            }
        }
    }
    //调整队头
    while ((front = que.front()) != 1) {
        que.pop();
        que.push(front);
    }
    auto len = que.size();
    for (int i = 0; i < len; ++i) {
        cout << que.front() << " ";
        que.pop();
    }
}