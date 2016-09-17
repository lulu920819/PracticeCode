#include<vector>
#include<iostream>
#include<sstream>
using namespace std;
int maxProfit1(int* prices, int pricesSize) {
    if(pricesSize<=1) return 0;
    int i;
    int profit = 0;
    int diff = 0;
    for(i=1;i<pricesSize;i++)
    {
        diff += prices[i]-prices[i-1];
        if(diff<0)
           diff = 0;
        if(diff>profit)
            profit = diff;
    }
    return profit;
}

int maxProfit(vector<int> prices) {
	int pricesSize = prices.size();
    if(pricesSize<=1) return 0;
    int i;
    int profit = 0;
    int diff = 0;
    for(i=1;i<pricesSize;i++)
    {
        diff += prices[i]-prices[i-1];
        if(diff<0)
           diff = 0;
        if(diff>profit)
            profit = diff;
    }
    return profit;
}

int main()
{
    string strTemp;  
    //int array[4];  
    //int i = 0;  
      vector<int> array;
    stringstream sStream;  
  
    cin >> strTemp;  
    int pos = strTemp.find(',');  
    while (pos != string::npos)  
    {  
        strTemp = strTemp.replace(pos, 1, 1, ' ');  //将字符串中的','用空格代替  
        pos = strTemp.find(',');  
    }  
  
    sStream << strTemp;  //将字符串导入的流中  
    while (sStream)  
    {  
        int i_tmp ;
        sStream >> i_tmp;
        array.push_back(i_tmp);  
    }
    cout<< maxProfit(array)<<endl; 
     
}
