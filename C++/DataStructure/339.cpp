#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = 0; j < n - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                flag = true;
                ++count;
            }
        }
        if (!flag) {
            break;
        }
    }
    cout << count;
}