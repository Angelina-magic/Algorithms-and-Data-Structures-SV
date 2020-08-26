//求凸包
int dist(int x1,int y1,int x2,int y2) //求距离
{
    return int(pow(double(x2-x1),2)+pow(double(y2-y1),2));
}
 
int mul_cross(int x1,int y1,int x2,int y2) //求叉乘
 
{
    return(x1*y2-x2*y1);
}
void find_1() //找左下角的点
{
    x[0]=2147483647;
    y[0]=2147483647;
    root=0;
    for (int i=1;i<=n;i++)
        if (x[i]<x[root]||(x[i]==x[root]&&y[i]<y[root]))
            root=i;
}
void find_2() //找凸包
{
    int last=root;
    while (true)
    {
        a[++tot]=last;
        int now=1;
        if (now==last) now++;
        for (int i=1;i<=n;i++)
            if (last!=i&&mul_cross(x[now]-x[last],y[now]-y[last],x[i]-x[last],y[i]-y[last])<0||(mul_cross(x[now]-x[last],y[now]-y[last],x[i]-x[last],y[i]-y[last])==0&&dist(x[i],y[i],x[last],y[last])<dist(x[now],y[now],x[last],y[last]))
                now=i;
        last=now;
        if (last==root) break;
    }
}
