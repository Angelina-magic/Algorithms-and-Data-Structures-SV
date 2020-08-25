# 判断点是否在线段上
"""
输入一条线段和一个点 -> 线段 有三种表示方式（点斜式，两点式，截距式） 最简单的输入方式应该是两点式
判断点是否在线段上 -> 通过向量共线来判断
返回结果 -> false/true
[[1, 2], [2, 3], [3, 4]]
"""
ans = []
for _ in range(3):
    ret = []

    ret.append(int(input("x = ")))
    ret.append(int(input("y = ")))
    ans.append(ret)

for i in range(2):
    ans[i][0] -= ans[2][0]
    ans[i][1] -= ans[2][1]

print(ans[0][0]*ans[1][1] == ans[0][1]*ans[1][0])
