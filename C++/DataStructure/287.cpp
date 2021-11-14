#pragma GCC dignostic error "-std=c++14"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > Matrix(n, vector<int>(m));
    //输入矩阵
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int temp;
            cin >> temp;
            Matrix[i][j] = temp;
        }
    }
    bool isPrinted = false; //该矩阵是否输出过马鞍点
    for (int i = 0; i < n; ++i) {
        int min = INT_MAX; //第 i 行的最小值
        int col; //该最小值所在的列
        for (int j = 0; j < m; ++j) {
            if (Matrix[i][j] < min) {
                min = Matrix[i][j];
                col = j;
            }
        }
        //找到了行最小值，现在验证它是不是列最大值
        int flag = true;
        for (int i2 = 0; i2 < n; ++i2) {
            if (Matrix[i2][col] > min) { //如果行最小值不是列最大值
                flag = false;
            }
        }
        if (flag) {
            cout << i + 1 << " " << col + 1 << " " << min << endl;
            isPrinted = true;
        }
    }
    if (!isPrinted) {
        cout << "NO";
    }
}