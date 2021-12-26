#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int increment = n / 2;
    for (int i = 0; i < increment; ++i) {
        int pending = increment + i;
        int index = i;
        int insert = a[pending];
        while (index >= 0 && insert < a[index]) {
            a[index + increment] = a[index];
            index -= increment;
        }
        a[index + increment] = insert;
    }
    for (int j = 0; j < n; ++j) {
        cout << a[j] << " ";
    }
    cout << endl;
}