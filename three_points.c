//三点顺序(三个点的顺序问题)
//每行是一组测试数据，有6个整数x1,y1,x2,y2,x3,y3分别表示A,B,C三个点的横纵坐标。（坐标值都在0到10000之间）
//输入0 0 0 0 0 0表示输入结束
//测试数据不超过10000组
// 如果这三个点是顺时针给出的，请输出1，逆时针给出则输出0
#include <stdio.h>

typedef struct { double x; double y;} COD;

int three_points(COD a, COD b, COD c) {
    COD ab, bc;
    double vector_project;

    //将坐标化为向量
    ab.x = b.x - a.x, ab.y = b.y - a.y;
    bc.x = c.x - b.x, bc.y = c.y - b.y;

    //直接通过向量积的定义求解
    vector_project = ab.x * bc.y - ab.y * bc.x;
    if (vector_project > 0) {
        return 0;
    } else if (vector_project < 0) {
        return 1;
    }
}

int main() {
    COD a, b, c;

    printf("x1 y1 x2 y2 x3 y3: ");
    scanf("%lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);

    while(a.x||a.y||b.x||b.y||c.x||c.y){
        printf("%d\n", three_points(a, b, c));

        printf("x1 y1 x2 y2 x3 y3: ");
        scanf("%lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
    }

    return 0;
}
