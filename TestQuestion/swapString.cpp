/*
����ʯϵ��Ϊ��dcba
�����������ʺ磬�ֱ���(0,1),(1,2),
�����һ��λ���ϵı�ʯ���Ժ͵ڶ���λ���ϵı�ʯ������
�ڶ���λ���ϵı�ʯ���Ժ͵�����λ���ϵı�ʯ������
���տ��Եõ��ֵ�����С�ı�ʯϵ�У�bcda��

��������:

�����������������ݡ�
����ÿ��������ݣ�
�ַ���s --- ����ʯ����
n --- ������n���ʺ�
������n�У�ÿ��������ai,bi --- ��ʾai��bi��һ���ʺ�������

��֤��

1<=s�ĳ���<=10000

1<=n<=10000

���������ݾ��Ϸ���

�������:

����ÿ�����ݣ����һ���ַ���

��������:

dcba
2
0 1
1 2
hellonowcoder
4
0 1
1 4
2 5
2 3

�������:

bcda
ehllonowcoder
*/

#include<string>
#include<iostream>
using namespace std;
void swapString(string &s,int n)
{
    for(int i = 0;i<n;i++)
    {
        int m,n;
        cin>>m>>n;
        char c;
        c = s.at(m+1);
        s.at(m+1) = s.at(n+1) ;
        s.at(n+1) = c;
    }
}

int main()
{
    string s;
    while(cin>>s)
    {
        int n;
        cin>>n;
        swapString(s,n);
        cout<<s<<endl;
    }
    return 0;
}
