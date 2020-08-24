//1042. 不邻接植花
//有 N 个花园，按从 1 到 N 标记。在每个花园中，你打算种下四种花之一。
//paths[i] = [x, y] 描述了花园 x 到花园 y 的双向路径。
//另外，没有花园有 3 条以上的路径可以进入或者离开。
//你需要为每个花园选择一种花，使得通过路径相连的任何两个花园中的花的种类互不相同。
//以数组形式返回选择的方案作为答案 answer，其中 answer[i] 为在第 (i+1) 个花园中种植的花的种类。花的种类用  1, 2, 3, 4 表示。保证存在答案。
//来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/flower-planting-with-no-adjacent
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct node {
    int paths[4];
    int path_num;
    int color;
};


int* gardenNoAdj(int N, int** paths, int pathsSize, int* pathsColSize, int* returnSize){

    if (N == 0) {
        *returnSize = 0;
        return NULL;
    }
    int *res = (int *)malloc(sizeof(int) * N);
    memset(res, 0, sizeof(int) * N);

    struct node *Nodes = (struct node *)malloc(sizeof(struct node) * N);
    memset(Nodes, 0, sizeof(struct node) * N);

    /* 构造邻接矩阵 */
    for(int i = 0; i < pathsSize; i++) {
        int start = paths[i][0] - 1;
        int end = paths[i][1] - 1;
        Nodes[start].paths[Nodes[start].path_num] = end;
        Nodes[start].path_num++;
        Nodes[end].paths[Nodes[end].path_num] = start;
        Nodes[end].path_num++;
    }

    /* 填充颜色 */
    for(int i = 0; i < N; i++) {
        int set[4] = {-1, -1, -1, -1};
        for(int path_i = 0; path_i < Nodes[i].path_num; path_i++) {
            int n_path = Nodes[i].paths[path_i];
            if (res[n_path] != 0) {         //这个颜色不能有
                set[res[n_path] - 1] = 0;
            }
        }
        for(int j = 0; j < 4; j++) {
            if (set[j] == -1) {
                res[i] = j + 1;
                break;
            }
        }
    }
    *returnSize = N;
    return res;
}
