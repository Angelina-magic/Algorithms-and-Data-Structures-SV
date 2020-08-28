// 计算多边形的面积
struct Point2d
{
    double x;
    double y;
    Point2d(double xx, double yy): x(xx), y(yy){}
};
 
//计算任意多边形的面积，顶点按照顺时针或者逆时针方向排列
double ComputePolygonArea(const vector<Point2d> &points)
{
    int point_num = points.size();
    if(point_num < 3)return 0.0;
    double s = points[0].y * (points[point_num-1].x - points[1].x);
    for(int i = 1; i < point_num; ++i)
        s += points[i].y * (points[i-1].x - points[(i+1)%point_num].x);
    return fabs(s/2.0);
}
