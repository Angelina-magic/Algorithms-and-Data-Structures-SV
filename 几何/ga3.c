// 判断点是否在矩形内
#define Max(x, y) x>y ? x:y
#define Min(x, y) x<y ? x:y

typedef struct point {
    double x;
    double y;
} Point;

typedef struct ret {
    Point A;
    Point C;
} Ret;

bool is_inRet(Ret anc, Point a) {
    if(a.x<Max(anc.A.x, anc.C.x)&&a.x>Min(anc.A.x, anc.C.x)&&a.y<Max(anc.A.y, anc.C.y)&&a.y>Min(anc.A.y, anc.C.y)) {
        return true;
    } else {
        return false;
    }
}
