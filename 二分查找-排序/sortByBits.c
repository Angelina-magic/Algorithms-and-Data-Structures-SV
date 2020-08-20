//1356. 根据数字二进制下 1 的数目排序
//给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。
//如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。
//请你返回排序后的数组。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/sort-integers-by-the-number-of-1-bits
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //计算1的个数
int getNum1(int n) {
    int cnt = 0;
    while (n > 0) {
        n &= (n - 1);
        cnt++;
    }

    return cnt;
}

//比较函数
int cmp(const void *a, const void *b) {
    int numa1 = *(int *)a, numb1 = *(int *)b;
    int c = getNum1(numa1), d = getNum1(numb1);

    return c == d ? numa1 - numb1 : c - d;
}

int* sortByBits(int* arr, int arrSize, int* returnSize){
    *returnSize = arrSize;
    qsort(arr, arrSize, sizeof(int), cmp); //使用qsort()函数来进行排序

    return arr;
}
