#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n) {
        vector<int> vec;
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            vec.push_back(temp);
        }
        int depth;
        cin >> depth;
        int begin = (int) exp2(depth - 1) - 1;
        int end = 2 * begin + 1;
        bool isPrinted = false;

        for (auto i = begin; i < end && i < vec.size(); ++i) {
            cout << vec[i] << " ";
            isPrinted = true;
        }
        if (!isPrinted) {
            cout << "EMPTY";
        }
        cout << endl;
        cin >> n;
    }
}