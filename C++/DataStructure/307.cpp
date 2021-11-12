#pragma GCC diagnostic error "-std=c++14"

#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<char> stk;
    string str;
    cin >> str;
    bool flag = true;
    for (char c: str) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        }
        if (c == ')' || c == ']' || c == '}') {
            if (stk.top() != c - 1 && stk.top() != c - 2) {
                cout << "wrong";
                flag = false;
                break;
            }
            stk.pop();
        }
    }
    if (flag) {
        cout << "right";
    }
}