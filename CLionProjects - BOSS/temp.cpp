//
// Created by Windows 10 on 2021/9/6.
//
#include <iostream>
#include <vector>
#include "master.h"
#include "blogPark.h"

using namespace std;

unsigned long long algorithm(int k, int m) {
    if (m < k - 1) {
        return 0;
    }
    vector<unsigned long long> temp(m - k + 2);
    temp[0] = 1;
    for (int n = 0; n <= m - k + 1; ++n) {
        for (int i = n - 1; i >= 0 && i >= n - k; --i) {
            temp[n] += temp[i];
        }
    }
    return temp[m - k + 1];
}


int main() {
    bool flag = true;
    for (int k = 2; k <= 46; ++k) {
        for (int m = 0; m < 46; ++m) {
            cout << "k = " << k << ", m = " << m << endl;
            unsigned long long mine = algorithm(k, m), master = run(k, m), blog = FIB(k, m);
            cout << mine << endl << blog << endl << master << endl;
            if (master == -1) {
                cerr << "ERROR" << endl;  //master 发生错误
                return -1;
            }
            if (mine != master || blog != master) {
                cerr << "There must be something wrong." << endl;
                flag = false;
                return 0;
            }
        }
    }
    if (!flag) {
        cout << "NOT COOL" << endl;
    } else {
        cout << "COOL" << endl;
    }
}