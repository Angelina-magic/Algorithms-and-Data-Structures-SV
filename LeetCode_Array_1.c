// 暴力算法，通过两边循环实现对每一个数的相加。算法的时间复杂度为O(n!),空间复杂度为O(1)。
int* twoSum_BF(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    int *ret = (int *)malloc(2*sizeof(int));
    for(i = 0; i < numsSize; ++i) {
        for(j = numsSize-1; j > i; --j) {
            if(nums[i]+nums[j]==target) {
                
                ret[0] = i, ret[1] = j, *returnSize = 2;
                return ret;
            }
        }
    }   
    return ret; 
}
