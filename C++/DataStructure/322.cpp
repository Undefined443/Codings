#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int **adjMatrix;   //邻接矩阵
int *InDegree;     //入度
int *OutDegree;    //出度
int *Ve;           //顶点的最早发生时间

void init() { //输入邻接矩阵，设定每个顶点的入度和出度，找到源点
    cin >> n;
    Ve = new int[n]{};
    InDegree = new int[n]{};
    OutDegree = new int[n]{};
    adjMatrix = new int *[n];
    for (int i = 0; i < n; ++i) {
        adjMatrix[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adjMatrix[i][j];
            if (adjMatrix[i][j]) { //若存在边 (i, j)，则 i 的出度 +1，j 的入度 +1
                ++OutDegree[i];
                ++InDegree[j];
            }
        }
    }
}

int topoSort() { //在拓扑排序的同时计算每个顶点的最早发生时间
    int left = n; //图中剩下的顶点数
    queue<int> nodeQue;
    for (int i = 0; i < n; ++i) { //将源点入队列
        if (!InDegree[i]) {
            nodeQue.push(i);
            Ve[i] = 0; //源点的最早发生时间为 0
        }
    }
    while (!nodeQue.empty()) {
        int v = nodeQue.front();
        nodeQue.pop(); //不断将入度为 0 的顶点出队列
        --left;
        for (int i = 0; i < n; ++i) {
            if (adjMatrix[v][i]) { //找到 v 的邻接点
                --InDegree[i]; //邻接点的入度 -1
                Ve[i] = max(Ve[i], Ve[v] + adjMatrix[v][i]); //邻接点的最早发生时间等于 v 的最早发生时间加上活动时间。当有多个 v 通往该邻接点时，选取最大值。
                if (!InDegree[i]) { //若邻接点入度变为 0 则入队列
                    nodeQue.push(i);
                }
            }
        }
    }
    if (left) { //有剩余顶点，说明图中有环
        return -1;
    } else {
        return Ve[n - 1]; //汇点的最早发生时间就是关键路径的长度
    }
}

int main() {
    init();
    int critical_path = topoSort();
    if (critical_path != -1)
        cout << critical_path << endl;
    else
        cout << "NO" << endl;
    return 0;
}
