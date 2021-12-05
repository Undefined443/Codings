#include <iostream>

using namespace std;

bool **adjMatrix;
bool *visited;
int n;

void DFS(int v) {
    cout << v + 1 << " ";
    visited[v] = true;
    for (int i = 0; i < n; ++i) {
        if (adjMatrix[i][v] && !visited[i]) {
            DFS(i);
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
            DFS(i);
            ++count;
        }
    }
    cout << endl << count;
}