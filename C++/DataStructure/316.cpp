#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int i, j;
    cin >> i >> j;
    while (i || j) {
        vector<int> ivec, jvec;
        while (i >= 1) {
            ivec.push_back(i);
            i /= 2;
        }
        while (j >= 1) {
            jvec.push_back(j);
            j /= 2;
        }
        auto iit = ivec.rbegin(), jit = jvec.rbegin();
        for (; iit < ivec.rend() && jit < jvec.rend(); ++iit, ++jit) {
            if (*iit != *jit) {
                break;
            }
        }
        cout << *--iit << endl;
        cin >> i >> j;
    }
}