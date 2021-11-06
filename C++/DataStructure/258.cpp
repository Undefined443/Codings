#pragma GCC diagnostic error "-std=c++14"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Node {
public:
  string m_address;
  int m_val;
  string m_next;

  Node(string address, int val, string next) : m_address(address), m_next(next), m_val(val) {};
};

int main() {
    string begin;
    int n;
    cin >> begin >> n;
    vector<Node> NodeVec;
    for (int i = 0; i < n; ++i) {
        string address;
        int val;
        string next;
        cin >> address >> val >> next;
        Node temp(address, val, next);
      NodeVec.push_back(temp);
    }
    //整理链表
    vector<Node> sortedVec;
    string next = begin;
    while (next != "-1") {
        auto i = find_if(NodeVec.begin(), NodeVec.end(), [next](const Node &node)->bool{return node.m_address == next;});
        sortedVec.push_back(*i);
        next = i->m_next;
    }
    //整理链表
    vector<Node> uniqueVec;
    uniqueVec.push_back(sortedVec.front());
    for (Node node : sortedVec) {
        if (find_if(uniqueVec.begin(), uniqueVec.end(), [node](Node uni)->bool{return abs(node.m_val) == abs(uni.m_val);}) == uniqueVec.end()) { //如果没出现过
            uniqueVec.back().m_next = node.m_address;
            uniqueVec.push_back(node);
        }
    }
    uniqueVec.back().m_next = "-1";
    cout << uniqueVec.size() << endl;
    for (Node node : uniqueVec) {
        cout << node.m_address << " " << node.m_val << " " << node.m_next << endl;
    }
}
