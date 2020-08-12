# 48. 旋转图像
# 给定一个 n × n 的二维矩阵表示一个图像。
# 将图像顺时针旋转 90 度。
# 说明：
# 你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
# 来源：力扣（LeetCode）
# 链接：https://leetcode-cn.com/problems/rotate-image
class Solution:
    # def rotate(self, matrix: List[List[int]]) -> None:
    # Do not return anything, modify matrix in-place instead.
    def rotate(self, matrix):
        n = len(matrix[0])

        # 将矩阵转置
        for i in range(n):
            for j in range(i, n):
                matrix[j][i], matrix[i][j] = matrix[i][j], matrix[j][i]

        # 将矩阵每一行反转
        for i in range(n):
            matrix[i].reverse()


nums = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
a = Solution()
a.rotate(nums)
print(nums)
