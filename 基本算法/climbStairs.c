//70. 爬楼梯
//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//注意：给定 n 是一个正整数。
int climbStairs(int n){
    // f(n) = f(n-1) + f(n-2)
    if ( n < 0 ) return 0;
    if (n <=2) return n;

    int fn1 = 1, fn2 = 2;
    int fn3;
    for (int i = 2 ;i < n; i++){
        fn3 = fn2 + fn1;
        fn1 = fn2;
        fn2 = fn3;
    }
    return fn3;

}
