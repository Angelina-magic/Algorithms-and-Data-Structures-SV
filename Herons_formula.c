#include <stdio.h>
#include <math.h>

double Heron(double a, double b, double c) {
    double s, p;
    p = (a+b+c)/2;
    s = sqrt(p*(p-a)*(p-b)*(p-c));

    return s;
}

int main() {
    double a, b, c;

    printf("a b c:");
    scanf("%lf %lf %lf", &a, &b, &c);

    printf("the area of the delta is %.2lf", Heron(a, b, c));

    return 0;
}
