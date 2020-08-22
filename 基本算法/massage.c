//面试题 17.16. 按摩师
//一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。
//在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。
//给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。
//注意：本题相对原题稍作改动
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/the-masseuse-lcci
int Max(int a,int b){
    return (a>b)?a:b;
}
int massage(int* nums, int numsSize){
    if(numsSize==0)
        return 0;
    if(numsSize==1)
        return nums[0];
    int *dp=(int*)malloc(sizeof(int)*numsSize);
    dp[0]=nums[0];
    dp[1]=Max(nums[0],nums[1]);
    int i;
    for(i=2;i<numsSize;i++){
        dp[i]=Max(dp[i-2]+nums[i],dp[i-1]);
    }
    return dp[i-1];
}
