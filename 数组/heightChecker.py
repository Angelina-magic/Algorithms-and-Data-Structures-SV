# 1051. 高度检查器
# 学校在拍年度纪念照时，一般要求学生按照 非递减 的高度顺序排列。
# 请你返回能让所有学生以 非递减 高度排列的最小必要移动人数。
# 注意，当一组学生被选中时，他们之间可以以任何可能的方式重新排序，而未被选中的学生应该保持不动。
# 来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/height-checker
class Solution:
    # def heightChecker(self, heights: List[int]) -> int:
    def heightChecker_BF(self, heights):
        ruc = sorted(heights)
        res = 0
        n = len(heights)
        for a in range(n):
            if ruc[a] != heights[a]:
                res += 1
        return res

    def heightChecker(self, heights):
        ruc = [0 for i in range(101)]
        for a in heights:  # 建立一个数组来存储每个数字的个数
            ruc[a] += 1

        k, res = 0, 0
        for i in range(1, 101):
            while ruc[i]:  # 通过判断相应坐标下是否有相同的该有的数值来判断是否需要替换数组的值
                if heights[k] != i:
                    res += 1
                k += 1
                ruc[i] -= 1
        return res
