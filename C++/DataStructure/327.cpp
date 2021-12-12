#include <iostream>

#define INF 10000

int **graph;
int **next; // next[i][j] 表示从 i 到 j 的最短路径中，i 的下一个顶点是什么
int n;

void init() {
    std::cin >> n;
    graph = new int *[n];
    next = new int *[n];
    for (int i = 0; i < n; ++i) {
        graph[i] = new int[n];
        next[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> graph[i][j];
            if (graph[i][j] != INF) { // 如果 i, j 邻接
                next[i][j] = j; // 那么 i, j 的初始最短路径就是 (i, j)
            }
        }
    }
}

void Floyd() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) { // 如果通过 k 可以缩短 i, j 的长度
                    graph[i][j] = graph[i][k] + graph[k][j]; // 更新最短路径长度
                    next[i][j] = next[i][k]; // 从 i 到 j 的最短路径的下一个顶点就是从 i 到 k 的最短路径的下一个顶点
                }
            }
        }
    }
}

void printPath(int u, int v) { // 输出 u 到 v 的最短路径
    while (u != v) {
        std::cout << u << " ";
        u = next[u][v];
    }
    std::cout << v << std::endl;
}

int main() {
    init();
    Floyd();
    int u, v;
    std::cin >> u >> v;
    while (u != -1 && v != -1) {
        if (graph[u][v] >= INF) { // 若 u, v 不可达
            std::cout << "NO" << std::endl;
        } else {
            std::cout << graph[u][v] << std::endl;
            printPath(u, v);
        }
    std::cin >> u >> v;
    }
}