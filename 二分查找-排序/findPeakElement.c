//162. 寻找峰值
//峰值元素是指其值大于左右相邻值的元素。
//给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
//数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
//你可以假设 nums[-1] = nums[n] = -∞。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/find-peak-element
int findPeakElement(int* nums, int numsSize){
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;

    while(left < right) {
        mid = (left + right) / 2;  
        if(nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}
