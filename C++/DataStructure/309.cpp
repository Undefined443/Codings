#pragma GCC diagnostic error "-std=c++14"

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Matrix {
public:
    queue<int> V;           //存储非零元
    vector<vector<int> > B; //指示矩阵

    void init(int n, int m);

    Matrix operator+(Matrix &M);

    void print();
};

void Matrix::init(int n, int m) {
    int count = 0; //记录非零元个数
    for (int i = 0; i < n; ++i) {
        vector<int> temp;
        for (int j = 0; j < m; ++j) {
            int index;
            cin >> index;
            if (index) {
                ++count;
            }
            temp.push_back(index);
        }
        B.push_back(temp);
    }
    for (int i = 0; i < count; ++i) {
        int temp;
        cin >> temp;
        V.push(temp);
    }
}

Matrix Matrix::operator+(Matrix &M) {
    auto row = B.size();
    auto col = B[0].size();
    Matrix C;
    C.B = B;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            int temp = 0;
            if (B[i][j]) { //如果自己在此处有非零元
                temp += V.front();
                V.pop();
            }
            if (M.B[i][j]) { //如果该位置有非零元
                temp += M.V.front();
                M.V.pop();
            }
            if (temp) {
                C.V.push(temp);
                C.B[i][j] = 1;
            } else {
                C.B[i][j] = 0;
            }
        }
    }
    return C;
}

void Matrix::print() {
    for (vector<int> &v : B) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    while (!V.empty()) {
        cout << V.front() << " ";
        V.pop();
    }
}

int main() {
    int n, m; //行数，列数
    cin >> n >> m;
    Matrix A;
    A.init(n, m);
    Matrix B;
    B.init(n, m);
    Matrix C = A + B;
    C.print();
}