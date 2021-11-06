#pragma GCC diagnostic error "-std=c++14"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    n += m;
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    auto end = unique(vec.begin(), vec.end());
    for (auto i = vec.begin(); i != end; ++i) {
        cout << *i << " ";
    }
}