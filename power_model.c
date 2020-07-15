#include <stdio.h>

unsigned long long power_mod(unsigned long long a, unsigned long long n, unsigned long long m) {
    unsigned long long i = 1, ans = 1;
    for (; i <= n; ++i) {
        ans = (ans*a)%m;
    }
    return ans;
}

int main() {
    unsigned long long a, m, n;

    printf("Input a and n and m:");
    scanf("%llu %llu %llu", &a, &n, &m);

    printf("%llu", power_mod(a, n, m));

    return 0;
}
