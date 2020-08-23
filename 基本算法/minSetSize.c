//1338. 数组大小减半
//给你一个整数数组 arr。你可以从中选出一个整数集合，并删除这些整数在数组中的每次出现。
//返回 至少 能删除数组中的一半整数的整数集合的最小大小。
#define MAX_NUMBER 100001

int cmp(const void *a , const void *b) {
    return *(int *)b - *(int *)a;
}
int minSetSize(int* arr, int arrSize){
    int res_num = 0, step = 0, sum = 0, count[MAX_NUMBER] = { 0 };
    int i;
    
    for (i = 0; i < arrSize; i++) {
        count[arr[i]]++;
    }
    
    qsort(count, MAX_NUMBER, sizeof(int), cmp);
    
    for (i = 0; i < MAX_NUMBER; i++) {
        sum += count[i];
        res_num = arrSize - sum;
        step++;
        if (2 * res_num <= arrSize) {
            return step;
        }
    }
    
    return 0;
}
