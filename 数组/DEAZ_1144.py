# 1144. 递减元素使数组呈锯齿状
# 给你一个整数数组 nums，每次 操作 会从中选择一个元素并 将该元素的值减少 1。
# 如果符合下列情况之一，则数组 A 就是 锯齿数组：
# 每个偶数索引对应的元素都大于相邻的元素，即      A[0] > A[1] < A[2] > A[3] < A[4] > ...
# 或者，每个奇数索引对应的元素都大于相邻的元素，即 A[0] < A[1] > A[2] < A[3] > A[4] < ...
# 返回将数组 nums 转换为锯齿数组所需的最小操作次数。
# 来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/decrease-elements-to-make-array-zigzag
class Solution:
    # def movesToMakeZigzag(self, nums: List[int]) -> int:
    def movesToMakeZigzag(self, nums):
        n = len(nums)
        res1, res2 = 0, 0
        for i in range(n):
            # 偶数位置为锯齿尖端
            if i % 2:
                d1 = nums[i] - nums[i - 1] + 1 if nums[i] >= nums[i - 1] else 0
                d2 = nums[i] - nums[i + 1] + 1 if i < n - 1 and nums[i] >= nums[i + 1] else 0
                res1 += max(d1, d2)
            # 奇数位置为锯齿尖端
            else:
                d1 = nums[i] - nums[i - 1] + 1 if i > 0 and nums[i] >= nums[i - 1] else 0
                d2 = nums[i] - nums[i + 1] + 1 if i < n - 1 and nums[i] >= nums[i + 1] else 0
                res2 += max(d1, d2)

        return min(res1, res2)


arr = [0, 0, 0, 0]
a = Solution()
print(a.movesToMakeZigzag(arr))
