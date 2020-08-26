// 点到线段的最短距离
double PointToSegDist(double x, double y, double x1, double y1, double x2, double y2) {
    double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
    if (cross <= 0) 
        return Math.Sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));

    double d2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    if (cross >= d2) 
        return Math.Sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));

    double r = cross / d2;
    double px = x1 + (x2 - x1) * r;
    double py = y1 + (y2 - y1) * r;
    return Math.Sqrt((x - px) * (x - px) + (py - y) * (py - y));
}
