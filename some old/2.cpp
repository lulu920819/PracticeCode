#include<iostream>

using namespace std;

int sum_x(int x,int g)
{
      int sum = 0;
      while(x!=0&&sum<=g)
      {
            sum+=x%10;
            x=x/10;
      }
      //cout<<"x"<<x<<"sum"<<sum<<endl;
      return sum;
}


int sum_1(int n)
{
    int count=0; 
    while(n != 0){ 
        n &= (n-1); 
        count ++; 
    } 
    return count; 
         
}

int main()
{
      int t;
      cin>>t;
      while(t--)
      {
            int n;
            cin>>n;
            int all = 0;
            for(int i = 1;i<=n;i++)
            {
            int g = sum_1(i);
            int f = sum_x(i,g);
            
            if(f==g)
                  all++;
            }
            cout<<all;
      }
       
}
      
