/*
小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，
小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。
小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板

输入描述:

输入为一行，有两个整数N，M，以空格隔开。
(4 ≤ N ≤ 100000)
(N ≤ M ≤ 100000)


输出描述:

输出小易最少需要跳跃的步数,如果不能到达输出-1
*/

#include<iostream>
#include<vector>
#include<set>
#include<math.h>
using namespace std;

// 得到n的约数，除了1和它本身
void get_yue_shu(int n, vector<int>&a){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            a.push_back(i);
            if(n/i != i)
                a.push_back(n/i);
        }
    }
}


void minJump(int n, int m)
{
    vector<int> res(m+1,0); //m+1 vector 0
    res[n]=1;  //第一个设置为1，为了 if(res[i] == 0)这句话，启动，所以后面结果是res[m]-1
    for(int i = n;i<=m;i++)
    {
        vector<int> a; //约数的集合
        get_yue_shu(i,a);
        if(res[i] == 0)
            continue;
        // iterator迭代器要用vector<int>::
        for(vector<int>::iterator it = a.begin();it!=a.end();it++)
        {
            if((i+*it)<=m&&res[i+*it]!=0)
                res[i+*it] = min(res[i+*it],res[i]+1);
            else if((i+*it)<=m)
                res[i+*it] = res[i]+1;
        }
    }
    if(res[m]==0)
        cout<<-1<<endl;
    else
        cout<<res[m]-1<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    minJump(n,m);
}

int main2(){
    int n,m;
    while(cin>>n>>m){
        vector<int> res(m+1, 0);
        res[n] = 1;
        for(int i=n;i<=m;i++){
            vector<int>a;
            //位置i无法到达，跳过
            if(res[i]==0)
                continue;
            get_yue_shu(i, a);
            //记录从起点到i的最小步数
            for(int j=0;j<a.size();j++){
                //由点i出发能到达的点
                if((a[j]+i)<=m&&res[a[j]+i]!=0)
                    //其它点也能到达，比较大小，记录最小步数
                    res[a[j]+i] = min(res[a[j]+i], res[i] + 1);
                else if((a[j]+i)<=m)
                    //到达点i的最小步数加1
                    res[a[j]+i] = res[i] + 1;
            }
        }
        if(res[m]==0)
            cout<<-1<<endl;
        else
            cout<<res[m]-1<<endl;
    }
    return 0;
}
