# 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
# 注意：答案中不可以包含重复的三元组。
class Solution:
    # def threeSum(self, nums: List[int]) -> List[List[int]]:

    def threeSum(self, nums):
        ret = []
        if len(nums) < 3:
            return []
        elif len(nums) == 3:
            if sum(nums) == 0:
                ret.append([nums[0], nums[1], nums[2]])
                return ret
            else:
                return []

        nums.sort()

        for i in range(len(nums) - 3):
            if nums[i] > 0 or nums[i] == nums[i-1] and i-1 >= 0:  # 显然当我们以i为最左端时，如果i>0那么                                                    
                continue                                            # 结果将必不可能为0；同时还要判断是否i与它前面的数的大小相同，以防止结果出现相同的数组
            j = i + 1
            k = len(nums) - 1

            while j < k:  # 显然我们只需要满足nums[j] + nums[k] == -nums[i]即可，
                if nums[j] + nums[k] > -nums[i]:  # 由于数组是已经排序了的，因此该我们只需要判断等式左右两边的关系就可以了，如果是左边大于右边显然只能将k向左移动以减小k的值以达到平衡
                    k -= 1
                elif nums[j] + nums[k] < -nums[i] or nums[j] == nums[j-1] and j > i+1:
                    j += 1
                else:
                    ret.append([nums[i], nums[j], nums[k]])
                    j += 1
        return ret


List = [0, -4, -1, -4, -2, -3, 2]
a = Solution()
print(a.threeSum(List))
