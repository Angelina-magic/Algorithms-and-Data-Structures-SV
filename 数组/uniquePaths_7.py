# 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
# 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
# 问总共有多少条不同的路径？
# 来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/unique-paths
class Solution:
    # def uniquePaths(self, m: int, n: int) -> int:
    def uniquePaths_1(self, m, n):
        res = [[1]*n] + [[1] + [0]*(n-1) for _ in range(m-1)]
        # print(res)
        for i in range(1, m):
            for j in range(1, n):
                res[i][j] = res[i-1][j] + res[i][j-1]
        return res[m-1][n-1]

    def uniquePaths_2(self, m, n):
        res = [1]*n
        dp = [1]*n
        for i in range(1, m):
            for j in range(1, n):
                res[j] = dp[j] + res[j-1]
            dp = res[:]
        return res[-1]

    def uniquePaths_3(self, m, n):
        res = [1]*n

        for i in range(1, m):
            for j in range(1, n):
                res[j] = res[j] + res[j-1]

        return res[-1]


m, n = 3, 3
a = Solution()
print(a.uniquePaths_1(m, n))
print(a.uniquePaths_2(m, n))
print(a.uniquePaths_3(m, n))
