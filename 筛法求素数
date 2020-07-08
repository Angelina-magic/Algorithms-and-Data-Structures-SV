// 筛法求素数
// 用筛法求素数的基本思想是：
// 把从1开始的、某一范围内的正整数从小到大顺序排列，
// 1不是素数，首先把它筛掉。
// 剩下的数中选择最小的数是素数，然后去掉它的倍数。
// 依次类推，直到筛子为空时结束。
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#define MAX 2000000

int main() {
//    unsigned long number;
    int i, k, sum;
    bool Prime[MAX+1];
    clock_t start, end;

//    printf("请输入所筛选范围的最大值(2~number)number:");
//    scanf("%lu", &number);
    start = clock();

    for (i = 0; i <= MAX; i++)
        Prime[i] = true;
    Prime[0]=Prime[1]=false;

    for (i = 2; i <= (int)sqrt(MAX); i++) {

        if (Prime[i] == true)

            for (k = i + 1; k <= MAX; k++) {
                if (Prime[k]==true)
                    if (k % i == 0)
                        Prime[k] = false;
            }
    }

    for (i = 0, sum = 0; i <= MAX; i++) {
        if (Prime[i] == true)
            sum++;
    }

    end = clock();

    printf("have %d prime number\n", sum);
    printf("Spend %.4lf Seconds", (double) (end-start) / CLOCKS_PER_SEC);

//    for (i = 0, k = 1; i <= MAX; i++) {
//        if (Prime[i] == true) {
//            printf("% d ", i);
//            k++;
//        }
//
//    }

    return 0;
}
