# 26. 删除排序数组中的重复项
# 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
# 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
# 来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
class Solution:
    # def removeDuplicates(self, nums: List[int]) -> int:
    def removeDuplicates_1(self, nums):
        i, j = 0, 1
        while i < len(nums) - 1:
            if nums[i] == nums[j]:
                del nums[j]
                continue
            i += 1
            j += 1
        return len(nums)

    def removeDuplicates_2(self, nums):
        a = 0
        for i, digits in enumerate(nums[1:]):
            if digits != nums[a]:
                a += 1
                nums[i+1] = nums[a]
                nums[a] = digits
        return a+1


nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
a = Solution()
print(a.removeDuplicates_1(nums))
arr = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
print(a.removeDuplicates_2(arr))
