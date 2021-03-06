/*
优雅的点：在圆上，x/y均为整数的点个数
input：半径的平方
*/
#include<iostream>
#include<math.h>
using namespace std;

// 在坐标轴的情况啊，就是已x轴为准，x从0开始，然后不需要等于sqrt(r2)就行了
int elegantPoint(int r2)
{
	int res = 0;
	for(int i =0;i<sqrt((double)r2);i++)
	{
		// 
		int rest = r2 - i*i;
		int j = (int)sqrt((double)rest);
		if((i*i+j*j)==r2)
			res++;
		// 不需要查找吧
		//int low = i;
		//int high  = (int)sqrt(r2);
		//while(low<=high)
		//{
		//	int mid = (high+low)/2;
		//	if(i*i + mid*mid ==r2){
		//		res++;
		//		break;
		//	}
		//	else if(i*i + j*j <r2)
		//		low = mid-1;
		//	else
		//		high = mid+1;
		//}
	}
	return res*4;
}

int main()
{
	int r2;
	cin>>r2;
	int res = elegantPoint(r2);
	cout<<res<<endl;
}