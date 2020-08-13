# 999. 可以被一步捕获的棋子数
# 在一个 8 x 8 的棋盘上，有一个白色的车（Rook），用字符 'R' 表示。棋盘上还可能存在空方块，白色的象（Bishop）以及黑色的卒（pawn），
# 分别用字符 '.'，'B' 和 'p' 表示。不难看出，大写字符表示的是白棋，小写字符表示的是黑棋。
# 车按国际象棋中的规则移动。东，西，南，北四个基本方向任选其一，然后一直向选定的方向移动，直到满足下列四个条件之一：
# 棋手选择主动停下来。
# 棋子因到达棋盘的边缘而停下。
# 棋子移动到某一方格来捕获位于该方格上敌方（黑色）的卒，停在该方格内。
# 车不能进入/越过已经放有其他友方棋子（白色的象）的方格，停在友方棋子前。
# 你现在可以控制车移动一次，请你统计有多少敌方的卒处于你的捕获范围内（即，可以被一步捕获的棋子数）。
# 来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/available-captures-for-rook
class Solution:
    def numRookCaptures(self, board):
        ans = 0  # 计数器
        # 标记车(Rook)的位置
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == "R":
                    a, b = i, j
                    break

        # 预先建立一个Rook的移动方向
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]

        # for循环是用来遍历每一个方向上的情况,通过i来映射方向
        for i in range(len(dx)):
            x, y = a, b
            # 通过while循环来模拟Rook的运动方式
            while -1 < x < 8 and -1 < y < 8:
                if board[x][y] == "B":
                    break
                elif board[x][y] == "p":
                    ans += 1
                    break
                else:
                    x, y = x + dx[i], y + dy[i]
        return ans
