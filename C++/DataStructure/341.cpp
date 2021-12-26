#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; ++i) {
        static int pending = 1;
        int index = pending - 1;
        int insert = a[pending];
        while (index >= 0 && insert < a[index]) {
            a[index + 1] = a[index];
            --index;
        }
        a[++index] = insert;
        for (int j = 0; j < n; ++j) {
            cout << a[j] << " ";
        }
        ++pending;
        cout << endl;
    }
}