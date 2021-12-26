#pragma GCC diagnostic error "-std=c++11"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
    string name;
    int score{};
    int age{};

public:
    Student() = default;

    friend bool operator<(const Student &stu1, const Student &stu2);

    friend istream &operator>>(istream &is, Student &stu);

    friend ostream &operator<<(ostream &os, const Student &stu);
};

bool operator<(const Student &stu1, const Student &stu2) {
    if (stu1.score != stu2.score) return stu1.score < stu2.score;
    if (stu1.name != stu2.name) return stu1.name > stu2.name;
    return stu1.age > stu2.age;
}

istream &operator>>(istream &is, Student &stu) {
    is >> stu.name >> stu.age >> stu.score;
    return is;
}

ostream &operator<<(ostream &os, const Student &stu) {
    os << stu.name << " " << stu.age << " " << stu.score;
    return os;
}

int main() {
    int n;
    cin >> n;
    vector<Student> svec(n);
    for (int i = 0; i < n; ++i) {
        cin >> svec[i];
    }
    sort(svec.rbegin(), svec.rend());
    for (const Student &s: svec) {
        cout << s << endl;
    }
}