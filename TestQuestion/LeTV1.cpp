#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		int count = 0;
		int low = ceil(a*0.05);
		int high = floor(a*0.1);
		int rest = b-a;
		while(low%5!=0&&low<=high)
			low++;
		for(int i =low;i<=high&&i<=b;i+=5)
			count++;
		cout<<count<<endl;
	}
}
 
 
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int A,B,R;
    while(cin>>A&&cin>>B){
        R=0;
        int a=ceil(A/0.95),b=floor(A/0.9);
        if(a<=B){
            if(b>B){
                R=B/5-a/5;
            }else{
                R=b/5-a/5;
            }
            if(a%5==0)
                R++;
    }
        cout<<R<<endl;
    }
    return 0;
}
