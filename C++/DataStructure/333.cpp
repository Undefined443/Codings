#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;
    map<char, int> count;
    map<char, vector<int>> loc;
    auto size = str.size();
    for (int i = 0; i < size; ++i) {
        char c = str[i];
        ++count[c];
        loc[c].push_back(i);
    }
    map<char, bool> printed;
    for (char i : str) {
        if (count[i] > 1 && !printed[i]) {
            printed[i] = true;
            bool flag = false;
            for (auto j : loc[i]) {
                if (flag) {
                    cout << ",";
                }
                cout << i << ":" << j;
                flag = true;
            }
            cout << endl;
        }
    }

}