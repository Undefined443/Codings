#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<char> charVec;
  for (int i = 0; i < n; ++i) {
    char input;
    cin >> input;
    charVec.push_back(input);
  }
  vector<int> next;
  next.push_back(-1);
  int j = 0, k = -1;
  int len = charVec.size();
  while (j != len) {
    if (k == -1 || charVec[j] == charVec[next[j]]) {
      ++j;
      ++k;
      if (charVec[j] != charVec[k]) {
        next[j] = k;
      } else {
        next[j] = next[k];
      }
    } else {
      k = next[k];
    }
  }
  for (int i : next) {
    cout << i << " ";
  }
}