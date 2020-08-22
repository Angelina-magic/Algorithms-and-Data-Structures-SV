//121. 买卖股票的最佳时机
//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
//注意：你不能在买入股票前卖出股票。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
int maxProfit(int* prices, int pricesSize){
    if(pricesSize == 0) {
        return 0;
    }

    int f[pricesSize][2];
    f[0][0] = -prices[0];
    f[0][1] = 0;

    for(int i = 1; i < pricesSize; i++) {
        
        f[i][0] = fmax(-prices[i], f[i-1][0]);  //在#include<math.h>头文中，fmax()函数的作用是返回两个数的最大值。
        f[i][1] = fmax(f[i-1][0] + prices[i], f[i-1][1]);
    }

    if(f[pricesSize-1][1] <= 0) {
        return 0;
    } else {
        return f[pricesSize-1][1];
    }
}
