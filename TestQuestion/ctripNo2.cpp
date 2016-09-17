#include<iostream>
using namespace std;

int binary(int p[],int n,int x)
{
	int low = 0,high = n-1;
	while(low<=high)
	{
		int mid = (low+high)/2;
		if(x<p[mid])
			high = mid-1;
		else
			low = mid+1;
	}
	if(low>high)
    	return (-1-low);
}

int main()
{
	int x,n;
	cin>>x>>n;
	if(n==0)
    {
       cout<<-1<<endl;
       return 0;
    }
	int * a = new int [n];
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==x)
		{
			cout<<i<<endl;
			return 0;	
		}	
	}
	
	cout<<binary(a,n,x)<<endl;
	delete a;
	return 0;
}
