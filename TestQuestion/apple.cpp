/*
С��ȥ�������̵���ƻ������թ���̷�ʹ���������ף�
ֻ�ṩ6��ÿ����8��ÿ���İ�װ(��װ���ɲ��)��
����С������ֻ�빺��ǡ��n��ƻ����С���빺�����ٵĴ�������Я����
������ܹ���ǡ��n��ƻ����С�׽����Ṻ��

����һ������n����ʾС���빺��n(1 �� n �� 100)��ƻ��
���һ��������ʾ������Ҫ����Ĵ��������������ǡ��n��ƻ�������-1
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
