//53. 最大子序和
//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
int maxSubArray(int* nums, int numsSize){
    int sum = 0;
    int ans = nums[0];
    for(int i = 0;i < numsSize;i++){
        sum += nums[i];
        if(ans < sum)
            ans = sum;
        if(sum <= 0){
            sum = 0;
        }
    }
    return ans;
}
