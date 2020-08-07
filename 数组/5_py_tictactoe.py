# 井字游戏  16.04
# 设计一个算法，判断玩家是否赢了井字游戏。输入是一个 N x N 的数组棋盘，由字符" "，"X"和"O"组成，其中字符" "代表一个空位。
# 以下是井字游戏的规则：
# 玩家轮流将字符放入空位（" "）中。
# 第一个玩家总是放字符"O"，且第二个玩家总是放字符"X"。
# "X"和"O"只允许放置在空位中，不允许对已放有字符的位置进行填充。
# 当有N个相同（且非空）的字符填充任何行、列或对角线时，游戏结束，对应该字符的玩家获胜。
# 当所有位置非空时，也算为游戏结束。
# 如果游戏结束，玩家不允许再放置字符。
# 如果游戏存在获胜者，就返回该游戏的获胜者使用的字符（"X"或"O"）；如果游戏以平局结束，则返回 "Draw"；如果仍会有行动（游戏未结束），则返回 "Pending"。
# 来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/tic-tac-toe-lcci
class Solution:
    # def tictactoe(self, board: List[str]) -> str:
    def tictactoe(self, board):
        n = len(board)

        def check(c):
            s = c * n
            return any((
                any(row == s for row in board),  # 1>. any() 函数用于判断给定的可迭代参数 iterable 是否全部为 False，则返回 False，如果有一个为
                # True，则返回 True。元素除了是 0、空、FALSE 外都算 TRUE。
                # 2>. map() 会根据提供的函数对指定序列做映射。第一个参数 function 以参数序列中的每一个元素调用
                # function 函数，返回包含每次 function 函数返回值的新列表。
                # 3>. zip() 函数用于将可迭代的对象作为参数，将对象中对应的元素打包成一个个元组，然后返回由这些元组组成的对象，这样做的好处是节约了不少的内存。我们可以使用 list(
                # )转换来输出列表。如果各个迭代器的元素个数不一致，则返回列表长度与最短的对象相同，利用 * 号操作符，可以将元组解压为列表。
                any(col == s for col in map(''.join, zip(*board))),
                all(board[i][i] == c for i in range(n)),
                # 4>. all() 函数用于判断给定的可迭代参数 iterable 中的所有元素是否都为 TRUE，如果是返回
                # True，否则返回 False。元素除了是 0、空、None、False 外都算 True。
                all(board[i][n - i - 1] == c for i in range(n))
            ))

        if check('X'):
            return 'X'
        if check('O'):
            return 'O'
        if ' ' in ''.join(board):
            return 'Pending'
        return 'Draw'


a = Solution()

nums = ["O"]
print(a.tictactoe(nums))
