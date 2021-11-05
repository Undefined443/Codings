#include <iostream>
#include <stack>

using namespace std;

int main() {
  int n;
  cin >> n;
  stack<char> stk;
  char temp;
  for (int i = 0; i < n / 2; ++i) {
    cin >> temp;
    stk.push(temp);
  }
  if (n % 2) {
    cin >> temp;
  }
  for (int i = 0; i < n / 2; ++i) {
    cin >> temp;
    if (temp != stk.top()) {
      cout << "NO" << endl;
      return 0;
    }
    stk.pop();
  }
  cout << "YES" << endl;
}