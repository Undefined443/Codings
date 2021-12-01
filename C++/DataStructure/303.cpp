//使用并查集
#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
    int index{};  //顶点名
    int weight = 1; //表示该集合有多少个元素

    Node() = default;
};

vector<int> *parent{};
vector<Node> *nodes{};

int findParent(int i) { //寻找结点 n 所属集合的代表元素
    return i == (*parent)[i] ? i : (*parent)[i] = findParent((*parent)[i]); //若自己不是所属集合的代表元素，那么代表元素就是父结点所属集合的代表元素
}

void merge(int v1, int v2) {
    //获取两结点所属集合的代表元素
    int v1_parent = findParent(v1);
    int v2_parent = findParent(v2);
    if (v1_parent != v2_parent) { //两结点属于不同集合，可以归并
        //把集合 2 归入集合 1
        (*parent)[v2_parent] = v1_parent;
        (*nodes)[v1_parent].weight += (*nodes)[v2_parent].weight;
        (*nodes)[v2_parent].weight = 0;
    }
}

int main() {
    int n, m; //顶点数，边数
    cin >> n >> m;
    int flag = 0;
    parent = new vector<int>(n);
    for_each(parent->begin(), parent->end(), [&flag](int &i) { i = flag++; });
    flag = 0;
    nodes = new vector<Node>(n);
    for_each(nodes->begin(), nodes->end(), [&flag](Node &i) { i.index = flag++; });
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        merge(v1 - 1, v2 - 1);
    }
    vector<int> count;
    for_each(nodes->begin(), nodes->end(), [&count](const Node &i) { if (i.weight) count.push_back(i.weight); });
    sort(count.begin(), count.end());
    cout << count.size() << endl;
    for_each(count.begin(), count.end(), [](int i) { cout << i << " "; });
}