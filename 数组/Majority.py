# 229. 求众数 II
# 给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
# 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
import collections
class Solution:
    # def majorityElement(self, nums: List[int]) -> List[int]:
    def majorityElement(self, nums):
        maj = collections.Counter(nums)
        res = []
        for i in maj.keys():
            if maj[i] > len(nums)//3:
                res.append(i)
        return res


arr = [1, 1, 1, 3, 3, 2, 2, 2]
a = Solution()
print(a.majorityElement(arr))
