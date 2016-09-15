/*
csdn: http://blog.csdn.net/github_30830155/article/details/52549574
*/

#include<stdio.h>
class A
{
public:
	virtual void Test()
	{
		printf("A test\n");
	}
};

class B: public A
{
public:
	void func()
	{
		Test();
	}
	virtual void Test()
	{
		printf("B test\n");
	}
};

class C: public B
{
public:
	virtual void Test()
	{
		printf("C test\n");
	}
};

int main()
{
	C c;
	((B *)(&c))->func();   // DISPLAY：C test
	((B)c).func();    // DISPLAY：B test

}