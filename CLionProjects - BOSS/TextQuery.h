#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <map>
#include <set>

class QueryResult;

class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;

    TextQuery(std::ifstream &);

    QueryResult query(const std::string &) const;

private:
    std::shared_ptr<std::vector<std::string>> file; //输入文件
    //每个单词到它所在行号的集合的映射
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};