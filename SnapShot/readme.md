[TOC]

# 环境
c++

boost库(split和正则）

单元测试google test工具

 
---

# 文件说明
- SnapShot.h : 头文件 
- SnapShot.cpp : 实现函数 
- SnapShotTest.cpp : 使用gtest工具单元测试代码
- run_main.cpp : 主函数，通过SnapShot.h中的宏定义`_TEST`进行单元测试或者运行
- SnapShotTime.h : 时间类的头文件
- SnapShotTime.cpp： 时间类的实现函数
- SnapShotTimeTest.cpp ：时间类的测试文件

---
# 流程图
```flow
st=>start: 开始
e=>end: 结束
op1=>operation: 分割字符串
op2=>operation: 读入id行
cond1=>condition: 是否合法
op3=>operation: 读入时间行
cond2=>condition: 是否合法
cond22=>condition: 是否有效
op4=>operation: 读入动物坐标行
cond3=>condition: 是否合法
cond4=>condition: 是否有效
cond5=>condition: 是否空行
cond6=>condition: 是否为查找的id
op5=>operation: 输出当前状态

st->op1->op2->cond1
cond1(yes)->op3
cond1(no)->e
op3->cond2
cond2(yes)->cond22
cond2(no)->e
cond22(yes)->op4
cond22(no)->e
op4->cond3
cond3(no)->e
cond3(yes)->cond4
cond4(no)->e
cond4(yes)->cond5
cond5(yes)->cond6
cond5(no)->op4
cond6(yes)->op5
cond6(no)->op2
op5->e
```

---
# 代码说明
## 成员变量
```
typedef pair<int ,int > Coordinate;  // 坐标
typedef map<string,Coordinate> StatusInfo; // 动物名，坐标的map，最后的状态集合
string id;  // 当前的读取的最新id
string curAnimalName;	// 当前的读取的最新动物名
Coordinate curCordinate;  // 当前的最新的坐标
int LineMode;	// 第几行
SnapShotTime LatestTime;  // 记录上一个时间
```

## 成员函数

### 检查有效性,合法性
```
	// validate check
	bool isIDLegal(string IDLine);
	bool isTimeLegal(string TimeLine);
	bool isTimeConflict(string TimeLine);
	bool isXYLegal(string XYLine,vector<int> &xy_cor);
	bool isXYConflict(vector<int>& xy_cor);
	bool splitXY(string XYLine, vector<string> & result);
```
检查原则
> - id: 不包含空格
> - 时间： yyyy/mm/dd hh:mm:ss；当前时间比上一时间大
> - 坐标，以空格分割： 数目：初次出现为3 或者 第二次出现为5，其余均不合法； 是否含无效字符：数字坐标中含字母； 是否和上次状态匹配

### set/get属性值
```
	// set and get attribute
	void setID(string _id);
	string getID();

	void setLatestTime(SnapShotTime _LatestTime);
	SnapShotTime getLastestTime();

	void setAnimalName(string _AnimalName);
	string getAnimalName();

	void setcurCordinate(int x, int y);
	void updatecurCordinate(Coordinate &preStatus,int x, int y);
	Coordinate getCordinate();

	void setLineMode(int _LineMode);
	int getLineMode();

	void updateLatestStatus(StatusInfo::iterator  it);
	void addLatestStatus();
	string getLatestStatusString();
	StatusInfo& getLatestStatus();
```


---

# 单元测试说明
## class SnapShot测试
> SnapShotTest.cpp
> 

- 检查id合法

TEST(SnapShot, isIDLegal) 

输入：有空格的id

- 检查时间合法

TEST(SnapShot, isTimeLegal)

输入：不符合格式的时间

- 分割动物坐标信息行，检查输入数目有效

TEST(SnapShot, splitXY)

输入：只含有3个坐标的字符串

- 检查坐标信息合法

TEST(SnapShot, isXYLegal)

输入：含有字母的字符串

- 检查坐标信息有效

TEST(SnapShot, isXYConflict)

输入：在已经出现的情况下，代入两个坐标点

- 设置获取状态

TEST(SnapShot, setValues)

输入：set和get是否匹配

- 接口函数测试

TEST(SnapShot, GetSnapShot)

输入：样例，坐标错误，时间比上次少

## class SnapShotTime测试
> SnapShotTimeTest.cpp
> 

-  重载赋值运算符 =

TEST(SnapShotTime, operator_COPY) 

-  重载大于运算符 >

TEST(SnapShotTime, operator_bigger) 

- 设置获取状态

TEST(SnapShotTime, setTimeValues)

输入：set和get是否匹配


---

# github链接
[github - lulu](https://github.com/lulu920819/PracticeCode/tree/master/SnapShot)

[csdn - lulu](http://blog.csdn.net/github_30830155)

---

# 改进之处
1. 判断时间，现在只是正则检查格式和数字，而没有对时间的合理性进行检查，比如闰年，可以用正则，待修改（2016/09/22 done）
2. 时间也会存在冲突，下一个时间要满足比上一个时间大（2016/09/22 done）
