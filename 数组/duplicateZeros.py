# 1089. 复写零
# 给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。
# 注意：请不要在超过该数组长度的位置写入元素。
# 要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。
# 来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/duplicate-zeros
class Solution:
    # def duplicateZeros(self, arr: List[int]) -> None:
    def duplicateZeros(self, arr):
        n = len(arr)
        k = 0

        # 记录有效的0的个数
        for pos, num in enumerate(arr):
            if num == 0:
                k += 1
            if pos + 1 + k >= n - 1:  # 当增加的0的个数大于数组的长度时候就跳出循环 pos+1是为了防止出现后几位全是0的情况出现
                break
        if k == 0:
            return

        # 双指针  i指向被"消除"的数值的前一位（快指针）  j指向最后一位（慢指针）
        i = n - 1 - k
        j = n - 1
        if pos + 1 + k == n - 1:
            arr[j] = arr[i]
            i -= 1
            j -= 1
        while k:  # 逆序遍历
            arr[j] = arr[i]
            j -= 1
            if arr[i] == 0:
                arr[j] = 0
                j -= 1
                k -= 1
            i -= 1


nums = [1, 0, 2, 3, 0, 4, 5, 0]
cat = Solution()
cat.duplicateZeros(nums)
print(nums)
