#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *left, *right;
} treeNode;

treeNode* insertBST(treeNode *p,int k)
{
	if(p==NULL)
	{
	p=(treeNode *)malloc(sizeof(treeNode));
	p->val=k;
	p->left=p->right=NULL;
	}
	else if(k==p->val)
	{
	return 0;
	}
	else if(k>p->val)
	{
	insertBST(p->right, k);
	}
	else
	{
	insertBST(p->left, k);
	}
	return p;
}

treeNode *createBST(int A[], int n)
{
	treeNode *bt=NULL;
	int i=0;
	while(i<n)
	{
	insertBST(bt,A[i]);
	i++;
	}
	return bt;
}

void LevelTraverse(treeNode *root)
{
    if(root == NULL)
        return;
    treeNode* a[50];
    a[0] = root;
    int beg = 0;     //表示该层的第一个元素
    int end = 0;     //表示该层的最后一个元素
    int pos_end = 0; //表示目前访问的元素存放的位置
    while(beg <= end)
    {
        if(a[beg]->left != NULL)
            a[++pos_end] = a[beg]->left;
        if(a[beg]->right != NULL)
            a[++pos_end] = a[beg]->right;
        cout << a[beg]->val << " ";
        ++beg;
        if(beg > end)
        {
            end = pos_end;
            cout << endl;
        }
    }
}

int main()
{
	treeNode *root;
	int A[50];
	A ={2,3,7,5,6,0};
	root = createBST(int A[], 6);
	LevelTraverse(treeNode *root);
	return 0;
}



