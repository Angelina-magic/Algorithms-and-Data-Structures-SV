# 1414. 和为 K 的最少斐波那契数字数目
# 给你数字 k ，请你返回和为 k 的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。
# 斐波那契数字定义为：
# F1 = 1
# F2 = 1
# Fn = Fn-1 + Fn-2 ， 其中 n > 2 。
# 数据保证对于给定的 k ，一定能找到可行解。
class Solution:
    # def findMinFibonacciNumbers(self, k: int) -> int:
    def findMinFibonacciNumbers(self, k):
        res = [1, 1]
        a, b, fib = 1, 1, 2

        while fib < k:
            fib = a + b
            a = b
            b = fib
            res.append(fib)

        i = 0
        for j in res[::-1]:
            if j <= k:
                i += 1
                k -= j      
            if k == 0:
                break

        return i


m = 7
a = Solution()
print(a.findMinFibonacciNumbers(m))
