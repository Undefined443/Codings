//#pragma GCC diagnostic error "-std=c++14"

#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n;
  cin >> n;
  queue<int> que;
  for (int i = 1; i <= n; ++i) {
    que.push(i);
  }
  que.push(0); //用于标记队尾
  que.push(0);
  que.push(0);
  int front;
  while (que.size() > 6) {
  while ((front = que.front()) && que.size() > 6) {
    //数到 1 的人出队再入队
    que.pop();
    que.push(front);
    //数到 2 的人出队
    que.pop();
  }
  if (que.size() <= 6) break;
  //把标记挪回队尾
  while (!(front = que.front())) {
    que.pop();
  }
  que.push(0);
  que.push(0);
  que.push(0);
  
  while ((front = que.front()) && que.size() > 6) {
    //数到 1 和 2 的人出队再入队
    que.pop();
    que.push(front);
    front = que.front();
    que.pop();
    que.push(front);
    //数到 3 的人出队
    que.pop();
  }
  while (!(front = que.front())) {
    que.pop();
  }
  que.push(0);
  que.push(0);
  que.push(0);
  }
  //调整队头
  while (front = que.front()) {
    que.pop();
    que.push(front);
  }
  while (!(front = que.front())) {
    que.pop();
  }
  for (int i = 0; i < 3; ++i) {
    cout << que.front() << " ";
    que.pop();
  }
  }