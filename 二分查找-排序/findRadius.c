//475. 供暖器
//冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
//现在，给出位于一条水平线上的房屋和供暖器的位置，找到可以覆盖所有房屋的最小加热半径。
//所以，你的输入将会是房屋和供暖器的位置。你将输出供暖器的最小加热半径。
//说明:
//给出的房屋和供暖器的数目是非负数且不会超过 25000。
//给出的房屋和供暖器的位置均是非负数且不会超过10^9。
//只要房屋位于供暖器的半径内(包括在边缘上)，它就可以得到供暖。
//所有供暖器都遵循你的半径标准，加热的半径也一样。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/heaters
int comp(const void*a,const void*b)//用来做比较的函数。
{
    return *(int*)a-*(int*)b;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){
    int i,j,d1,d2= 0,lastj=0,tmp;

    qsort(houses,housesSize,sizeof(int),comp);
    qsort(heaters,heatersSize,sizeof(int),comp);

    for(i=0;i<housesSize;i++){
        d1 = abs(houses[i]-heaters[lastj]);
        for(j=lastj;j<heatersSize;j++){
            tmp = abs(houses[i]-heaters[j]);    //获得houses[i]与heaters[j]之间的距离。
            if(tmp < d1){
                d1 = tmp;   //获得houses[i]与heaters中最近的距离d1。
                lastj = j;
            }
            if(heaters[j] > houses[i])
                break;
        }
        if(d1 > d2)
            d2 = d1;    //获得所有house[i]能获得供暖的最小加热半径。
    }
    return d2;
}
