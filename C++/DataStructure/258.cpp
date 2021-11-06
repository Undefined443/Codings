#pragma GCC diagnostic error "-std=c++14"

#include <iostream>
#include <forward_list>
#include <vector>

using namespace std;

class Node {
public:
  int address;
  int val;
  int next;
  
  Node() {
    cin >> address;
    cin >> val;
    cin >> next;
  }
};

int main() {
    int address;
    int n;
    cin >> address >> n;
    vector<Node> NodeVec;
    for (int i = 0; i < n; ++i) {
      NodeVec.emplace();
    }
    forward_list<int> intList;
    while (address != -1) {
      NodeVec.find(NodeVec.begin(), NodeVec.end(), )
    }
}
