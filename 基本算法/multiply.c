//面试题 08.05. 递归乘法
//递归乘法。 写一个递归函数，不使用 * 运算符， 实现两个正整数的相乘。可以使用加号、减号、位移，但要吝啬一些。
int multiply(int A, int B){
    int tmp = 0;

    if (A >> 1) {
        tmp = multiply(A >> 1, B << 1);
    }

    return (((unsigned int)A << 31) >> 31) ? (tmp + B) : tmp;
}
