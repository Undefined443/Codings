#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main(int argc, char **argv) {
    ifstream file1(argv[1], ios::in);
    ifstream file2(argv[2], ios::in);
    string str1;
    string str2;
    int line = 1;
    while (file1.good() && file2.good()) {
        getline(file1, str1);
        getline(file2, str2);
        if (strcmp(argv[3], "-e") == 0) {
#define EASYMODE
        }
        if (str1 != str2) {
            cerr << "Difference at line " << line << ":" << endl;
#ifndef EASYMODE
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); //设置前景色为高亮绿色
            cout << "<<<<<<< " << argv[1] << endl;
#endif
            cout << str1 << endl;
#ifndef EASYMODE
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //设置前景色为白色
            cout << "=======" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE); //设置前景色为高亮蓝色
#endif
            cout << str2 << endl
#ifndef EASYMODE
            << ">>>>>>> " << argv[2] << endl << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //设置前景色为白色
#endif
        }
        ++line;
    }
}
