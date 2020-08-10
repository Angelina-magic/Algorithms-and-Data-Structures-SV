# 674. 最长连续递增序列
# 给定一个未经排序的整数数组，找到最长且连续的的递增序列，并返回该序列的长度。
class Solution:
    # def findLengthOfLCIS(self, nums: List[int]) -> int:
    def findLengthOfLCIS(self, nums):
        ans, anchor = 0, 0
        for i in range(len(nums)):
            if i and nums[i-1]>=nums[i]:
                anchor = i
            ans = max(ans, i-anchor+1)
        return ans
