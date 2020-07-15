//设m是大于1的正整数，a、b是整数，如果(a-b)|m，则称a与b关于模m同余，记作a≡b(mod m)，读作a与b对模m同余。
//
//（1）若a≡0(mod m)，则a|m；
//（2）a≡b(mod m)等价于a与b分别用m去除，余数相同。
//同余的性质主要有：
//（1）对于同一个除数，两数的和（或差）于他们余数的和（或差）同余数。
//（2）对于同一个除数，两数的乘积与他们余数的乘积同余。
//（3）对于同一个除数，如果两个整数同余，那么他们的差就一定能被这个数整除。
//（4）对于同一个除数，如果两个整数同余，那么他们的乘方仍然同余。
//      解答同余类型题目的关键是灵活运用性质，把求一个比较大的数字除以某数的余数问题转化为求一个较小数除以这个数的余数，使复杂的问题变得简单化。
#include<stdio.h>
#include<string.h>

unsigned long long mod(char *a, unsigned long long m) {

    unsigned long long len = strlen(a), ans = 0;
    for (int i = 0; i < len; ++i) {
        ans = ((a[i]-'0')+ 10*ans)%m;
    }
    return ans;
}

int main(void) {
    char a[100];
    unsigned long long b, m;

    printf("Input a:");
    gets(a);
    printf("Input m:");
    scanf("%llu", &m);

    b = mod(a, m);
    printf("%llu", b);
    return 0;
}
