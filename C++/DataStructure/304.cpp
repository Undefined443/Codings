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
    static int flag; //用于给顶点分类的辅助变量
public:
    int index;       //顶点名
    int category;    //顶点的类别

    Node();
};

int Node::flag = 0;

Node::Node() : index(flag++), category(index) {} //给每个顶点命名并分类。顶点的初始类别就是自己的名字

int main() {
    int n, m;
    cin >> n >> m;
    vector<Node> nodes(n); //创建一个存储了 n 个顶点的顶点集
    vector<Arc> arcs;      //边集
    //输入边
    for (int i = 0; i < m; ++i) {
        Arc temp;
        cin >> temp;
        arcs.push_back(temp);
    }
    sort(arcs.begin(), arcs.end(), [](const Arc &A1, const Arc &A2) { return A1.weight < A2.weight; }); //将边按权值升序排序
    int totalEdge = 0; //用于记录已输出的边数
    for (auto it = arcs.begin(); totalEdge < n - 1; ++it) {
        //在顶点集中确定边的两顶点所属类别
        int from_category = find_if(nodes.begin(), nodes.end(),
                                    [it](const Node &n) {
                                        return n.index == it->from;
                                    })->category;
        int to_category = find_if(nodes.begin(), nodes.end(),
                                  [it](const Node &n) {
                                      return n.index == it->to;
                                  })->category;
        if (from_category != to_category) { //边的两端点不属于同一类，可以将边加入生成树。这里直接将边输出
            //将所有和 to 类别相同的结点的类别都转成 from 的类别
            for_each(nodes.begin(), nodes.end(),
                     [from_category, to_category](Node &n) {
                         n.category = (n.category == to_category) ? from_category : n.category;
                     });
            cout << *it << endl;
            ++totalEdge;
        }
    }
}