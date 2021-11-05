#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char str[80] = {0};
  gets(str);
  int end = strlen(str) / 2;
  for (int i = 0; i < end; ++i) {
      static int len = 1;
      if (!strncmp(str, str + len, len)) {
          cout << len;
          return 0;
      }
      ++len;
  }
  cout << strlen(str);
}