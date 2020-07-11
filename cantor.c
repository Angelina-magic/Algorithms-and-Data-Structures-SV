// 设有n个数（1，2，3，4,…,n），可以有组成不同(n!种)的排列组合，康托展开表示的就是是当前排列组合在n个不同元素的全排列中的名次。
// X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!+...+a[1]*0!
// 其中, a[i]为整数，并且0 <= a[i] <= i, 0 <= i < n, 表示当前未出现的的元素中排第几个，这就是康托展开。
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long long Fac(unsigned long long len) {
    unsigned long long sum, i;
    for (i = 1, sum = 1; i <= len; ++i) {
        sum *= i;
    }
    return sum;
}

unsigned long long cantor(int *list, unsigned long long len) {
    unsigned long long sum, i, s, k;

    sum = 0;
    for (i = 0; i < len; ++i)
    {
        for (k = i, s = 0; k < len; ++k)
        {
            if (list[i]>list[k])
                ++s;
        }
        sum += s*Fac(len-i-1);
    }

    return sum;
}

int main() {
    char *ch, c;
    unsigned long long len, i, sum;
    int *list;
    int k;

//    ch = (char *)malloc(20*sizeof(char));
//    printf("Input:");
//    scanf("%s", ch);
//    len = strlen(ch);

    printf("press the max of the cantor:");
    scanf("%llu", &len);
    list = (int *)malloc(len*sizeof(int));

    k = 0;printf("input 'q' to quit!!!\ninput:");
    while (scanf("%d", &list[k]))
    {
        printf("input:");
        k ++;
    }

//    for (i = 0; i < len; i++) {
//        list[i] = ch[i] - '0';
//    }

    printf("Output:%llu", cantor(list, len));
    return 0;
}
