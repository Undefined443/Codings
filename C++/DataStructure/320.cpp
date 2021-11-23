#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> LT;  //层次遍历序列
    vector<int> LVR; //中序遍历序列
    //输入层次和中序序列
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        LT.push_back(temp);
    }
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        LVR.push_back(temp);
    }
    
}