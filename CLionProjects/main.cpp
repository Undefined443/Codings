#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <iterator>

using namespace std;
using namespace std::placeholders;

int main() {
    vector<int> ivec{1, 5, 7, 4, 86, 24, 25, 7654, 3, 46, 2356, 865, 4783, 7, 6, 6, 43, 8, 0, 4};
    sort(ivec.begin(), ivec.end());
    ostream_iterator<int> out_iter(cout, "\n");
    copy(ivec.cbegin(), ivec.cend(), out_iter);
}
