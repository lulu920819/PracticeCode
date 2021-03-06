#include <gtest/gtest.h> 
#include "SnapShot.h"
#ifdef _TEST

TEST(SnapShotTime, operator_bigger) 
{ 
	// do some initialization 
	string str1 = "2016/09/02      22:30:52";
	SnapShotTime ss1 = SnapShotTime(str1); 


	string str2= "2016/09/02      22:30:52";
	SnapShotTime ss2 = SnapShotTime(str2); 

	// 时间相同
	EXPECT_FALSE(ss1>ss2);

	// 日期+1  时间减少
	ss2.setDate("2016/09/03"); 
	ss2.setTime("22:36:52"); 
	EXPECT_TRUE(ss1.getDate()<ss2.getDate());
	EXPECT_FALSE(ss1>ss2);
	EXPECT_TRUE(ss2>ss1);

	// 日期不变 时间改变
	ss2.setDate("2016/09/02"); 
	EXPECT_FALSE(ss1>ss2);
	EXPECT_TRUE(ss2>ss1);

}

TEST(SnapShotTime, operator_COPY) 
{ 
	// do some initialization 
	string str1 = "2016/09/02      22:30:52";
	SnapShotTime ss1 = SnapShotTime(str1); 

	SnapShotTime ss2 = ss1;

	EXPECT_TRUE(ss1.getDate() == ss2.getDate());
	EXPECT_TRUE(ss1.getTime() == ss2.getTime());

}


TEST(SnapShotTime, setTimeValues)
{
	// do some initialization 
	string str1 = "2016/09/02      22:30:52";
	SnapShotTime ss = SnapShotTime(str1); 

	// validate the pointer is not null 

	EXPECT_STREQ("2016/09/02",ss.getDate().c_str());
	EXPECT_STREQ("22:30:52",ss.getTime().c_str());
	
	string date1 ="2016/09/02";
	string time1 = "22:38:52";
	ss.setDate(date1);
	ss.setTime(time1);

	EXPECT_STREQ(date1.c_str(),ss.getDate().c_str());
	EXPECT_STREQ(time1.c_str(),ss.getTime().c_str());

}

#endif // _TEST
