//1387. 将整数按权重排序
//我们将整数 x 的 权重 定义为按照下述规则将 x 变成 1 所需要的步数：
//如果 x 是偶数，那么 x = x / 2
//如果 x 是奇数，那么 x = 3 * x + 1
//比方说，x=3 的权重为 7 。因为 3 需要 7 步变成 1 （3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1）。
//给你三个整数 lo， hi 和 k 。你的任务是将区间 [lo, hi] 之间的整数按照它们的权重 升序排序 ，如果大于等于 2 个整数有 相同 的权重，那么按照数字自身的数值 升序排序 。
//请你返回区间 [lo, hi] 之间的整数按权重排序后的第 k 个数。
//注意，题目保证对于任意整数 x （lo <= x <= hi） ，它变成 1 所需要的步数是一个 32 位有符号整数。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/sort-integers-by-the-power-value
typedef struct {
	unsigned short head;
	unsigned short pos;
	unsigned short size;
} LIST;
unsigned int get_step_num(unsigned int num)
{
	unsigned int step = 0;
	while (num != 1) {
		if (num & 0x01) {
			num = num * 3 + 1;
		}
		else {
			num = num >> 1;
		}
		step++;
	}
	return step;
}
int getKth(int lo, int hi, int k) {
	int i = 0, tail = 0, num;
	unsigned int step = 0;
	int src_num[1001];
	int list_point[179];//最大权重为178
	LIST list[179];//最大权重为178
	memset(list_point, 0xFF, sizeof(list_point));

	for (i = lo; i <= hi; i++) {
		step = get_step_num(i);
    
		if (list_point[step] == 0xFFFFFFFF) {
			list_point[step] = tail;
			list[tail].head = i;
			list[tail].pos = i;
			list[tail].size = 1;
			tail++;
		} else {
			list[list_point[step]].size++;
			src_num[list[list_point[step]].pos] = i;
			list[list_point[step]].pos = i;
		}
	}
	i = 0;
	step = 0;
	while (1) {
		if (list_point[step] == 0xFFFFFFFF) {
			step++;
			continue;
		}
		if (i + list[list_point[step]].size >= k)
        break;
		i += list[list_point[step]].size;
		step++;
	}
	i = k - i - 1;
	num = list[list_point[step]].head;
	while (i > 0) {
		num = src_num[num];
		i--;
	}
	return num;
}
