//441. 排列硬币
//你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。
//给定一个数字 n，找出可形成完整阶梯行的总行数。
//n 是一个非负整数，并且在32位有符号整型的范围内。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/arranging-coins
int arrangeCoins(int n)
{
	long left = 0;
	long right = n;
	while (left <= right) {
	    long mid = left + (right - left) / 2;
		long sum = (1 + mid) * mid / 2;
		if (sum == n) {
		    return mid;
		} else if (sum > n) {
		    right = mid - 1;
		} else {
		    left = mid + 1;
		}
	}
	return right;
}
