//面试题 08.03. 魔术索引
//魔术索引。 在数组A[0...n-1]中，有所谓的魔术索引，满足条件A[i] = i。给定一个有序整数数组，编写一种方法找出魔术索引，若有的话，
//在数组A中找出一个魔术索引，如果没有，则返回-1。若有多个魔术索引，返回索引值最小的一个。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/magic-index-lcci
int getAnswer(int* nums, int left, int right) {
    if (left > right) {
        return -1;
    }
    int mid = (right - left) / 2 + left;
    int leftAnswer = getAnswer(nums, left, mid - 1);
    if (leftAnswer != -1) {
        return leftAnswer;
    } else if (nums[mid] == mid) {
        return mid;
    }
    return getAnswer(nums, mid + 1, right);
}

int findMagicIndex(int* nums, int numsSize) {
    return getAnswer(nums, 0, numsSize - 1);
}
