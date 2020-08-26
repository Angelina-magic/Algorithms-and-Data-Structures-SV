// 判断线段是否相交
#include"stdio.h"
#include"string.h"
#include "math.h"
#include"stdlib.h"
#define M 101
#define inf 999999999
#define eps 1e-10

typedef struct node
{
    double x, y;
} P;
typedef struct line{
    P s;
    P e;
} Line;
Line L[M];
double max(double x, double y)
{
    return x>y?x:y;
}
double min(double x,double y)
{
    return x<y?x:y;
}
int paichi(Line a,Line b)//快速排斥，若通过快速排斥进行跨立实验，否则无交点;
{
    if(max(a.e.x,a.s.x)>=min(b.s.x,b.e.x)&&max(b.s.x,b.e.x)>=min(a.s.x,a.e.x)&&max(a.s.y,a.e.y)>=min(b.s.y,b.e.y)&&max(b.s.y,b.e.y)>=min(a.s.y,a.e.y))
        return 1;
    else
        return 0;
}
double cross(P a,P b,P c)//叉积
{
    double x1=b.x-a.x;
    double y1=b.y-a.y;
    double x2=c.x-a.x;
    double y2=c.y-a.y;
    return x1*y2-x2*y1;
}
int kuali(Line a,Line b)//跨立实验(通过相互跨立则可确定两线段相交返回1 )
{
    if(cross(a.s,a.e,b.s)*cross(a.s,a.e,b.e)<=0
    &&cross(b.s,b.e,a.s)*cross(b.s,b.e,a.e)<=0)
        return 1;
    else
        return 0;
}
