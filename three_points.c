//三点顺序(三个点的顺序问题)
//每行是一组测试数据，有6个整数x1,y1,x2,y2,x3,y3分别表示A,B,C三个点的横纵坐标。（坐标值都在0到10000之间）
//输入0 0 0 0 0 0表示输入结束
//测试数据不超过10000组
// 如果这三个点是顺时针给出的，请输出1，逆时针给出则输出0
#include <stdio.h>
#include <math.h>

typedef struct { double x; double y;} COD;

int three_points(COD a, COD b, COD c) {
    COD ab, bc;
    double vector_cos, angle, vector_sin;

    //将坐标化为向量
    ab.x = b.x - a.x, ab.y = b.y - a.y;
    bc.x = c.x - b.x, bc.y = c.y - b.y;

    //使用余弦定理求cos再求正弦
    vector_cos = (ab.x*bc.x + ab.y*bc.y)/sqrt((pow(ab.x, 2)+pow(ab.y, 2))*(pow(bc.x, 2)+pow(bc.y, 2)));
    angle = acos(vector_cos);
    vector_sin = sin(angle);

    if (vector_sin) {
        if (vector_sin>0)
            return 1;
        else
            return 0;
    } else {
        printf("this isn't a delta!  ");
        return -1;
    }
}

int main() {
    COD a, b, c;

    printf("x1 y1 x2 y2 x3 y3: ");
    scanf("%lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);

    printf("%d", three_points(a, b, c));
    return 0;
}
