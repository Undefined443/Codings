#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int pivot = a[0];
    int low = 0;
    int high = n - 1;
    while (low < high) {
        while (low < high && a[high] >= pivot) {
            --high;
        }
        a[low] = a[high];
        while (low < high && a[low] <= pivot) {
            ++low;
        }
        a[high] = a[low];
    }
    a[low] = pivot;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}