//704. 二分查找
//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/binary-search
int search(int* nums, int numsSize, int target)
{
    int low=0,high=numsSize-1;//定义high和low以便于查找
    int mid;
    while(low<=high)//循环开始-
    {
        mid=(low+high)/2;
        if(nums[mid]==target)
            return mid;//首先判断其是否在中间相等
        else {if(nums[mid]>target) high=mid-1;//大于就让high成为mid-1
        else low=mid+1;}//小于让mid+1
    }//二分查找循环结束，最后return的一定是mid
    return(-1);
}
