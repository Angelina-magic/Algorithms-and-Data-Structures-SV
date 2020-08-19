//852. 山脉数组的峰顶索引
//我们把符合下列属性的数组 A 称作山脉：
//A.length >= 3
//存在 0 < i < A.length - 1 使得A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
//给定一个确定为山脉的数组，返回任何满足 A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1] 的 i 的值。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/peak-index-in-a-mountain-array
int peakIndexInMountainArray_1(int* A, int ASize){
// 线性扫描
    int i=0;
    while(A[i]<A[i+1]) i++;
    return i;
}

int peakIndexInMountainArray_2(int* A, int ASize){
// 二分查找
    int left = 0;
    int right = ASize - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (A[mid] > A[mid - 1]  && A[mid] > A[mid + 1]) {
            return mid;
        } else if (A[mid] < A[mid - 1]) {
            right = mid - 1;
        } else if (A[mid] < A[mid + 1]) {
            left = mid + 1;
        }
    }
    return left;
}
