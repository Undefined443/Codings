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
        if (str1 != str2) {
            cerr << "Difference at line " << line << ":" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN); //设置前景色为高亮绿色
            cout << "<<<<<<< " << argv[1] << endl
            << str1 << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //设置前景色为白色
            cout << "=======" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE); //设置前景色为高亮蓝色
            cout << str2 << endl
            << ">>>>>>> " << argv[2] << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //设置前景色为白色
        }
        ++line;
    }
}
