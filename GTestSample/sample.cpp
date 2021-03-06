#include"sample.h"
using namespace std;

#define  DELIME " "

int fun(int a, int b)  
{  
	return (a-b);  
}  

bool isIDLegal(string IDLine)
{
	// 是否存在空格
	if (IDLine.empty()||IDLine.size()==0)
		return 0;
	size_t index=IDLine.find_first_of(DELIME,0);  
	if (index == string::npos)
	{
		return true;
	}
	return false;
}


bool isXYLegal(string XYLine)
{
	// cat1 10 9 2 -1 or cat1 10 9
	regex reg("[+-]*\d+");
	vector<string> res;
	vector<int> xy_cor;
	split(res,XYLine,is_any_of(" "));
	if (res.size()!=3||res.size()!=5)
		return false;
	setAnimalName(res[0]);
	for(size_t i = 1;i<res.size();i++)
	{
		bool result = regex_match(res[i],reg);
		if (result)
		{
			int num = lexical_cast<int>(res[i]);  
			xy_cor.push_back(num);
		}
		else
			return false;
	}

	if ( isXYConflict(xy_cor))
	{
		ConflictErr();
	}
	return true;
}