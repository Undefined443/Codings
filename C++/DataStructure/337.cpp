#include <iostream>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    int *a = new int[M];
    int *b = new int[N];
    for (int i = 0; i < M; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
    }
    int len = M + N;
    int *c = new int[len];
    int i = 0, j = 0, k = 0;
    while (i < M && j < N) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < M) {
        c[k++] = a[i++];
    }
    while (j < N) {
        c[k++] = b[j++];
    }
    for (int l = 0; l < len; ++l) {
        cout << c[l] << " ";
    }
}