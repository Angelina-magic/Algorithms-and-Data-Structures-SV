//1518. 换酒问题
//小区便利店正在促销，用 numExchange 个空酒瓶可以兑换一瓶新酒。你购入了 numBottles 瓶酒。
//如果喝掉了酒瓶中的酒，那么酒瓶就会变成空的。
//请你计算 最多 能喝到多少瓶酒。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/water-bottles
int numWaterBottles(int numBottles, int numExchange){

    int empty = numBottles;
    int sum = numBottles;
    while(empty >= numExchange) {
        
        numBottles = empty / numExchange;   //更新还可以喝几瓶
        empty = empty % numExchange+numBottles; //更新空瓶的数量
        sum += numBottles;    //计算一共可以喝几瓶
    }
    return sum;
}
