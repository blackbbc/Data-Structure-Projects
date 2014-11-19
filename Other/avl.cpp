#include <iostream>
#include <stack>
#include <cstdlib>
#include <time.h>

using namespace std;

struct pointer
{
	int key,height;
	pointer *left,*right;
};

int i,data,n;
pointer *root,*p;

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

//平衡树删除 
//非递归写法？ 
bool Delete(int X,pointer *T)
{
	pointer *p=T,*pr=NULL,*ppr,*q,*ptr;
	stack<pointer *>st;
	
	//寻找删除位置，并用栈记录（父亲）路径 
	while (p!=NULL)
	{
		if (X==p->key)
			break;
		pr=p;
		st.push(pr);
		if (X<p->key)
			p=p->left;
		else
			p=p->right;
	}
	
	if (p==NULL)
		return false;
	
	//有两个子女，在左子树找直接前驱 
	if (p->left!=NULL && p->right!=NULL)
	{
		pr=p;
		st.push(pr);
		q=p->left;
		
		while (q->right!=NULL)
		{
			pr=q;
			st.push(pr);
			q=q->right;
		}
		
		p->key=q->key;//用直接前驱填补
		p=q;//移到直接前驱 
	}
	
	//一个子女的情况，移动到其中一个子女身上 
	if (p->left!=NULL)
		q=p->left;
	else
		q=p->right;
	
	//被删节点是根节点
	if (pr==NULL)
		ptr=q;
	else
	{
		//在干什么？？？？ 
		if (pr->left==p)
			pr->left=q;
		else
			pr->right=q;
		
		//回溯 
		while (!st.empty())
		{
			st.pop();
			
		}
	} 
}

void print(pointer *root)
{
	if (root==NULL)
		return;
	print(root->left);
	cout<<root->key<<" ";
	print(root->right);
}

int main()
{
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
	
	return 0;
}
