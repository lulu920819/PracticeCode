/*
小易去附近的商店买苹果，奸诈的商贩使用了捆绑交易，
只提供6个每袋和8个每袋的包装(包装不可拆分)。
可是小易现在只想购买恰好n个苹果，小易想购买尽量少的袋数方便携带。
如果不能购买恰好n个苹果，小易将不会购买。

输入一个整数n，表示小易想购买n(1 ≤ n ≤ 100)个苹果
输出一个整数表示最少需要购买的袋数，如果不能买恰好n个苹果则输出-1
*/

#include<iostream>
#include<math.h>

using namespace std;


int dsp(int n,bool &hasresult){
    if(n==0){
        hasresult = true;
        return 0;
    }

    else if(n<0){

        return 0;
    }
    return min(dsp(n-6,hasresult),dsp(n-8,hasresult))+1;

}


int main(){
    int n;
    cin>>n;
    bool hasresult = false;
    int cnt = dsp(n,hasresult);
   	if(hasresult)
        cout<<cnt<<endl;
    else
        cout<<-1<<endl;
}
