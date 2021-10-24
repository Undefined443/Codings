#include <memory>
#include "master.h"

#define OK 0
#define ERROR 1

typedef int Status;

Status Fibonacci(int k, int m, unsigned long long &f)
/* 求k阶斐波那契序列的第m项的值f */
{
//判断参数合理性
    if (k < 2 || m < 0) {
        return ERROR;
    }
//当 m < k 时
    if (m < k) {
        if (m == k - 1) {
            f = 1;
            return OK;
        } else {
            f = 0;
            return OK;
        }
    }

    unsigned long long *p, *q, i, n;
//n为操作空间大小
    n = k + 1;
//动态创建k+1个空间为操作空间
    p = q = (unsigned long long *) calloc(n, sizeof(unsigned long long));
//初始化前k+1个值，即前k-1个值为0，第k和k+1个值为1
    q[k - 1] = 1;
    q[k] = 1;
//使用模n法在n个空间内形成循环操作，此处不用k个空间是因为
//求第i个值时，要用到第i-k-1个数的值，需要k+1个空间
//第i个数的值等于两倍第i-1个数的值减去第i-k-1个数的值
    for (i = n; i <= m; i++) {
        p[i % n] = 2 * p[(i - 1) % n] - p[(i - k - 1) % n];
    }
    f = p[(m) % n];
    return OK;
}

unsigned long long run(int k, int m) {
    unsigned long long ret = 0;
    if (Fibonacci(k, m, ret) == ERROR) {
        return -1;
    }
    return ret;
}