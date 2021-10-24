//编写求k阶非波纳妾序列的第m项值的函数算法
#include "blogPark.h"

unsigned long long FIB(int k, int m) {
    unsigned long long f[46] = {};
    int i = 0, j = 0;
    if (k > 46 || m > 46) return 0;
    else if (m < k - 1) return 0;
    else if (m <= k - 1) return 1;;
    for (i = 0; i < k - 1; i++)        //使前k-2项均为0
        f[i] = 0;
    f[i] = 1;                    //令k－1项为1

    i++;
    for (; i <= m; i++) {
//		f[i]=f[i-1]+f[i-2]+f[i-3]+...+f[i-k];
        for (j = 1; j <= k; j++) {
            f[i] += f[i - j];
        }
    }
    i--;    //上面的for循环结束后，又运行一个i++,故需减掉1
    return f[i];
}