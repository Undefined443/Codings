#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int len;
        cin >> len;
        vector<int> nums;
        set<int> num_set;
        for (int j = 0; j < len; ++j) {
            int temp;
            cin >> temp;
            nums.push_back(temp);
            num_set.insert(temp);
        }
        using count = map<int, int>; //每个组中使用的元素计数表
        map<int, count> groups;
        for (int j = 0; j < len; ++j) {
            int group;
            cin >> group;
            int num = nums[j];
            ++groups[group][num];
        }
        for (auto &group: groups) {
            cout << group.first << "={";
            bool flag = false;
            for (int num: num_set) {
                if (flag) {
                    cout << ",";
                }
                cout << num << "=" << group.second[num];
                flag = true;
            }
            cout << "}" << endl;
        }
    }
}