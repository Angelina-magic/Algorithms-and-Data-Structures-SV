//1491. 去掉最低工资和最高工资后的工资平均值
//给你一个整数数组 salary ，数组里每个数都是 唯一 的，其中 salary[i] 是第 i 个员工的工资。
//请你返回去掉最低工资和最高工资以后，剩下员工工资的平均值。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/average-salary-excluding-the-minimum-and-maximum-salary
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

double average(int* salary, int salarySize){
    double sum = 0;
    qsort(salary, salarySize, sizeof(int), cmp);
    if (salarySize == 3) {
        return salary[1];
    }

    for (int i = 1; i < salarySize - 1; ++i) {
        sum += salary[i];
    }

    return sum / (salarySize - 2);
}
