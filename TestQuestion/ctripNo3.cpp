#include<iostream>
#include<sstream>
#include<string>
using namespace std;

void display(int **a,int n)
{
	for(int i = 0;i<n;i++)
	{
		
		for(int j = 0;j<n;j++)
			cout<< a[i][j] << " ";
		cout<<endl;
	}
}
 

int main()
{
	int n;
	cin>>n;
	int **a = new int*[n];
	for(int i = 0;i<n;i++)
	{
		int j = 0;
		a[i] = new int[n];
            for(int j = 0;j<n;j++)
            {
                  scanf("%d",&a[i][j]);
                  getchar();
            }
	}
	display(a,n);
}

