/*
1267. 统计参与通信的服务器
这里有一幅服务器分布图，服务器的位置标识在 m * n 的整数矩阵网格 grid 中，1 表示单元格上有服务器，0 表示没有。
如果两台服务器位于同一行或者同一列，我们就认为它们之间可以进行通信。
请你统计并返回能够与至少一台其他服务器进行通信的服务器的数量。

来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/count-servers-that-communicate
*/
void dfs(int** grid, int gridSize, int* gridColSize,int row, int col,int *num)
{
    if (grid[row][col] == 0) {
        return;
    }
    grid[row][col] = 0;//将1连接颜色去掉，防止重复访问
    *num = *num + 1;

    //遍历行
    for (int i = 0; i < gridSize; i++) {
        if (grid[i][col] == 1) {
            dfs(grid, gridSize,gridColSize,i,col,num);
        }
    }
    //遍历列
    for (int j = 0; j < gridColSize[row]; j++) {
        if (grid[row][j] == 1) {
            dfs(grid, gridSize,gridColSize,row,j,num);
        }
    }

    return;
}


int countServers(int** grid, int gridSize, int* gridColSize) {
    int max = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if(grid[i][j] == 1) {
                int num = 0;
                dfs(grid, gridSize,gridColSize,i,j,&num);
                //如果等于1 说明是孤立节点1，不需要统计
                if (num > 1) {
                    max += num;
                }
            }
        }
    }

    return max;
}
