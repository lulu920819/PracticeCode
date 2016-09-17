/*
若宝石系列为：dcba
其中有两道彩虹，分别是(0,1),(1,2),
代表第一个位置上的宝石可以和第二个位置上的宝石互换，
第二个位置上的宝石可以和第三个位置上的宝石互换，
最终可以得到字典序最小的宝石系列：bcda。

输入描述:

输入包含多组测试数据。
对于每组测试数据：
字符串s --- 代表宝石序列
n --- 代表有n条彩虹
接下来n行，每行两个数ai,bi --- 表示ai和bi由一条彩虹相连。

保证：

1<=s的长度<=10000

1<=n<=10000

且输入数据均合法。

输出描述:

对于每组数据，输出一个字符串

输入例子:

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

输出例子:

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
