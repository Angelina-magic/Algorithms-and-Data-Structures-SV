# 1122. 数组的相对排序
# 给你两个数组，arr1 和 arr2，
# arr2 中的元素各不相同
# arr2 中的每个元素都出现在 arr1 中
# 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。
# 来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/relative-sort-array
import collections
class Solution:
    # def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
    def relativeSortArray(self, arr1, arr2):
    
        # 将arr1 counter计数，按照arr2来取
        arr = []
        count = collections.Counter(arr1)

        # 按照arr2将arr1的元素存入li
        for num in arr2:
            if num in count:
                i = count[num]
                for i in range(i):
                    arr.append(num)
            # 被存的元素删除掉
            del count[num]
            
        # 剩下的元素排序放到末尾
        arr += sorted(list(count.elements()))
        return arr


arr1 = [2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19]
arr2 = [2, 1, 4, 3, 9, 6]
a = Solution()
print(a.relativeSortArray(arr1, arr2))
