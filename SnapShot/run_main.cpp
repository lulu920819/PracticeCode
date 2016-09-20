#include "SnapShot.h"
#include <iostream>
using namespace std;
#ifndef _TEST
int main()
{
	string historyData = "e4e87cb2-8e9a-4749-abb6-26c59344dfee\n2016/09/02 22:30:46\n	cat1 10 9\n\n351055db-33e6-4f9b-bfe1-16f1ac446ac1\n2016/09/02 22:30:52\ncat1 10 9 2 -1\ncat2 2 3\n\ndcfa0c7a-5855-4ed2-bc8c-4accae8bd155\n2016/09/02 22:31:02\ncat1 12 8 3 4\n";
	string id = "dcfa0c7a-5855-4ed2-bc8c-4accae8bd155";
	//cout<<historyData<<endl;
	//cout<<id<<endl;
	SnapShot *ss = new SnapShot;
	string res = ss->GetSnapShot(historyData,id);
	cout<<"------------"<<endl;
	cout<<res<<endl;

	return 0;
}
#else
#include <gtest/gtest.h>
int main(int argc, char** argv) { 
	testing::InitGoogleTest(&argc, argv); 

	// Runs all tests using Google Test. 
	return RUN_ALL_TESTS(); 
}
#endif