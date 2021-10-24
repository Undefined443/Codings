#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
#include <map>
#include <set>
#include "TextQuery.h"
#include "QueryResult.h"

using std::string;
using std::vector;
using std::ostream;
using std::ifstream;
using std::istringstream;
using std::shared_ptr;
using std::map;
using std::set;

TextQuery::TextQuery(std::ifstream &is) : file(new vector<string>) {
    string text;
    while (getline(is, text)) {             //对文件中每一行
        file->push_back(text);                     //保存此行文本
        int n = file->size() - 1;                  //当前行号
        istringstream line(text);                  //将行文本分解为单词
        string word;
        while (line >> word) {                     //对行中每个单词
            //如果单词不在 wm 中，以之为下标在 wm 中添加一项
            auto &lines = wm[word];                //lines 是一个 shared_ptr
            if (!lines)                            //在我们第一次遇到这个单词时，此指针为空
                lines.reset(new set<line_no>);  //分配一个新的 set
            lines->insert(n);                      //将此行号插入 set 中
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const {
    //如果未找到 sought，我们返回一个指向此 set 的指针
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    //使用 find 而不是下标运算符来查找单词，避免将单词添加到 wm 中
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file); //未找到
    else
        return QueryResult(sought, loc->second, file);
}