#pragma GCC dignostic ignored "-Wunused"

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

//用邻接表存储图

using namespace std;

class Node {
private:
    static int flag;      //用于给顶点命名的辅助变量
public:
    int  index;           //顶点名
    bool visited = false; //表示顶点是否访问过
    vector<vector<Node>::iterator> adjs; //邻接表
    
    Node();
    
    bool visit();
};

int Node::flag = 0;

Node::Node() : index(flag++) {}

//如果顶点未访问过，则访问该顶点，返回 true；否则返回 false
bool Node::visit() {
    if (!visited) {
        visited = true;
        return true;
    }
    return false;
}

/*
class Arc {
public:
    vector<Node>::iterator *from;
    vector<Node>::iterator *to;
    vector<Node> *m_V;
    
    Arc(vector<Node> &V);
    
    friend istream &operator>>(istream &is, Arc &arc);
};

Arc::Arc(vector<Node> &V) m_V(&V) {}

istream &operator>>(istream &is, Arc &arc) {
    int from, to;
    is >> from >> to;
    arc.from = find_if(arc.m_V->begin(), arc.m_V->end(),
        [from](const Node &n) {
            return n.index == from;
        });
    arc.to = find_if(arc.m_V->begin(), arc.m_V->end(),
        [to](const Node &n) {
            return n.index == to;
        });
    return is;
}
*/

int main() {
    int n, m;
    cin >> n >> m;
    vector<Node> nodes(n); //顶点数组
//  vector<Arc>  E;        //边集
    vector<int>  subGraph; //记录连通子图数
    
    //输入边集
    for (int i = 0; i < m; ++i) {
//      Arc temp(V);
//      cin >> temp;
//      E.push_back(temp);
        int from, to;
        cin >> from >> to;
        //将边的两端点分别加入到两端点各自的邻接表
        auto from_node = find_if(node.begin(), node.end(),
            [from](const Node &n) {
                return n.index == from;
            });
        auto to_node = find_if(node.begin(), node.end(),
            [to](const Node &n) {
                return n.index == to;
            });
        from_node->adjs.push_back(to_node);
        to_node->adjs.push_back(from_node);
    }
    
    //DFS
    stack<*Node> nodeStack;
    for (Node &node : nodes) {
        if (node.visit()) { //如果找到未访问过的顶点，则访问该顶点，并进行 DFS
            int nodeCount = 1; //记录该子图的顶点数
            nodeStack.push(&node);
            while(!nodeStack.empty()) {
                auto n = nodeStack.top();
                bool isAllVisited = true;
                for (Node *pnode : n->adjs) {
                    if (pnode->visit()) {
                        nodeStack.push(pnode);
                        isAllVisited = false;
                        ++nodeCount;
                        break;
                    }
                }
                if (isAllVisited) {
                    nodeStack.pop();
                }
            }
            subGraph.push_back(nodeCount);
        }
    }
    cout << subGraph.size() << endl;
    sort(subGraph.begin(), subGraph.end());
    for (int i : subGraph) {
        cout << i << " ";
    }
}