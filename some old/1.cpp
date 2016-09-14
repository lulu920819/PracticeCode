#include<iostream>
#include<math.h> 
using namespace std;

void countnum(int i)
{
	long long result=0;
   
    int num = floor(log2(i+1));
    cout<<"num"<<num<<endl;
    
    while(num>1)
    {
    	cout<<"i:"<<i<<endl;
    	 long half = (long)pow(2,num)-1+(long)pow(2,num-1);
    	 cout<<"half:"<<half<<endl;
    	 if(i< half)
    	 {
    	 	result=pow(10,num-1)*4+result;
    	 	cout<<"4--"<<num<<":"<<result<<endl;
    	 	i = half-i-1+(long)pow(2,num-1);
		 }
    	 	
    	 else
    	 {
    	 	result=pow(10,num-1)*7+result;
    	 	cout<<"7--"<<num<<":"<<result<<endl;
    	 	i = i-half-1+(long)pow(2,num-1);
		 }
    	 
    	 
    	 
    	 num--;
	}
   
    result+=((i==1)?4:7);
    cout<<std::fixed<<"result"<<result<<endl;
}


int main()
{
	countnum(10000);
	
    return 0;
}
