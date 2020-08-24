//面试题 16.11. 跳水板
//你正在使用一堆木板建造跳水板。有两种类型的木板，其中长度较短的木板长度为shorter，长度较长的木板长度为longer。你必须正好使用k块木板。编写一个方法，生成跳水板所有可能的长度。
//返回的长度需要从小到大排列。
//来源：力扣（LeetCode)链接：https://leetcode-cn.com/problems/diving-board-lcci
class Solution:
    def divingBoard(self, shorter: int, longer: int, k: int) -> List[int]:
        if k == 0:
            return []
        if longer == shorter:
            return [longer*k]
        return [i*longer+(k-i)*shorter for i in range(k+1)]
