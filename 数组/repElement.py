# 1299. 将每个元素替换为右侧最大元素
# 给你一个数组arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 - 1替换。
# 完成所有替换操作后，请你返回这个数组。
class Solution:
    # def replaceElements(self, arr: List[int]) -> List[int]:
    def replaceElements_1(self, arr):
        n = len(arr)
        ret = [0] * n
        for i in range(n - 2, -1, -1):
            ret[i] = ret[i+1] if ret[i+1]>arr[i+1] else arr[i+1]
        ret[n-1] = -1
        return ret


nums = [17, 18, 5, 4, 6, 1]
a = Solution()
print(a.replaceElements(nums))
