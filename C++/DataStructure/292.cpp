#include <iostream>
#include <priority_queue>

using namespace std;

int main() {
  int n;
  cin >> n;
  priority_queue<int,vector<int>, greater<int> > pri_que;//升序队列
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    pri_que.push(x);
  }
  int res = 0;
  while (pri_que.size() != 1) {
    int a = pri_que.top();
    pri_que.pop();
    int b = pri_que.top();
    pri_que.pop();
    int c = a + b;
    pri_que.push(c);
    res += c;
  }
  cout << res;
}