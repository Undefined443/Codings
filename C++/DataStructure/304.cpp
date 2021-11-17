#pragma GCC diagnostic error "-std=c++14"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Arc {
public:
    int from;
    int to;
    int weight;

    void input();
};

void Arc::input() {
    cin >> from >> to >> weight;
}

class Node {
private:
    static int flag;
public:
    int index;
    int category;

    Node();
};

int Node::flag = 1;

Node::Node() : index(flag++), category(index) {} //每个顶点自成一类

int main() {
    int n, m;
    cin >> n >> m;
    vector<Node> nodes(n);
    vector<Arc> arcs;
    for (int i = 0; i < m; ++i) {
        Arc temp;
        temp.input();
        arcs.push_back(temp);
    }
    sort(arcs.begin(), arcs.end(), [](const Arc &A1, const Arc &A2) { return A1.weight < A2.weight; });
    vector<Arc> spanningTree; //记录已选择的边数
    auto candidateArc = arcs.begin();
    while (spanningTree.size() < n - 1) {
        //在顶点集中定位边的两顶点
        int from_category = find_if(nodes.begin(), nodes.end(),
                            [candidateArc](const Node &n) -> bool { return n.index == candidateArc->from; })->category;
        int to_category = find_if(nodes.begin(), nodes.end(),
                          [candidateArc](const Node &n) -> bool { return n.index == candidateArc->to; })->category;
        if (from_category != to_category) { //边的两顶点不属于同一类，可以将边加入生成树
            for_each(nodes.begin(), nodes.end(),
                     [from_category, to_category](Node &n) {
                         n.category = (n.category == to_category) ? from_category : n.category;
                     }); //将所有和 to 类别相同的结点的类别都转成 from 的类别
            spanningTree.push_back(*candidateArc);
        }
        ++candidateArc;
    }
    for (const Arc &arc: spanningTree) {
        cout << arc.from << " " << arc.to << " " << arc.weight << endl;
    }
}