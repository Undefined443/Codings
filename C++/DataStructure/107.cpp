#pragma GCC diagnostic error "-std=c++14"

#include <iostream>
#include <vector>

#define NDEBUG

#ifndef NDEBUG
#include <windows.h>
#endif


using namespace std;

class Point {
public:
    int i;
    int j;
    int dir;

    Point(int i, int j) : i(i), j(j), dir(0) {}

    bool operator!=(const Point &p) const {
        if (this->i == p.i && this->j == p.j) return false;
        return true;
    }

    Point &operator=(const Point &p) {
        this->i = p.i;
        this->j = p.j;
        this->dir = p.dir;
        return *this;
    }
};

int chooseDir(Point p, const vector<vector<int> > &maze) {
    if (maze[p.i][p.j + 1] == 0) return 1; //to the right
    if (maze[p.i + 1][p.j] == 0) return 2; //downwards
    if (maze[p.i][p.j - 1] == 0) return 3; //to the left
    if (maze[p.i - 1][p.j] == 0) return 4; //upwards
    return 0; //nowhere to go
}

void move(Point &p, vector<vector<int> > &maze) {
    switch (p.dir) {
        case 1:
            ++p.j;
            break;
        case 2:
            ++p.i;
            break;
        case 3:
            --p.j;
            break;
        case 4:
            --p.i;
            break;
    }
    maze[p.i][p.j] = 1;
}

int main() {
    int hight, width;
    cin >> hight >> width;
    vector<vector<int> > maze(hight + 2, vector<int>(width + 2));
    int i, j;
    cin >> i >> j;
    Point start(i, j);
    cin >> i >> j;
    Point end(i, j);

    //initial the maze(wall)
    for (int i = 0; i < hight + 2; ++i) {
        maze[i][0] = 1;
        maze[i][width + 1] = 1;
    }
    for (int j = 1; j < width + 1; ++j) {
        maze[0][j] = 1;
        maze[hight + 1][j] = 1;
    }

    //enter the maze
    for (int i = 1; i <= hight; ++i) {
        for (int j = 1; j <= width; ++j) {
            cin >> maze[i][j];
        }
    }
    maze[start.i][start.j] = 1;

#ifndef NDEBUG
    vector<vector<int>> maze_cpy(maze);
#endif

    //finding the solution
    vector<Point> track;
    Point cur = start;
    bool flag = true; //decide if the maze has a solution
    while (cur != end) {
        if (cur.dir = chooseDir(cur, maze)) {
            track.push_back(cur);
            move(cur, maze);
        } else {
            if (track.empty()) {
                flag = false;
                break;
            }
            cur = track.back();
            track.pop_back();
        }
    }
    cur.dir = 1;
    track.push_back(cur);

    //output
    if (!flag) {
        cout << "no" << endl;
        return 0;
    }
    bool first = true;
    for (Point p: track) {
        if (!first) cout << "," << flush;
        cout << "(" << p.i << "," << p.j << "," << p.dir << ")" << flush;
        first = false;
    }

#ifndef NDEBUG
    cout << endl;
    for (Point p: track) {
        maze_cpy[p.i][p.j] = 2;
    }
    for (int i = 1; i <= hight; ++i) {
        for (int j = 1; j <= width; ++j) {
            if (maze_cpy[i][j] == 2) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
                cout << "0 ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
            }
            else cout << maze_cpy[i][j] << " ";
        }
        cout << endl;
    }
    getchar();
    getchar();
#endif
}

/*
7 22
1 1
7 20
0 0 1 0 0 0 0 1 0 1 1 1 0 1 1 0 0 0 0 0 0 0
1 0 1 0 1 1 0 1 0 0 0 0 0 0 1 0 1 1 1 0 1 1
0 0 1 0 1 1 0 0 1 1 0 1 0 0 1 0 0 0 1 0 0 0
0 1 1 0 0 1 1 0 0 1 0 0 1 0 1 1 1 0 1 0 0 0
0 0 0 1 0 0 1 1 0 0 1 0 1 0 0 0 0 0 1 0 1 1
1 1 0 0 1 0 1 1 1 0 0 0 1 1 1 1 1 1 1 0 0 0
1 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 0

 */