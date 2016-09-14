#include<iostream>
using namespace std;

typedef struct node
{
	struct node *leftChild;
	struct node *rightChild;
	int data;
}BiTreeNode, *BiTree;


void Fibonacc()
{

}

BiTreeNode createBiTree(BiTree &T,int n)
{
	int c;
    if(n==2||n==1)
    {
        N = new BiTreeNode;
		N->data = 1;
		return N;
    }
	else
	{
		T = new BiTreeNode;
		T->data = f(n);
		createBiTree(T->leftChild,n-1);
		createBiTree(T->rightChild,n-2);
	}
}

int main()
{
	BiTree T;
	createBiTree(T);

	return 0;
}
