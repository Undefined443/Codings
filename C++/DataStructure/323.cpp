#include <iostream>
#include <queue>

using namespace std;

class Graph {
public:
    int n;
    int **adjMatrix;   //邻接矩阵
    int *InDegree;     //入度
    bool loop = false;

    Graph();

    ~Graph();

    void checkLoop();
};

Graph::Graph() {
    int x;
    cin >> x;
    n = x;
    adjMatrix = new int *[n];
    InDegree = new int[n]{};
    for (int i = 0; i < n; ++i) {
        adjMatrix[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adjMatrix[i][j];
            if (adjMatrix[i][j]) {
                ++InDegree[j];
            }
        }
    }
    checkLoop();
}

Graph::~Graph() {
    for (int i = 0; i < n; ++i) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
    delete[] InDegree;
}

void Graph::checkLoop() {
    int left(n);
    queue<int> nodeQue;
    for (int i = 0; i < n; ++i) {
        if (!InDegree[i]) {
            nodeQue.push(i);
        }
    }
    while (!nodeQue.empty()) {
        int front = nodeQue.front();
        nodeQue.pop();
        --left;
        for (int i = 0; i < n; ++i) {
            if (adjMatrix[front][i]) {
                --InDegree[i];
                if (!InDegree[i]) {
                    nodeQue.push(i);
                }
            }
        }
    }
    loop = left != 0;
}

int main() {
    int n;
    cin >> n;
    bool *res = new bool[n];
    for (int i = 0; i < n; ++i) {
        Graph G;
        res[i] = G.loop;
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i];
    }
}