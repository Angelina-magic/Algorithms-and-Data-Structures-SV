/*
1043. 分隔数组以得到最大和

给出整数数组 A，将该数组分隔为长度最多为 K 的几个（连续）子数组。分隔完成后，每个子数组的中的值都会变为该子数组中的最大值。

返回给定数组完成分隔后的最大和。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-array-for-maximum-sum
*/
int Max(int a, int b) {
    return a > b ? a : b;
}

int maxSumAfterPartitioning(int* A, int ASize, int K){
    if (ASize  == 0) {
        return 0;
    }
    if (K > ASize) {
        K = ASize;
    }
    int maxK = 0;
    int dp[ASize];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < ASize; i++) {
        if (i < K) {
            maxK = Max(maxK, A[i]);
            dp[i] = maxK * (i + 1);
            continue;
        }
        maxK = A[i];
        for (int j = 0; j < K; j++) {
            maxK = Max(maxK, A[i - j]);
            dp[i] = Max(dp[i], dp[i - j - 1] + maxK * (j + 1));
        }
    }
    return dp[ASize - 1];
}
