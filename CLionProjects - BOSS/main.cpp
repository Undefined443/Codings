#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include <sstream>
#include <utility>
#include <memory>
#include <new>
#include <unordered_set>
#include <initializer_list>
#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

void runQueries(std::ifstream &infile) {
    //infile 是一个 ifstream，指向我们要处理的文件
    TextQuery tq(infile);
    //与用户交互：提示用户输入要查询的单词，完成查询并打印结果
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        //若遇到文件尾或用户输入了'q'时循环终止
        if (!(cin >> s) || s == "q") break;
        //指向查询并打印结果
        print(cout, tq.query(s)) << endl;
    }
}

int main() {

}

