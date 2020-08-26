// 判断矩形是否与圆相交
#define Max(x, y) x>y ? x:y
#define Min(x, y) x<y ? x:y

typedef struct point {
    double x;
    double y;
} Point;
// 以矩形的中心为坐标原点来建立坐标系，这样就只需要一个点(在第一象限)就可以描述矩形
typedef struct ret {
    Point A;
} Ret;

typedef struct circle {
    Point K;
    double r;
} Circle;

// 建立一个边界矩形，圆心只要不在边界矩形内，那么就不会与矩形相交
bool is_intersection(Ret anc, Circle vin) {
    anc.A.x += vin.r, anc.A.y += vin.r;
    vin.K.x = fabs(vin.K.x), vin.K.y = fabs(vin.K.y);
    if(vin.K.x>anc.A.x||vin.K.y>anc.A.y) {
        return true;
    } else {
        return false;
    }
}
