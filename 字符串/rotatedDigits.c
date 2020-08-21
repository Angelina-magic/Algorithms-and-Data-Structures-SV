//788. 旋转数字
//我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。
//如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；
//2 和 5 可以互相旋转成对方（在这种情况下，它们以不同的方向旋转，换句话说，2 和 5 互为镜像）；6 和 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。
//现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/rotated-digits
int valid_unequal_digits(int n)//判断一个数是否是好数
{
    int re=0,tmp=0;
    while(n!=0) {

        tmp=n%10;//取这一位
        
        if(tmp==3||tmp==4||tmp==7) {
            return 0;//如果数字中某一位是3或4或7，这个数不是好数
        }
        if(tmp==2||tmp==5||tmp==6||tmp==9) {
            re=1;//如果数字中某一位是2或5或6或9，就有可能是好数（前提是数字中任何一位不能是3或4或7）
        }
        n=n/10;//取下一位来判断
    }
    return re;
}
int rotatedDigits(int N) {
    int i=0,sum=0;
    for(i=1;i<=N;i++) {
        sum=sum+valid_unequal_digits(i);
    }
    return sum;
}
