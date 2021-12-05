#include <iostream>
#include <queue>

using namespace std;

bool **adjMatrix;
bool *visited;
int n;

void BFS(int v) {
    queue<int> nodeQue;
    nodeQue.push(v);
    visited[v] = true;
    while (!nodeQue.empty()) {
        int front = nodeQue.front();
        nodeQue.pop();
        cout << front + 1 << " ";
        for (int i = 0; i < n; ++i) {
            if (adjMatrix[front][i] && !visited[i]) {
                nodeQue.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    cin >> n;
    adjMatrix = new bool *[n];
    for (int i = 0; i < n; ++i) {
        adjMatrix[i] = new bool[n];
    }
    visited = new bool[n]{};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adjMatrix[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            BFS(i);
            ++count;
        }
    }
    cout << endl << count;
}