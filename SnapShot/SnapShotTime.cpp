#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>  
#include "SnapShotTime.h"

using namespace std;
using namespace boost; 

SnapShotTime::SnapShotTime(string str)
{
	vector<string> tmp;
	split(tmp,str,is_space(),token_compress_on);

	setDate(tmp.at(0));
	setTime(tmp.at(1)) ;
}

SnapShotTime::SnapShotTime()
{
	setDate("0000/00/00");
	setTime("00:00:00") ;
}

SnapShotTime::~SnapShotTime()
{

}

string SnapShotTime::getDate()
{
	return SSDate;
}
void SnapShotTime::setDate(string _SSDate)
{
	SSDate = _SSDate;
}
string SnapShotTime::getTime()
{
	return SSTime;
}
void SnapShotTime::setTime(string _SSTime)
{
	SSTime = _SSTime;
}

bool  SnapShotTime:: operator > ( SnapShotTime cur)
{
	return bigger((*this) , cur);
}

void  SnapShotTime:: operator = ( SnapShotTime cur)
{
	setDate(cur.getDate());
	setTime(cur.getTime());
}
 
 bool SnapShotTime:: bigger( SnapShotTime ss1,  SnapShotTime ss2)
 {
	 if (ss1.getDate()<ss2.getDate())
		 return false;
	 else if(ss1.getDate()>ss2.getDate())
		 return true;
	 else
	  return ss1.getTime()>ss2.getTime();
 }