#include <iostream>
#include <cmath>
using namespace std;

class Rectangle
{
public:
    int xl = 0, xr = 0, yl = 0, yr = 0;
    int width = 0, hight = 0;
    int S = 0;
    void init();
};

bool chonghe(Rectangle *a, Rectangle *b, int *x, int *y);
int max(int a, int b);
int min(int a, int b);

int main()
{
    int n;
    cin >> n;
    Rectangle rec[100];
    for (int i = 0; i < n; i++)
    {
        rec[i].init();
    }
    int sum = rec[0].S;
    int x = 0, y = 0;
    for (int i = 1; i < n; i++)
    {
        if (chonghe(&rec[i - 1], &rec[i], &x, &y))
        {
            sum -= x * y;
        }
        sum += rec[i].S;
    }
    cout << sum;
}

void Rectangle::init()
{
    cin >> xl >> yl >> xr >> yr;
    width = xr - xl;
    hight = yr - yl;
    S = width * hight;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

bool chonghe(Rectangle *a, Rectangle *b, int *x, int *y)
{
    *x = a->width + b->width - max(a->xr, b->xr) + min(a->xl, b->xl);
    *y = a->hight + b->hight - max(a->yr, b->yr) + min(a->yl, b->yl);
    return max(a->xr, b->xr) - min(a->xl, b->xl) < a->width + b->width && max(a->yr, b->yr) - min(a->yl, b->yl) < a->hight + b->hight;
}
