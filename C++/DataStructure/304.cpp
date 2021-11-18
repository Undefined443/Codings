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

    friend istream &operator>>(istream &is, Arc &arc);

    friend ostream &operator<<(ostream &os, const Arc &arc);
};

istream &operator>>(istream &is, Arc &arc) {
    is >> arc.from >> arc.to >> arc.weight;
    return is;
}

ostream &operator<<(ostream &os, const Arc &arc) {
    os << arc.from << " " << arc.to << " " << arc.weight;
    return os;
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
        cin >> temp;
        arcs.push_back(temp);
    }
    sort(arcs.begin(), arcs.end(), [](const Arc &A1, const Arc &A2) { return A1.weight < A2.weight; }); //按权排序
    vector<Arc> spanningTree; //生成树
    for (auto it = arcs.begin(); spanningTree.size() < n - 1; ++it) {
        //在顶点集中确定边的两顶点所属类别
        int from_category = find_if(nodes.begin(), nodes.end(),
                                    [it](const Node &n) {
                                        return n.index == it->from;
                                    })->category;
        int to_category = find_if(nodes.begin(), nodes.end(),
                                  [it](const Node &n) {
                                      return n.index == it->to;
                                  })->category;
        if (from_category != to_category) { //边的两顶点不属于同一类，可以将边加入生成树
            for_each(nodes.begin(), nodes.end(),
                     [from_category, to_category](Node &n) {
                         n.category = (n.category == to_category) ? from_category : n.category;
                     }); //将所有和 to 类别相同的结点的类别都转成 from 的类别
            spanningTree.push_back(*it);
        }
    }
    for (const Arc &arc: spanningTree) {
        cout << arc << endl;
    }
}