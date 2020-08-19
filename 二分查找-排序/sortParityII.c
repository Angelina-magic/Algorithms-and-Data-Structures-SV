//922. 按奇偶排序数组 II
//给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
//对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。
//你可以返回任何满足上述条件的数组作为答案。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/sort-array-by-parity-ii
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
  *returnSize=0;
  int* res=(int*)malloc(sizeof(int)*ASize);
  int t=0;
  int s=1;
  for(int i=0;i<ASize;i++) {
      if(A[i]%2==0) {
          res[t]=A[i];
          t=t+2;
      } else {
          res[s]=A[i];
          s=s+2;
      }
  }
  *returnSize=ASize;
  return res;
}
