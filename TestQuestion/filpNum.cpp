/*
输入n个数，请将其中的偶数的二进制反转。
eg：输入1 6 5
其中6是偶数，二进制表示为110，反转后为011，代表3，所以最终输出1 3 5.

输入描述:
输入包含多组测试数据。
对于每组测试数据：
N --- 输入的数字个数
N个数：a0,a1,...,an-1
保证：
1<=N<=3000,0<=ai<=INT_MAX.

输出描述:
对于每组数据，输出N个整数。
*/

#include<iostream>
#include<vector>
using namespace std;

int flipNum(int x)
{
    int res = 0;
    while(x!=0)
    {
        res = res*2 + x%2;
        x = x/2;
    }


    return res;
}

void getNum(vector<int> &a,int n)
{
    for(int i = 0;i <n;i++)
    {
        int tmp;
        cin>>tmp;
        if(tmp%2!=0)
            a[i] = tmp;
        else
            a[i] = flipNum(tmp);
    }
}

void displayNum(vector<int> a,int n)
{
     cout << a[0];
     for(int i = 1;i <n;i++)
     {
         cout<<" "<<a[i];
     }
     cout<<endl;
}

int main()
{
    int N;
    while(cin>>N)
    {
        vector<int> a(N,0);
        getNum(a,N);
        displayNum(a,N);
    }
}
