#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

struct pointer
{
	int key,height;
	pointer *left,*right;
};

int i,data,n,opt;
pointer *root=NULL,*p;

char title[255]="**          平衡二叉树          **\n==================================\n**     1 --- 插入元素           **\n**     2 --- 查询元素           **\n**     3 --- 中缀遍历           **\n**     4 --- 退出程序           **\n==================================\n";

 
int h(pointer *x)
{
	if (x==NULL)
		return -1;
	else
		return x->height;
}

int max(int x,int y)
{
	return x>y?x:y;
}

pointer *SingleRotateWithLeft(pointer *x)
{
	pointer *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->height=max(h(x->left),h(x->right))+1;
	y->height=max(h(y->left),h(y->right))+1;
	return y;
}

pointer *SingleRotateWithRight(pointer *x)
{
	pointer *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->height=max(h(x->left),h(x->right))+1;
	y->height=max(h(y->left),h(y->right))+1;
	return y;
}

pointer *DoubleRotateWithLeft(pointer *x)
{
	x->left=SingleRotateWithRight(x->left);
	return SingleRotateWithLeft(x);
}

pointer *DoubleRotateWithRight(pointer *x)
{
	x->right=SingleRotateWithLeft(x->right);
	return SingleRotateWithRight(x);
}

pointer *Insert(int X,pointer *T)
{
	if (T==NULL)
	{
		T=new pointer();
		T->key=X;
		T->left=NULL;
		T->right=NULL;
		T->height=0;
	}
	else
		if (X<T->key)
		{
			T->left=Insert(X,T->left);
			if (h(T->left)-h(T->right)==2)
				if (X<T->left->key)
					T=SingleRotateWithLeft(T);
				else
					T=DoubleRotateWithLeft(T);
		}
		else
		{
			T->right=Insert(X,T->right);
			if (h(T->right)-h(T->left)==2)
				if (X>T->right->key)
					T=SingleRotateWithRight(T);
				else
					T=DoubleRotateWithLeft(T);
		}
	T->height=max(h(T->left),h(T->right));
	return T;
}

void print(pointer *root)
{
	if (root==NULL)
		return;
	print(root->left);
	cout<<root->key<<" ";
	print(root->right);
}

void Pprint(pointer *root)
{
	cout<<"平衡树为：";
	print(root);
	cout<<"\n\n";
}

bool search(int x,pointer *T)
{
	if (T==NULL)
		return false;
	if (x==T->key)
		return true;
	if (x<T->key)
		return search(x,T->left);
	else
		return search(x,T->right);
}

int main()
{
 
/**
**测试单元 
	srand(time(0));
	
	cin>>n;
	root=NULL;
	for (i=0;i<n;i++)
	{
		data=rand()%100;
		cout<<data<<endl;
		root=Insert(data,root);
	}	
	
	print(root);
	
	cin>>data;
	
	cout<<search(data,root);
*/

	cout<<title;
	
	cout<<"首先请建立初始二叉树！\n";
	cout<<"请输入元素个数n：";
	cin>>n;
	cout<<"请依次输入n个元素：\n";
	for (i=0;i<n;i++)
	{
		cin>>data;
		root=Insert(data,root);
	}
	Pprint(root);
	
	while (1)
	{
		cout<<"请选择操作：";
		cin>>opt;
		switch (opt)
		{
			case 1:
				cout<<"请输入要插入的元素：";
				cin>>data;
				Insert(data,root);
				Pprint(root);
				break;
			case 2:
				cout<<"请输入要查询的元素：";
				cin>>data;
				if (search(data,root))
					cout<<"该元素存在！";
				else
					cout<<"该元素不存在！";
				cout<<"\n\n";
				break;
			case 3:
				Pprint(root);
				break;
			case 4:
				cout<<"感谢您的使用，再见！\n";
				return 0;
				break;
			default:
				cout<<"输入错误，请重试！\n\n";
				break; 
		}
	}
	
	return 0;
}
