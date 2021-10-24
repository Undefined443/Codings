#pragma GCC diagnostic error "-std=c++14"

#include <iostream>
#include <exception>
#include <windows.h>

using namespace std;

int main() {
    int n, i;
    for (int j = 0; j < 20; ++j) {
        static int i = 2;
        int temp = i;
        i = 3 * i / 2;
        if (i - i / 3 == temp) {
            cout << i << " ";
        } else {
            ++i;
            if (i - i / 3 == temp) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); //设置前景色为高亮绿色
                cout << i << " ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE); //设置前景色为白色
                continue;
            }
            i -= 2;
            if (i - i / 3 == temp) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); //设置前景色为高亮红色
                cout << i << " ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE); //设置前景色为白色
                continue;
            }
            throw exception();
        }
        i = 2 * i - 1;
    }
}