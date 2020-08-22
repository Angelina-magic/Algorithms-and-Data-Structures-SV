//198. 打家劫舍
//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
//影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
//如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/house-robber
int rob(int* nums, int numsSize) {

    if(!numsSize) {
        return 0;
    }

    int dp[numsSize][2];
    dp[0][0] = 0;
    dp[0][1] = nums[0];

    for(int i=1;i<numsSize;i++) {
        dp[i][1] = nums[i] + dp[i-1][0];
        dp[i][0] = dp[i-1][0]>dp[i-1][1]?dp[i-1][0]:dp[i-1][1];
    }
    return dp[numsSize-1][0] > dp[numsSize-1][1] ? dp[numsSize-1][0] : dp[numsSize-1][1];
}
