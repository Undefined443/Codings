#pragma once

#include <string>
#include <vector>
#include <memory>
#include <set>
#include "TextQuery.h"

class TextQuery;

class QueryResult {
    friend std::ostream &print(std::ostream &, const QueryResult);

    friend class TextQuery;

public:
    QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p,
                std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(p), file(f) {}

private:
    std::string sought; //查询单词
    std::shared_ptr<std::set<TextQuery::line_no>> lines; //出现的行号
    std::shared_ptr<std::vector<std::string>> file; //输入文件
};

std::ostream &print(std::ostream &os, const QueryResult &qr) {
    //如果找到了单词，打印出现次数和所有出现的位置
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural
}

