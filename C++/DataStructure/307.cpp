#pragma GCC diagnostic error "-std=c++14"

#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    stack<char> stk;
    bool flag = true;
    for (char c: str) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stk.empty() || (stk.top() != c - 1 && stk.top() != c - 2)) { //一定要注意 stack.empty() 的情况
                cout << "wrong" << endl;
                flag = false;
                return 0;
            }
            stk.pop();
        }
    }
    if (flag && stk.empty()) {
        cout << "right" << endl;
    } else {
        cout << "wrong" << endl;
    }

}