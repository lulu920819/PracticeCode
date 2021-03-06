#include <gtest/gtest.h> 
#include "SnapShot.h"
#ifdef _TEST


TEST(SnapShot, isIDLegal) 
{ 
	// do some initialization 
	SnapShot* ss = new SnapShot(); 

	// validate the pointer is not null 
	ASSERT_TRUE(ss != NULL); 

	// call the method we want to test 
	
	string str1 = "fjdkfjdifjinvjdv";
	string str2 = "dfdgfb fgkffkmgf";

	// validate the result after operation 
	EXPECT_TRUE(ss->isIDLegal(str1));
	EXPECT_FALSE(ss->isIDLegal(str2));

	delete ss; 
}

TEST(SnapShot, isTimeLegal) 
{ 
	// do some initialization 
	SnapShot* ss = new SnapShot(); 

	// validate the pointer is not null 
	ASSERT_TRUE(ss != NULL); 
	// call the method we want to test 

	string str1 = "2016/09/02       22:30:52";  //合法
	string str2 = "2016/02/29  22:30:52";  //闰年
	string str3 = "2017/02/29 25:30:578";  //非闰年 02 29
	string str4 = "16:09:02 22:30:52";  //格式不对
	string str5 = "2016/09/0222:30:52";  ////格式不对
	string str6 = "2016/09/02 22:3a0:52";  ////格式不对
	string str7 = "2017/03/35 01:30:57";  //日期不对
	string str8 = "2017/03/04 1:30:67";  //时间不对
	// validate the result after operation 
	EXPECT_TRUE(ss->isTimeLegal(str1));
	EXPECT_TRUE(ss->isTimeLegal(str2));
	EXPECT_FALSE(ss->isTimeLegal(str3));
	EXPECT_FALSE(ss->isTimeLegal(str4));
	EXPECT_FALSE(ss->isTimeLegal(str5));
	EXPECT_FALSE(ss->isTimeLegal(str6));
	EXPECT_FALSE(ss->isTimeLegal(str7));
	EXPECT_FALSE(ss->isTimeLegal(str8));

	delete ss; 
}

TEST(SnapShot, splitXY) 
{ 
	// do some initialization 
	SnapShot* ss = new SnapShot(); 

	// validate the pointer is not null 
	ASSERT_TRUE(ss != NULL); 

	// call the method we want to test 

	string str1 = "cat1 5 6 7      1";
	string str2 = "cat1 5 6 7";
	vector<string> res;
	// validate the result after operation 
	EXPECT_TRUE(ss->splitXY(str1,res));
	EXPECT_FALSE(ss->splitXY(str2,res));
	delete ss; 
}


TEST(SnapShot, isXYLegal) 
{ 
	// do some initialization 
	SnapShot* ss = new SnapShot(); 

	// validate the pointer is not null 
	ASSERT_TRUE(ss != NULL); 
	// call the method we want to test 

	string str1 = "cat1 5 -6 -7 1";
	string str2 = "cat1 5 a c 1";
	string str3 = "cat1 5 6 7";
	vector<int> res;
	// validate the result after operation 
	EXPECT_TRUE(ss->isXYLegal(str1,res));
	EXPECT_STREQ("cat1",ss->getAnimalName().c_str());
	EXPECT_EQ(5,res[0]);
	EXPECT_EQ(-6,res[1]);
	EXPECT_EQ(-7,res[2]);
	EXPECT_EQ(1,res[3]);

	EXPECT_FALSE(ss->isXYLegal(str2,res));
	EXPECT_FALSE(ss->isXYLegal(str3,res));
	
	delete ss; 
}


TEST(SnapShot, isXYConflict) 
{ 
	// do some initialization 
	SnapShot* ss = new SnapShot(); 

	// validate the pointer is not null 
	ASSERT_TRUE(ss != NULL); 
	// call the method we want to test 
	// map of status is null 
	vector<int> xy_cor;
	xy_cor.push_back(5);
	xy_cor.push_back(6);
	ss->setAnimalName("cat1");
	// validate the result after operation 
	EXPECT_TRUE(ss->isXYConflict(xy_cor));
	EXPECT_FALSE(ss->isXYConflict(xy_cor));
	

	delete ss; 
}

TEST(SnapShot, setValues)
{
	// do some initialization 
	SnapShot* ss = new SnapShot(); 

	// validate the pointer is not null 
	ASSERT_TRUE(ss != NULL); 
	
	//  setcurCordinate
	int x  = 1; int y =2;
	ss->setcurCordinate(x,y);
	Coordinate c = ss->getCordinate();
	// validate the result after operation 
	EXPECT_EQ(x,c.first);
	EXPECT_EQ(y,c.second);

	// setAnimalName
	string  name = "cat1";
	ss->setAnimalName(name);
	EXPECT_STREQ(name.c_str(),ss->getAnimalName().c_str());

	// add to map
	ss->addLatestStatus();
	EXPECT_STREQ("cat1 1 2\n",ss->getLatestStatusString().c_str());

	// insert to map
	ss->updatecurCordinate(c,4,6);  // 5 8
	Coordinate c2 = ss->getCordinate();
	EXPECT_EQ(x+4,c2.first);
	EXPECT_EQ(y+6,c2.second);  

	StatusInfo&  m=  ss->getLatestStatus();
	StatusInfo::iterator it = m.begin();
	ss->updateLatestStatus(it);
	EXPECT_STREQ("cat1 5 8\n",ss->getLatestStatusString().c_str());


	delete ss; 
}

TEST(SnapShot, GetSnapShot) 
{ 
	// do some initialization 
	SnapShot* c1 = new SnapShot(); 
	SnapShot* c2 = new SnapShot();
	SnapShot* c3 = new SnapShot();
	// validate the pointer is not null 
	ASSERT_TRUE(c1 != NULL); 
	ASSERT_TRUE(c2 != NULL); 
	ASSERT_TRUE(c3 != NULL); 
	// call the method we want to test 


	// 例子
	string historyData1 = "e4e87cb2-8e9a-4749-abb6-26c59344dfee\n2016/09/02 22:30:46\n	cat1 10 9\n\n351055db-33e6-4f9b-bfe1-16f1ac446ac1\n2016/09/02 22:30:52\ncat1 10 9 2 -1\ncat2 2 3\n\ndcfa0c7a-5855-4ed2-bc8c-4accae8bd155\n2016/09/02 22:31:02\ncat1 12 8 3 4\n";
	string id = "dcfa0c7a-5855-4ed2-bc8c-4accae8bd155";
	string answer1 = "cat1 15 12\ncat2 2 3\n";
	// validate the result after operation 
	EXPECT_STREQ(answer1.c_str(),c1->GetSnapShot(historyData1,id).c_str());

	// 坐标冲突
	string historyData2 = "e4e87cb2-8e9a-4749-abb6-26c59344dfee\n2016/09/02 22:30:46\n	cat1 10 9\n\n351055db-33e6-4f9b-bfe1-16f1ac446ac1\n2016/09/02 22:30:52\ncat1 10 9 2 -1\ncat2 2 3\n\ndcfa0c7a-5855-4ed2-bc8c-4accae8bd155\n2016/09/02 22:31:02\ncat1 11 8 3 4\n";
	// validate the result after operation 
	EXPECT_STREQ("Conflict found at dcfa0c7a-5855-4ed2-bc8c-4accae8bd155",c2->GetSnapShot(historyData2,id).c_str());

	// 时间冲突  下一个时间小
	string historyData3 = "e4e87cb2-8e9a-4749-abb6-26c59344dfee\n2016/09/02 22:30:46\n	cat1 10 9\n\n351055db-33e6-4f9b-bfe1-16f1ac446ac1\n2016/09/02 23:30:52\ncat1 10 9 2 -1\ncat2 2 3\n\ndcfa0c7a-5855-4ed2-bc8c-4accae8bd155\n2016/09/02 22:31:02\ncat1 11 8 3 4\n";
	// validate the result after operation 
	EXPECT_STREQ("Conflict found at dcfa0c7a-5855-4ed2-bc8c-4accae8bd155",c3->GetSnapShot(historyData3,id).c_str());

	delete c1; 
	delete c2; 
	delete c3; 
}

#endif // _TEST
