#include "SnapShot.h"
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>     
using namespace std;
using namespace boost; 
#define DELIME '\n'


string SnapShot::GetSnapShot(string historyData, string id)
{
	if(historyData.empty())
	{
		cout<<"Invalid format."<<endl;
		exit(0);
	}

	size_t last = 0;  
	size_t index=historyData.find_first_of(DELIME,last);  
	while (index!=std::string::npos)  
	{  
		string line = historyData.substr(last,index-last);  
		trim(line);
		cout<<"line  --- "<<line<<endl;
		if(LineMode==3&&line.empty())
			LineMode = 1;
		switch (LineMode)
		{
		case 1:   // id
			if(line.empty())
				break;
			if(isIDLegal(line))
			{
				setID(line);
				LineMode++;
				if (id.compare(getID())==0)
				{
					isResult = true;
				}
			}
			else
				//InvalidErr();
			break;
		case 2:  // time
			if(isTimeLegal(line))
				LineMode++;
			else
				//InvalidErr();
			break;
		case 3: //xy
			if(isXYLegal(line))
			{	
				
				if(isResult)
					//display
					return getResult();
				
			}
			else
				InvalidErr();
			break;
		default:
			break;
		}
		last=index+1;  
		index=historyData.find_first_of(DELIME,last);  
	}  
	//if (index-last>0)  
	//{  
	//	string line = historyData.substr(last,index-last) ;  
	//}  
	return NULL;  // CAN'T FIND
}


SnapShot::SnapShot()
{
	this->isResult=false;
	this->id = "";
	this->LineMode=1;
}

void SnapShot::setAnimalName(string _AnimalName)
{
	curAnimalName = _AnimalName;
}
string SnapShot::getAnimalName()
{
	return curAnimalName;
}

void SnapShot::setID(string _id)
{
	id = _id;
}

string SnapShot::getID()
{
	return id;
}

void SnapShot::InvalidErr()
{
	cout<<"Invalid format."<<endl;
	exit(0);
}
void SnapShot::ConflictErr()
{
	cout<<"Conflict found at "<<getID();
	exit(0);
}


bool SnapShot::isIDLegal(string IDLine)
{
	// 全部为数字
	regex reg("(//w+)");
	bool result = regex_match(IDLine,reg);
	return result;
}
bool SnapShot::isTimeLegal(string TimeLine)
{
	// yyyy/MM/dd HH:mm:ss 
	regex reg("(([0-9]{3}[1-9]|[0-9]{2}[1-9][0-9]{1}|[0-9]{1}[1-9][0-9]{2}|[1-9][0-9]{3})/(((0[13578]|1[02])-(0[1-9]|[12][0-9]|3[01]))|((0[469]|11)/(0[1-9]|[12][0-9]|30))|(02-(0[1-9]|[1][0-9]|2[0-8]))))|((([0-9]{2})(0[48]|[2468][048]|[13579][26])|((0[48]|[2468][048]|[3579][26])00))-02-29) \s+((((0?[0-9])|([1][0-9])|([2][0-4]))\\:([0-5]?[0-9])((\\s)|(\\:([0-5]?[0-9])))))?$");
	bool result = regex_match(TimeLine,reg);
	return result;
}

bool SnapShot::isXYLegal(string XYLine)
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

bool SnapShot::isXYConflict(vector<int> xy_cor)
{
	// cat1 10 9 2 -1 or cat1 10 9
	/* 1. cat1 not in map but has 4 nums
		2. cat1 in map but has 2 nums
		3. nums not match
	*/
	map<string , Coordinate>::iterator  iter;
	iter = LatestStatus.find(getAnimalName());
	if(iter!=LatestStatus.end()) //in the list
	{
		if (xy_cor.size()==2)
			return false;
		Coordinate preStatus = iter->second;
		if (preStatus.first!=xy_cor[0]||preStatus.second!=xy_cor[1])
			return false;
		else
		{
			curCordinate = make_pair(preStatus.first+xy_cor[2],preStatus.second+xy_cor[3]);
			iter->second = curCordinate;
		}

	}
	else
	{
		if (xy_cor.size()==4)
			return false;
		curCordinate = make_pair(xy_cor.at(0),xy_cor.at(1));
		LatestStatus.insert(make_pair(getAnimalName(),curCordinate));
		
	}
	return true;
}


string SnapShot::getResult()
{
	string result;
	for (map<string, Coordinate>::iterator  it = LatestStatus.begin();it!=LatestStatus.end();it++)
	{
		result.append(it->first); 
		result.append(" ");
		result.append(lexical_cast<string>(it->second.first));
		result.append(" ");
		result.append(lexical_cast<string>(it->second.second));
		result.append(1,'\n');
	}
	return result;
}