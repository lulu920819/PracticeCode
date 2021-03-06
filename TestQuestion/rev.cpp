/*
对于一个整数X，定义操作rev(X)为将X按数位翻转过来，并且去除掉前导0。
如果 X = 123，则rev(X) = 321;
如果 X = 100，则rev(X) = 1.
现在给出整数x和y,要求rev(rev(x) + rev(y))为多少？ 
input：输入为一行，x、y(1 ≤ x、y ≤ 1000)，以空格隔开
output:  rev(rev(x) + rev(y))
*/
#include<iostream>
#include<math.h>
using namespace std;

// 在坐标轴的情况啊，就是已x轴为准，x从0开始，然后不需要等于sqrt(r2)就行了
int rev(int n)
{
	int res = 0;

	if(n==0)
		return  0;
	bool firstnum = false;
	while(n!=0)
	{
		int m = n%10;
		if(m!=0)
		{
			firstnum = true;
			res = res*10+m;
		}
		else
		{
			if(firstnum)
				res = res*10+m;
		}
		n = n/10;
	}
	return res;
}

int main()
{
	int x,y;
	cin>>x>>y;
	int res =rev(rev(x)+rev(y));
	cout<<res<<endl;
}