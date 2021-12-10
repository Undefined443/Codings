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
    priority_queue<d_v, vector<d_v>, greater<d_v>> min_heap; // 创建一个小顶堆（距离最近的顶点在堆顶），这里存储尚未确定最短路径的顶点 (d)v
    vector<int> dist(n, INF); // 所有顶点的最短路径，初始化所有顶点的最短路径为无穷大
    dist[src] = 0; // 源点的最短路径为 0
    bool *flag = new bool[n]{}; // 用于判断是否已经使用过某顶点作为中转站来刷新其他顶点的最短路径
    min_heap.push(make_pair(0, src)); // 将源点插入小顶堆，使循环开始运行
    while (!min_heap.empty()) {
        int u = min_heap.top().second; // 取出距离最近的顶点
        min_heap.pop();
        if (!flag[u]) {
            for (auto i = adj[u].begin(); i != adj[u].end(); ++i) { // 以 u 为中转站，刷新其邻接点的最短路径
                int v = i->first; // 邻接点
                int weight = i->second; // 通往邻接点的边的权
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    min_heap.push(make_pair(dist[v], v)); // 若 v 通过 u 中转得到的距离小于直连距离，则刷新它在小顶堆中的值
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
