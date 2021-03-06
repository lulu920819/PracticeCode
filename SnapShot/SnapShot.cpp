#include "SnapShot.h"
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>     
using namespace std;
using namespace boost; 



string SnapShot::GetSnapShot(string historyData, string id)
{
	if(historyData.empty())
	{
		return InvalidErr();
	}

	size_t last = 0;  
	size_t index=historyData.find_first_of(DELIME,last);  
	while (index!=string::npos)  
	{  
		
		string line = historyData.substr(last,index-last);
		trim(line);
		int linemode = getLineMode();
		//cout<<linemode<<"---line "<<line<<endl;		
		//cout<<line.size()<<"size:"<<endl;
		if(line.size()==0)
		{
			setLineMode(0);
		}

		vector<int> xy_cor;
		switch (getLineMode())
		{
		case 1:   // id
			if(isIDLegal(line))
			{
				if (id==(getID())) // end of the program
				{
					return getLatestStatusString();
				}
				setID(line);
				setLineMode(2);
			}
			else
				return InvalidErr();
			break;
		case 2:  // time
			if(isTimeLegal(line))
			{
				if(isTimeConflict(line)==false)
					return ConflictErr(id);
				setLineMode(3);
			}		
			else
				return InvalidErr();
			break;
		case 3: //xy
			if(isXYLegal(line,xy_cor)==true)
			{	
				if(isXYConflict(xy_cor)==false)
					return ConflictErr(id);
			}
			else
				return	InvalidErr();
			break;
		default:
			setLineMode(1);
			break;
		}
		last=index+1;  
		index=historyData.find_first_of(DELIME,last);  
	}  
	if (id==(getID())) // end of the program	
		return getLatestStatusString();
	else
		return "can	't find";  // CAN'T FIND
}


SnapShot::SnapShot()
{
	setID("");
	setLineMode(1);
}

SnapShot::~SnapShot()
{
	
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

void SnapShot::setLatestTime(SnapShotTime _LatestTime)
{
	LatestTime = _LatestTime;
}

SnapShotTime  SnapShot::getLastestTime()
{
	return LatestTime;
}

void SnapShot::updatecurCordinate(Coordinate &preStatus,int x, int y)
{
	curCordinate.first =preStatus.first+x;
	curCordinate.second=preStatus.second+y;
}

void SnapShot::setcurCordinate(int x, int y)
{
	curCordinate .first = x;
	curCordinate.second = y;
}

Coordinate SnapShot::getCordinate()
{
	return curCordinate;
}

void SnapShot::setLineMode(int _LineMode)
{
	LineMode = _LineMode;
}
int SnapShot::getLineMode()
{
	return LineMode;
}

void SnapShot::updateLatestStatus(StatusInfo::iterator  it)
{
	it->second = this->curCordinate;
}

void SnapShot::addLatestStatus()
{
		LatestStatus.insert(make_pair(this->curAnimalName,this->curCordinate));
}

StatusInfo& SnapShot::getLatestStatus()
{
	return LatestStatus;
}

string SnapShot::getLatestStatusString()
{
	string result;
	for (StatusInfo::iterator  it = LatestStatus.begin();it!=LatestStatus.end();it++)
	{
		result.append(it->first); 
		result.append(SPACE);
		result.append(lexical_cast<string>(it->second.first));
		result.append(SPACE);
		result.append(lexical_cast<string>(it->second.second));
		result.append(1,'\n');
	}
	return result;
}

string SnapShot::InvalidErr()
{
	//cout<<"Invalid format."<<endl;
	return "Invalid format.";
	//exit(0);
}

string SnapShot::ConflictErr(string id)
{
	//cout<<"Conflict found at "<<getID();
	string error = "Conflict found at "+id;
	return error;
	//exit(0);
}

bool SnapShot::isIDLegal(string IDLine)
{
	size_t index=IDLine.find_first_of(SPACE,0);  
	if (index == string::npos)
	{
		return true;
	}
	return false;
}

bool SnapShot::isTimeConflict(string TimeLine)
{
	SnapShotTime cur = SnapShotTime(TimeLine);
	SnapShotTime lastest = getLastestTime();
	if(cur>getLastestTime())
	{
		setLatestTime(cur);
		return true;
	}
	else
	{
		
		return false;	
	}
}

bool SnapShot::isTimeLegal(string TimeLine)
{
	// yyyy/MM/dd HH:mm:ss   是否比上一次大
	//regex reg("[0-9]{4}/(0[0-9]|1[0-2])/([0-2][0-9]|3[01])(\\s)+([01][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]");  // 基本匹配  仅格式(闰年，月份，未考虑）
	
	// 年0001-9999 yyyy  ： [0-9]{3}[1-9]|[0-9]{2}[1-9][0-9]{1}|[0-9]{1}[1-9][0-9]{2}|[1-9][0-9]{3}
	// 平年的（2月28） MM/dd :  30 天的  31 天的  28 天的 三个或者  (((0[13578]|1[02])/(0[1-9]|[12][0-9]|3[01]))|((0[469]|11)/(0[1-9]|[12][0-9]|30))|(02/(0[1-9]|[1][0-9]|2[0-8])))
	// 闰年 2.29 (([0-9]{2})(0[48]|[2468][048]|[13579][26])|((0[48]|[2468][048]|[3579][26])00))/02/29
	// 空格 (\\s)+
	// 时间： ([01][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]
	regex reg ("(((([0-9]{3}[1-9]|[0-9]{2}[1-9][0-9]{1}|[0-9]{1}[1-9][0-9]{2}|[1-9][0-9]{3})/(((0[13578]|1[02])/(0[1-9]|[12][0-9]|3[01]))|((0[469]|11)/(0[1-9]|[12][0-9]|30))|(02/(0[1-9]|[1][0-9]|2[0-8]))))|((([0-9]{2})(0[48]|[2468][048]|[13579][26])|((0[48]|[2468][048]|[3579][26])00))/02/29))(\\s)+([01][0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9])");
	bool result = regex_match(TimeLine,reg);
	return result;           
}


bool SnapShot::splitXY(string XYLine, vector<string> & result)
{
	split(result,XYLine,is_space(),token_compress_on);
	if (result.size()==3||result.size()==5)
		return true;
	else
		return false;
}

bool SnapShot::isXYLegal(string XYLine,vector<int> &xy_cor)
{
	// cat1 10 9 2 -1 or cat1 10 9
	regex reg("[+-]*(\\d)+");
	vector<string> result;
	bool isLegal;
	isLegal =  splitXY(XYLine,result);
	if (isLegal== false)
		return isLegal;

	setAnimalName(result.at(0));
	for(size_t i = 1;i<result.size();i++)
	{
		bool isNum = regex_match(result.at(i),reg);
		if (isNum)
		{
			int num = lexical_cast<int>(result[i]);  
			xy_cor.push_back(num);
		}
		else
			return false;
	}
	return true;
}

bool SnapShot::isXYConflict(vector<int>& xy_cor)
{
	// cat1 10 9 2 -1 or cat1 10 9
	/* 1. cat1 not in map but has 4 nums
		2. cat1 in map but has 2 nums
		3. nums not match
	*/
	StatusInfo &curStatus = getLatestStatus();
	StatusInfo::iterator  iter;

	iter = curStatus.find(getAnimalName());
	if(iter!=curStatus.end()) //in the list
	{
		if (xy_cor.size()==2)
			return false;
		Coordinate preStatus = iter->second;
		if (preStatus.first==xy_cor[0]&&preStatus.second==xy_cor[1])
		{
			updatecurCordinate(preStatus,xy_cor[2],xy_cor[3]);
			updateLatestStatus(iter);
		}	
		else
			return false;

	}
	else
	{
		if (xy_cor.size()==4)
			return false;
		setcurCordinate(xy_cor.at(0),xy_cor.at(1));
		addLatestStatus();		
	}
	return true;
}
