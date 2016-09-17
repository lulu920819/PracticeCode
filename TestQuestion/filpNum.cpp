/*
����n�������뽫���е�ż���Ķ����Ʒ�ת��
eg������1 6 5
����6��ż���������Ʊ�ʾΪ110����ת��Ϊ011������3�������������1 3 5.

��������:
�����������������ݡ�
����ÿ��������ݣ�
N --- ��������ָ���
N������a0,a1,...,an-1
��֤��
1<=N<=3000,0<=ai<=INT_MAX.

�������:
����ÿ�����ݣ����N��������
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
