//658. 找到 K 个最接近的元素
//给定一个排序好的数组，两个整数 k 和 x，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。如果有两个数与 x 的差值一样，优先选择数值较小的那个数。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/find-k-closest-elements
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize){
    *returnSize = k;
    int left = 0;
    int right = arrSize - 1;
    while (right - left >= k) {
        if (x * 2 <= arr[right] + arr[left]) {
            --right;
        } else {
            ++left;
        }
    }
    return &arr[left];
}
