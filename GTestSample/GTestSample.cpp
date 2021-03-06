#include "gtest/gtest.h"  
#include "sample.h"

using namespace std;

TEST(fun, case1)  
{  
	EXPECT_LT(-2, fun(1, 2)); 
	EXPECT_EQ(-1, fun(1, 2));  
	ASSERT_LT(-2, fun(1, 2)); 
	ASSERT_EQ(-1, fun(1, 2));  
}  


TEST(isIDLegal, case_IDLegal)  // 通过case2 来看名字
{  
	string  str1 = "";
	string str2 = "fdfdf  fgfgf";
	string str3 = "fdfdfdfdfgfgf";
	EXPECT_FALSE(isIDLegal(str1)); 
	EXPECT_FALSE( isIDLegal(str2));  
	EXPECT_TRUE( isIDLegal(str3));  

}  




int main(int argc, char** argv)  
{  
	testing::InitGoogleTest(&argc, argv);  
	return RUN_ALL_TESTS();  
} 

