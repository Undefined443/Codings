//使用并查集
#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Arc {
public:
    int v1;
    int v2;
    int weight;

    Arc() = default;

    friend istream &operator>>(istream &is, Arc &arc);

    friend ostream &operator<<(ostream &os, const Arc &arc);

    friend bool operator<(const Arc &e1, const Arc &e2);
};

istream &operator>>(istream &is, Arc &arc) {
    int v1, v2;
    is >> v1 >> v2 >> arc.weight;
    arc.v1 = v1 < v2 ? v1 - 1 : v2 - 1;
    arc.v2 = v1 < v2 ? v2 - 1 : v1 - 1;
    return is;
}

ostream &operator<<(ostream &os, const Arc &arc) {
    os << arc.v1 + 1 << " " << arc.v2 + 1 << " " << arc.weight;
    return os;
}

bool operator<(const Arc &e1, const Arc &e2) {
    return e1.weight < e2.weight;
}

vector<int> *parent{};

int findParent(int i) {
    return i == (*parent)[i] ? i : (*parent)[i] = findParent((*parent)[i]);
}

bool merge(int v1, int v2) {
    int v1_parent = findParent(v1);
    int v2_parent = findParent(v2);
    if (v1_parent != v2_parent) {
        (*parent)[v2_parent] = v1_parent;
        return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    parent = new vector<int>(n);
    int flag = 0;
    for_each(parent->begin(), parent->end(), [&flag](int &i) { i = flag++; });
    //输入边集
    vector<Arc> arcs;
    for (int i = 0; i < m; ++i) {
        Arc temp{};
        cin >> temp;
        arcs.push_back(temp);
    }
    sort(arcs.begin(), arcs.end()); //将边按权值升序排序
    int totalEdges = 0; //用于记录已输出的边数
    for (auto it = arcs.begin(); totalEdges < n - 1; ++it) {
        if (merge(it->v1, it->v2)) {
            cout << *it << endl;
            ++totalEdges;
        }
    }
}