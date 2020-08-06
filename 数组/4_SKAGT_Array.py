# 1343. 大小为 K 且平均值大于等于阈值的子数组数目
# 给你一个整数数组 arr 和两个整数 k 和 threshold 。
# 请你返回长度为 k 且平均值大于等于 threshold 的子数组数目。
# 来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold

class Solution:
    # def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:

    def numOfSubarrays(self, arr, k, threshold):
        if len(arr) < k:
            return 0

        target = k * threshold
        j, Addres = 0, sum(arr[:k])
        if Addres >= target:
            j += 1

        for i in range(k, len(arr)):
            Addres += arr[i] - arr[i-k]  # 滑动窗口
            if Addres >= target:
                j += 1
        return j

nums = [11, 13, 17, 23, 29, 31, 7, 5, 2, 3]
m, n = 3, 5
a = Solution()
print(a.numOfSubarrays(nums, m, n))
