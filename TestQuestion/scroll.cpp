/*
�������ǿ��֮�󣬺հش���ľ��Ų���û�ܻ���³��˹��������³��˹���������䣬�հ�������ᵽ�˸߽���֮�����ߵ�ǿ��ʵ����
�������հ����ջ����ҵ���³��˹���������㣬������³��˹ϲ���ռ��Ϲž��ᣬ��Ϊ�Ϲž����ܹ���³��˹�������֮����
¬��˹����ʹ���Ϲž��Ὣ¬��˹���յ�����֮�ţ����þ���֮�ŵ���������¬��˹��
�հ�ע�⵽¬��˹ϲ���ռ���ͬ�ľ��ᣬ������Ǽ���ͬ���Ϲž��ᣬ������Ȥ�ͻ��𽥽��͡�
�հ�����ӵ��N�ֲ�ͬ�ľ��ᣬÿ�־�����Ai����������Ҫ����N�������ɢ��³��˹��ص�����֮�ŵ�·�ϣ�ÿһ�����з�ʽ����һ������ֵCharm������ֵԽ�ߣ�³��˹�����յ�����֮�ŵĸ���Խ�ߡ�
Charm = Sum of all D(i)������D(i) = k - i��iΪ�������о���i���±꣬kΪλ��i�����Һ�i��ͬһ�־���ľ����±ꡣ
�������еľ�����<�������� ����>�ĸ�ʽ����������Ҫ������о��������˳��ʹ������ֵ�������ж������з�ʽ��������������������������ֵ�����С��һ����

�������� :

����������ݣ��봦���ļ�������

����ÿ��������ݣ�

��һ�У�һ������N��������N�־��ᡣ

�ڶ��У�N�־����������

��֤��

0 <= N <= 50;

��������Ϊ����1~10����ĸ��ÿ�־��������Ϊ1~800֮���һ��������


������� :

������о����һ�����С�

�������� :

3
Thunder 1 Wind 3 Soil 2

������� :

	 Soil Wind Thunder Wind Soil Wind
*/
#include<iostream>
#include <sstream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

void minScroll(int n)
{
    vector<pair<string,int> > v(n);

    string l = "",r="",mid = "";
    for(int i = 0;i<n;i++)
        cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());

    for(int i =0;i<n;i++)
    {
        if(v[i].second>=2){
            l += (v[i].first+" ");
            r +=(v[i].first + " ");
            v[i].second -=2;
        }

    }

    for(int i = 0;i<n;i++)
    {
        while(v[i].second!=0)
        {
            mid+= (v[i].first+" ");
            v[i].second--;
        }
    }
    string s = l+mid+r;
    if(s.size())
        s.substr(0,s.size()-1);
    cout<<s<<endl;
}

int main()
{
    int n;
    while(cin>>n)
    {
        minScroll(n);
    }
}

int main1(){
	int n;
	while (cin >> n){
		string l = "", mid = "", r = "";
		vector<pair<string, int> >v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i].first >> v[i].second;
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < n; i++){
			if (v[i].second>1)
				l += v[i].first + ' ', r += v[i].first + ' ', v[i].second -= 2;
		}
		for (int i = 0; i < n; i++){
			while (v[i].second>0)
				mid += v[i].first + ' ', v[i].second--;
		}
		string s = l + mid + r;
		if (s.size())
			//s.pop_back();
		cout << s << endl;
	}
}
