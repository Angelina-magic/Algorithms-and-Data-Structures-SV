# 1266. 访问所有点的最小时间
# 平面上有 n 个点，点的位置用整数坐标表示 points[i] = [xi, yi]。请你计算访问所有这些点需要的最小时间（以秒为单位）。
# 你可以按照下面的规则在平面上移动：
# 每一秒沿水平或者竖直方向移动一个单位长度，或者跨过对角线（可以看作在一秒内向水平和竖直方向各移动一个单位长度）。
# 必须按照数组中出现的顺序来访问这些点。
# 来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/minimum-time-visiting-all-points
class Solution:
    # def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
    def minTimeToVisitAllPoints(self, points):
        res = 0
        for i in range(len(points) - 1):
            j = i + 1
            dx, dy = abs(points[i][0] - points[j][0]), abs(points[i][1] - points[j][1])
            res += max(dx, dy)
        return res


nums = [[1, 1], [3, 4], [-1, 0]]
a = Solution()
print(a.minTimeToVisitAllPoints(nums))
