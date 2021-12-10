#pragma GCC diagnostic error "-std=c++11"

#include <utility>
#include <list>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

# define INF 0x3f3f3f3f

//用邻接表存储图
class Graph {
    int n; // 图的顶点数
    list<pair<int, int>> *adj; // 邻接表，存储边的终点和边的权 (v, w)

public:
    explicit Graph(int i);

    void addEdge(int u, int v, int w);

    int Dijkstra(int s);
};

Graph::Graph(int i) : n(i) {
    adj = new list<pair<int, int>>[n];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
}


int Graph::Dijkstra(int src) {
    using d_v = pair<int, int>; // (d)v，最短路径_顶点
    priority_queue<d_v, vector<d_v>, greater<d_v>> min_heap; // 创建一个小顶堆（距离最近的顶点在堆顶），存储已经确认可达的顶点 (d)v。每次将距离最短的顶点（堆顶）取出，用它来刷新其邻接点的最短路径
    bool *flag = new bool[n]{}; // 用于判断是否已经使用过某顶点来刷新其邻接点的最短路径
    vector<int> dist(n, INF); // 所有顶点的最短路径，初始化所有顶点的最短路径为无穷大（不可达）。通过每次从堆顶取出的顶点（新确定最短路径的顶点）来刷新各顶点的最短路径
    dist[src] = 0; // 源点的最短路径为 0
    min_heap.push(make_pair(0, src)); // 将源点插入小顶堆，使循环开始运行
    while (!min_heap.empty()) {
        int u = min_heap.top().second; // 取出距离最近的顶点 u
        min_heap.pop();
        if (!flag[u]) {
            for (auto i = adj[u].begin(); i != adj[u].end(); ++i) { // 以 u 为中转站，刷新其邻接点的最短路径
                int v = i->first; // u 的邻接点 v
                int weight = i->second; // 边 (u, v) 的权
                if (dist[v] > dist[u] + weight) { // 若通过 u 中转可以缩短 (d)v
                    dist[v] = dist[u] + weight; // 更新 (d)v
                    min_heap.push(make_pair(dist[v], v)); // 将新的 (d)v 重新加入小顶堆
                }
            }
            flag[u] = true;
        }
    }
    int max = 0;
    for (int i = 0; i < n; ++i) {
        max = dist[i] > max ? dist[i] : max;
    }
    return max;
}

int main() {
    int M, N, K;
    cin >> M >> N >> K;
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G.addEdge(u - 1, v - 1, w);
    }
    int res = G.Dijkstra(K - 1);
    cout << (res == INF ? -1 : res);
}
