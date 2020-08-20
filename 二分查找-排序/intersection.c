349. 两个数组的交集
给定两个数组，编写一个函数来计算它们的交集。
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if (!nums1 || !nums2 || nums1Size<=0 || nums2Size<= 0) {
        *returnSize = 0;
        return NULL;
    }
    int hash[1024] = {0};
    for (int i =0; i < nums1Size; i++) {
        hash[nums1[i]] = 1; // 标记
    }
    int *temRes = (int *)calloc(sizeof(int),nums2Size) ;
    int k = 0; // 交集个数
    for (int j = 0; j < nums2Size; j++) {
        if (hash[nums2[j]]) { // 被标记说明是交集
            temRes[k++] =  nums2[j];
            hash[nums2[j]] = 0; // 后面再用重复元素不处理
        }
    }
    *returnSize = k;
    int *res = (int *)calloc(sizeof(int),k) ;
    for (int i = 0; i < k; i++) { // temRes前k个交集元素
        res[i] = temRes[i];  
    }
    free(temRes);
    return res; 
}
