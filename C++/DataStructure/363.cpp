#include <iostream>

using namespace std;

int partition(int arr[], int low, int high) { // 将无序表 [low, high] 以 arr[low] 为支点分为两部分。返回支点索引
    int pivot = arr[low]; // 取出支点
    while (low < high) {
        while (low < high && arr[high] >= pivot) { // 不断将 high 左移，直到找到比支点小的元素
            --high;
        }
        arr[low] = arr[high]; // 将该元素抛给 low
        while (low < high && arr[low] <= pivot) { // low 指针右移，直至遇到比支点大的元素
            ++low;
        }
        arr[high] = arr[low]; // 将该元素抛给 high
    }
    arr[low] = pivot; // 放回支点
    return low;
}

void quickSort(int arr[], int low, int high) {
    if (low <= high) {
        int pivotLoc = partition(arr, low, high); // 将无序表分割成两个子表
        quickSort(arr, low, pivotLoc - 1); // 对支点左侧的子表进行排序
        quickSort(arr, pivotLoc + 1, high); // 对支点右侧的子表进行排序
        cout << arr[pivotLoc] << " ";
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
}