//1351. 统计有序矩阵中的负数
//给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。 
//请你统计并返回 grid 中 负数 的数目。
int countNegatives(int** grid, int gridSize, int* gridColSize){
    int m=gridSize,n=*gridColSize;
    int ans=0;
    for(int i=0;i<m;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(grid[i][j]<0)
                ans++;
            else
                break;
        }
    }
    return ans;
}
