#include <iostream>

using namespace std;

// 堆化以 root 作为根结点的子树。arr 是排序数组，n 是元素个数
void heapify(int arr[], int n, int root) {
    int smallest = root; // 将最小结点初始化为根结点
    int lChild = 2 * root + 1;
    int rChild = 2 * root + 2;

    if (lChild < n && arr[lChild] < arr[smallest]) { // 用左孩子更新最小结点
        smallest = lChild;
    }
    if (rChild < n && arr[rChild] < arr[smallest]) { // 用右孩子更新最小结点
        smallest = rChild;
    }

    // 如果最小结点不是根结点，就交换最小结点和根结点的值
    if (smallest != root) {
        swap(arr[root], arr[smallest]);
        heapify(arr, n, smallest); // 交换操作可能破坏子堆的结构，因此重新堆化子堆
    }
}

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
}