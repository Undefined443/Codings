#include <iostream>
#include <fstream>
#include <string>

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
            cout << str1 << endl;
            cout << str2 << endl;
        }
        ++line;
    }
}
