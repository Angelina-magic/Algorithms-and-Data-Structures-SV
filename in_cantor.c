//康托展开是一个全排列到一个自然数的双射，因此是可逆的。
//即对于上述例子，在（1，2，3，4，5）给出61可以算出起排列组合为 34152。由上述的计算过程可以容易的逆推回来，具体过程如下：
//用 61 / 4! = 2余13，说明a[5]=2,说明比首位小的数有2个，所以首位为3。
//用 13 / 3! = 2余1，说明a[4]=2，说明在第二位之后小于第二位的数有2个，所以第二位为4。
//用 1 / 2! = 0余1，说明a[3]=0，说明在第三位之后没有小于第三位的数，所以第三位为1。
//用 1 / 1! = 1余0，说明a[2]=1，说明在第二位之后小于第四位的数有1个，所以第四位为5。
//最后一位自然就是剩下的数2啦。
//通过以上分析，所求排列组合为 34152。

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//求阶乘
unsigned long long Fac(unsigned long long len) {
    unsigned long long sum, i;
    for (i = 1, sum = 1; i <= len; ++i) {
        sum *= i;
    }
    return sum;
}

//康托展开的逆过程
int* Incantor(int len, unsigned long long seq) {
    unsigned long long fac, rem;
    int *a;
    bool *v;
    int i, k, t, h;

    a = (int *)malloc(len*sizeof(int));
    v = (bool *)malloc(len*sizeof(bool));

    for (i = 0; i < len; ++i) {
        v[i] = true;
    }

    for (i = len, h = 0; i > 0; --i) {
        fac = Fac(i-1);
        rem = seq/fac;
        seq = seq%fac;

        k = 0, t = 0;
        do {
            if (k == rem&&v[t]) {
                a[h] = t+1;
                v[t] = false;
                ++h;
                break;
            }
            else {
                if (v[t++]) {
                    ++k;
                }
            }
        } while (t < len);
    }

    return a;
}

int main() {
    unsigned long long seq;
    int *list;
    int k, len;

    printf("Input the number:");
    scanf("%llu", &len);
    printf("the sequence:");
    scanf("%llu", &seq);

    printf("the list of the number:\n");
    list = Incantor(len, seq);
    for (k = 0; k < len; ++k) {
        printf(" %d ", list[k]);
    }

    return 0;
}
