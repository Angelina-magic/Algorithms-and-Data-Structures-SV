// 欧几里得算法
#include<stdio.h>

unsigned int Gcd(unsigned int M,unsigned int N)
{
    unsigned int S;// submultiple 约数
    while(N > 0)
    {
        S = M % N;
        M = N;
        N = S;
    }
    return M;
}

int main(void)
{
    int a,b;
    
    printf("a:");
    scanf("%d", &a);
    printf("b:");
    scanf("%d", &b);
    
    printf("the greatest common factor of %d and %d is %d\n", a, b, Gcd(a,b));
    
    return 0;
}
