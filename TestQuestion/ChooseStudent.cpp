/*
有 n 个学生站成一排，每个学生有一个能力值，
牛牛想从这 n 个学生中按照顺序选取 k 名学生，
要求相邻两个学生的位置编号的差不超过 d，
使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗
输入描述:
每个输入包含 1 个测试用例。
每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，
表示学生的个数，
接下来的一行，包含 n 个整数，
按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。
接下来的一行包含两个整数，
k 和 d (1 <= k <= 10, 1 <= d <= 50)。


输出描述:
输出一行表示最大的乘积。
*/
#include<iostream>

using namespace std;

void display(long long ** a, int x, int y)
{
	for(int i = 0;i<x;i++)
	{
		for(int j = 0;j<y;j++)
			cout<<a[i][j]<< " ";
		cout<<endl;
	}

}
// n 个学生中按照顺序选取 k 名学生，
// 要求相邻两个学生的位置编号的差不超过 d
long long getMaxAI(int *ai, int K, int D,int N)
{
	long long  maxAI = 0;
	long long **Fmax = new long long *[K];
	long long **Fmin = new long long *[K];
	for (int x =0;x<K;x++)
	{
		Fmax[x] = new long long [N]();  //初始化为0；加上()
		Fmin[x] = new long long [N]();
		if(x==0)
		{
			for (int y = 0;y<N;y++)
			{
				Fmax[x][y]=ai[y];
				Fmin[x][y]=ai[y];
			}
		}
	}
	//display(Fmax,K,N);

	for(int k = 1;k<K;k++)
	{
		for(int i = 0;i<N;i++ )
		{
			for (int m =1;m<=D  ;  m++ )
			{
				if(i-m>=0)
				{
					Fmax[k][i] = max(Fmax[k][i], max(Fmax[k-1][i-m]*ai[i],Fmin[k-1][i-m]*ai[i]));
					Fmin[k][i] = min(Fmin[k][i], min(Fmax[k-1][i-m]*ai[i],Fmin[k-1][i-m]*ai[i]));
				}
			}
		}
		//cout<<maxAI<<endl;
	}	

	for (int n = 0;n<N;n++)
	{
		maxAI = max(maxAI,Fmax[K-1][n]);
	}

	for (int x =0;x<K;x++)
	{
		delete []Fmax[x] ;
		delete []Fmin[x] ;
	}
	delete []Fmax;
	delete []Fmin;

	return maxAI;
}

int main()
{
	int n;
	while(cin>>n)
	{
		int * ai = new int[n];

		for(int i = 0;i<n;i++)
		{
			cin>>ai[i];
		}
		int k,d;
		cin>>k>>d;
		cout<<getMaxAI(ai,k,d,n)<<endl;

		delete []ai;
	}


	//int ai2[3] = {7,4,7};
	//int k2 =2 ,d2 =50, n2=3;
	//getMaxAI(ai2,k2,d2,n2);

	return 0;
}