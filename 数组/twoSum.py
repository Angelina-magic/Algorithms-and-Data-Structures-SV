    class Solution:
    #    def twoSumBF(self, nums: List[int], target: int) -> List[int]:
        def twoSum(self, nums, target):
            hashmap = {}  # 通过python3的字典的key-value的特点（无序性，key的唯一性）来实现散列
            for i, num in enumerate(nums):  # enumerate() 函数用于将一个可遍历的数据对象(如列表、元组或字符串)组合为一个索引序列，同时列出数据下标和数据，一般用在 for 循环当中
                if hashmap.get(target - num) is not None:  # Python3 字典(Dictionary) get() 方法返回指定键的值，如果值不在字典中返回默认值(None)
                    return [i, hashmap.get(target - num)]  # 返回结果
                hashmap[num] = i  # 这句不能放在if语句之前，解决list中有重复值或target-num=num的情况
