#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> seq;
    for (int i = 1; i <= n; ++i) {
        int pop;
        cin >> pop;
        seq.push(pop);
    }
    stack<int> stk;
    int push = 1; //尚未被 push 的数
    while (!seq.empty()) {
        if (!stk.empty() && stk.top() == seq.front()) {
            stk.pop();
            seq.pop();
        } else {
            if (push > n) { //如果所有数都被 push 且依然无法满足要求，输出 no。
                cout << "no";
                return 0;
            }
            stk.push(push++);
        }
    }
    cout << "yes";
}