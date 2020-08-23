//1029. 两地调度
//公司计划面试 2N 人。第 i 人飞往 A 市的费用为 costs[i][0]，飞往 B 市的费用为 costs[i][1]。
//返回将每个人都飞到某座城市的最低费用，要求每个城市都有 N 人抵达。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/two-city-scheduling
int cmp(const void *a, const void *b) {
    return ((*(int **)a)[0] - (*(int **)a)[1]) - ((*(int **)b)[0] - (*(int **)b)[1]);
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize) {
    int ans = 0;
    qsort(costs, costsSize, sizeof(int *), cmp);

    for (int i = 0; i < costsSize; ++i) {
        if (i < costsSize / 2) {
            ans += costs[i][0];
        } else {
            ans += costs[i][1];
        }
    }

    return ans;
}
