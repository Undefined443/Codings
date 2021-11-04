#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char str[80] = {0};
  gets(str);
  while (1) {
    static int len = 1;
    if (!strncmp(str, str + len, len)) {
      cout << len;
      return 0;
    }
    ++len;
  }
}