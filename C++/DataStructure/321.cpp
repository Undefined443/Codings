//使用并查集
#include <iostream>

using namespace std;

int *parent{};

int findParent(int i) {
    return i == parent[i] ? i : parent[i] = findParent(parent[i]);
}

void merge(int v1, int v2) {
    parent[findParent(v2)] = findParent(v1);
}

int main() {
    int N, M; //城市数目和现有高铁线路数目
    cin >> N >> M;
    parent = new int[N];
    for (int i = 0; i < N; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < M; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        merge(v1 - 1, v2 - 1);
    }
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (i == parent[i]) {
            ++count;
        }
    }
    cout << count - 1;
}