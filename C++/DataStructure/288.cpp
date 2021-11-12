#pragma GCC diagnostic error "-std=c++14"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> charVec;
    for (int i = 0; i < n; ++i) {
        char input;
        cin >> input;
        charVec.push_back(input);
    }
    vector<int> next;
    next.push_back(-1);
    auto len = charVec.size();
    int k = -1;
    int j = 0;
    while (j < len - 1) {
        //str[k] 表示前缀之后，str[j] 表示后缀之后。
        if (k == -1 || charVec[j] == charVec[k]) { //前缀之后和后缀之后相等，说明相等前后缀可以延长 1 位。
            ++j;
            ++k;
            //这里加一个判断
//            if (charVec[j] != charVec[k]) {
                next.push_back(k);
//            } else { //在匹配时，如果后缀之后失配，那么就让前缀之后再次与之尝试匹配。因此如果前缀之后和后缀之后相等，就一定再次失配。因此这里直接递归 k 的值。
//                next.push_back(next[k]);
//            }
        } else {
            k = next[k];
        }
    }
    for (int i : next) {
        cout << i << " ";
    }
}