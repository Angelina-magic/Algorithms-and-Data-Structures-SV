//1137. 第 N 个泰波那契数
//泰波那契序列 Tn 定义如下： 
//T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2
//给你整数 n，请返回第 n 个泰波那契数 Tn 的值。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/n-th-tribonacci-number
int tribonacci(int n){
    if (n < 3) {
        return n == 0 ? 0 : 1;
    }
    
    int a = 0, b = 1, c = 1;
    for (int i = 3; i <= n; ++i) {
        int temp = a + b + c;
        a = b;
        b = c;
        c = temp;
    }
    return c;
}
