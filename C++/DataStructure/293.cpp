#pragma GCC diagnostic error "-std=c++14"

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> que;
    for (int i = 1; i <= n; ++i) {
        que.push(i);
    }
    int front;
    while (que.size() > 3) {
        auto len = que.size();
        for (int i = 1; i <= len && que.size() > 3; ++i) {
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
        for (int i = 1; i <= len && que.size() > 3; ++i) {
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
    for (int i = 0; i < (n < 3 ? n : 3); ++i) {
        cout << que.front() << " ";
        que.pop();
    }
}