/*
blog :  http://blog.csdn.net/github_30830155/article/details/52549844
*/

#include<stdio.h>

void IslandsCore(int (&grid)[5][5], int i, int j,int m,int n)
{
	grid[i][j]=0;
	if(i>1&&grid[i-1][j]==1)
		IslandsCore(grid,i-1,j,m,n);
	if(j>1&&grid[i][j-1]==1)
		IslandsCore(grid,i,j-1,m,n);
	if((i<m-1)&&grid[i+1][j]==1)
		IslandsCore(grid,i+1,j,m,n);
	if((j<n-1)&&grid[i][j+1]==1)
		IslandsCore(grid,i,j+ 1,m,n);
}




int numsofIslands(int (&grid)[5][5], int m, int n)
{
	int cnt=0;
	for	(int i = 0;i<m;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(grid[i][j]==1)
			{
				grid[i][j]=0;
				printf("i:%d,j:%d, --- %d\n",i,j,grid[i][j]);
				cnt++;
				if(i>1&&grid[i-1][j]==1)
					IslandsCore(grid,i-1,j,m,n);
				if(j>1&&grid[1][j-1]==1)
					IslandsCore(grid,i,j-1,m,n);
				if((i<m-1)&&grid[i+1][j]==1)
					IslandsCore(grid,i+1,j,m,n);
				if((j<n-1)&&grid[i][j+1]==1)
					IslandsCore(grid,i,j+1,m,n);
			}
		}
	}
	return cnt;
} 


int main()
{
	// 1, 1, 0, 0, 0],  [0, 1, 0, 0, 1],  [0, 0, 0, 1, 1],  [0, 0, 0, 0, 0],  [0, 0, 0, 0, 1
	int grid[5][5]={{1, 1, 0, 0, 0},{0, 1, 0, 0, 1},
	{0, 0, 0, 1, 1},{0, 0, 0, 0, 0},{0, 0, 0, 0, 1}};
	int cnt = numsofIslands(grid,5,5);
	printf("%d\n",cnt);
	
}
