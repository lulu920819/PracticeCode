#include <iostream>
#include <vector>
using namespace std;

// BST的结点
typedef struct node
{
	int key;
	struct node *lChild, *rChild;
}Node, *BST;

// 在给定的BST中插入结点，其数据域为element, 使之称为新的BST
bool BSTInsert(Node * &p, int element)
{
	if(NULL == p) // 空树
	{
		p = new Node;
		p->key = element;
		p->lChild = p->rChild = NULL;
		return true;
	}

	if(element == p->key) // BST中不能有相等的值
		return false;

	if(element < p->key)  // 递归
		return BSTInsert(p->lChild, element);

	return BSTInsert(p->rChild, element); // 递归
}

// 建立BST
void createBST(Node * &T, int a[], int n)
{
	T = NULL;
	int i;
	for(i = 0; i < n; i++)
	{
		BSTInsert(T, a[i]);
	}
}

// 先序遍历
void preOrderTraverse(BST T)
{
	if(T)
	{
		cout << T->key << " ";
		preOrderTraverse(T->lChild);
		preOrderTraverse(T->rChild);
	}
}

// 中序遍历
void inOrderTraverse(BST T)
{
	if(T)
	{
		inOrderTraverse(T->lChild);
		cout << T->key << " ";
		inOrderTraverse(T->rChild);
	}
}

// 层次遍历
void print_by_level(BST T) {
    vector<Node *> vec;
    vec.push_back(T);
    int cur = 0;
    int end = 1;
    while (cur < vec.size()) {
        end = vec.size();
        while (cur < end) {
            cout << vec[cur]->key << " ";
            if (vec[cur]->lChild)
                vec.push_back(vec[cur]->lChild);
            if (vec[cur]->rChild)
                vec.push_back(vec[cur]->rChild);
            cur++;
        }
        cout << endl;
    }
}

int main()
{
	int a[6] = {2, 3, 7, 5, 6, 0};
	int n = 6;
	BST T;

	// 并非所有的a[]都能构造出BST,所以，最好对createBST的返回值进行判断
	createBST(T, a, n);

	cout << "preOrderTraverse"<< endl;
	preOrderTraverse(T);
	cout << endl;

	cout << "inOrderTraverse"<< endl;
	inOrderTraverse(T);
	cout << endl;

	cout << "print_by_level"<< endl;
    print_by_level(T);
    cout << endl;

	return 0;
}
