#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;

//用邻接表存储图
class Node {
private:
    static int flag;                     //用于给顶点命名的辅助变量
public:
    int index;                           //顶点名
    bool visited = false;                //表示顶点是否访问过
    vector<vector<Node>::iterator> adjs; //邻接表

    Node();

    bool visit();
};

int Node::flag = 0;

Node::Node() : index(++flag) {}

//如果顶点未访问过，则访问该顶点，返回 true；否则返回 false
bool Node::visit() {
    if (!visited) {
        visited = true;
        return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Node> nodes(n); //顶点数组
    vector<int> subGraph;  //记录连通子图数

    //输入边集
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        //将边的两端点分别加入到两端点各自的邻接表
        auto from_node = find_if(nodes.begin(), nodes.end(),
                                 [from](const Node &n) {
                                     return n.index == from;
                                 });
        auto to_node = find_if(nodes.begin(), nodes.end(),
                               [to](const Node &n) {
                                   return n.index == to;
                               });
        from_node->adjs.push_back(to_node);
        to_node->adjs.push_back(from_node);
    }

    //DFS
    stack<vector<Node>::iterator> nodeStack;
    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
        if (it->visit()) { //如果找到未访问过的顶点，则访问该顶点，并进行 DFS
            nodeStack.push(it);
            int nodeCount = 1; //记录该子图的顶点数
            while (!nodeStack.empty()) {
                auto top = nodeStack.top(); //取栈顶元素
                bool isAllVisited = true;
                for (auto pnode: top->adjs) { //检查栈顶元素是否有未访问过的邻接点
                    if (pnode->visit()) { //找到一个未访问过的邻接点
                        nodeStack.push(pnode); //邻接点入栈
                        ++nodeCount; //连通子图顶点数 +1
                        isAllVisited = false; //顶点（可能）有未访问过的邻接点，还不能出栈
                        break; //重新进入 while 循环
                    }
                }
                if (isAllVisited) { //若该顶点没有未访问过的邻接点，则将该顶点出栈
                    nodeStack.pop();
                }
            }
            subGraph.push_back(nodeCount); //由 it 开始的 DFS 生成树探索完毕，将树的顶点数加入记录数组
        }
    }
    cout << subGraph.size() << endl;
    sort(subGraph.begin(), subGraph.end());
    for (int i: subGraph) {
        cout << i << " ";
    }
}