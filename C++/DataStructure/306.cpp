#pragma GCC diagnostic error "-std=c++14"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>
#include <cstdlib>

using namespace std;

int main() {
    string str;
    cin >> str;
    stack<int> stk;
    for (const char &it: str) {
        if (isdigit(it)) {
            stk.push(it - '0');
        } else {
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();
            switch (it) {
                case '+':
                    stk.push(a + b);
                    break;
                case '-':
                    stk.push(a - b);
                    break;
                case '*':
                    stk.push(a * b);
                    break;
                case '/':
                    stk.push(a / b);
                    break;
            }
        }
    }
    cout << stk.top();
}