# 面试题 16.20. T9键盘
# 在老式手机上，用户通过数字键盘输入，手机将提供与这些数字相匹配的单词列表。每个数字映射到0至4个字母。给定一个数字序列，实现一个算法来返回匹配单词的列表。你会得到一张含有有效单词的列表。
# 来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/t9-lcci
class Solution:
    # def getValidT9Words(self, num: str, words: List[str]) -> List[str]:
    def getValidT9Words_HM(self, num, words):
        hashmap = {'2': ['a', 'b', 'c'], '3': ['d', 'e', 'f'], '4': ['g', 'h', 'i'], '5': ['j', 'k', 'l'],
                   '6': ['m', 'n', 'o'], '7': ['p', 'q', 'r', 's'], '8': ['t', 'u', 'v'],
                   '9': ['w', 'x', 'y', 'z']}
        ruc = []
        for arr in words:
            ret = arr
            arr = ",".join(arr)
            arr = arr.split(",")
            j = 0
            for n, res in enumerate(num):
                if arr[n] in hashmap[res]:
                    j += 1
            if j == len(num):
                ruc.append(ret)
        return ruc


    def getValidT9Words(self, num, words):
        intab = "abcdefghijklmnopqrstuvwxyz"
        outtab = "22233344455566677778889999"
        trans = str.maketrans(intab, outtab)
        return [word for word in words if word.maketrans(trans)==num]


num = "2"
words = ["a", "b", "c", "d"]
a = Solution()
print(a.getValidT9Words(num, words))
