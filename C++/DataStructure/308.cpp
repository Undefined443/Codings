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
    getline(cin, str);
    istringstream is(str);
    vector<string> svec;
    string temp;
    while (is >> temp) {
        svec.push_back(temp);
    }
    stack<int> stk;
    for (auto it = svec.rbegin(); it != svec.rend(); ++it) {
        if (isdigit((*it)[0])) {
            stk.push(atoi(it->c_str()));
        } else {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            switch ((*it)[0]) {
                case '+':
                    stk.push(a + b);
                    break;
                    //case '-':
                default: //不知道为什么 - 号对应的字符串是两个字符，(*it)[0] 解析不到 '-' 号。
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