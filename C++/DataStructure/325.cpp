#include <iostream>
#include <stack>

using namespace std;

bool **adjMatrix;
bool *visited;
int n;

void DFS(int v) {
    stack<int> nodeStk;
    nodeStk.push(v);
    cout << v + 1 << " ";
    visited[v] = true;
    while (!nodeStk.empty()) {
        int top = nodeStk.top();
        bool isAllVisited = true;
        for (int i = 0; i < n; ++i) {
            if (adjMatrix[top][i] && !visited[i]) {
                nodeStk.push(i);
                cout << i + 1 << " ";
                visited[i] = true;
                isAllVisited = false;
                break;
            }
        }
        if (isAllVisited) {
            nodeStk.pop();
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