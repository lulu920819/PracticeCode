#include <stdio.h>
#include <stdlib.h>

struct A{
	void foo(){
		printf("foo");
	}

	virtual void bar(){
		printf("bar");
	}

	A() {
		bar();
	}
};

struct B : A
{
	void foo(){
		printf("b_foo");
	}

	void bar(){
		printf("b_bar");
	}

};

void main()
{
	A * p = new B;
	p->foo();
	p->bar();
	printf("\n");
}

