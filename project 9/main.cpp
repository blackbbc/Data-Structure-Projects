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

char title[255]="**          ƽ�������          **\n==================================\n**     1 --- ����Ԫ��           **\n**     2 --- ��ѯԪ��           **\n**     3 --- ��׺����           **\n**     4 --- �˳�����           **\n==================================\n";

 
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
	cout<<"ƽ����Ϊ��";
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
**���Ե�Ԫ 
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
	
	cout<<"�����뽨����ʼ��������\n";
	cout<<"������Ԫ�ظ���n��";
	cin>>n;
	cout<<"����������n��Ԫ�أ�\n";
	for (i=0;i<n;i++)
	{
		cin>>data;
		root=Insert(data,root);
	}
	Pprint(root);
	
	while (1)
	{
		cout<<"��ѡ�������";
		cin>>opt;
		switch (opt)
		{
			case 1:
				cout<<"������Ҫ�����Ԫ�أ�";
				cin>>data;
				Insert(data,root);
				Pprint(root);
				break;
			case 2:
				cout<<"������Ҫ��ѯ��Ԫ�أ�";
				cin>>data;
				if (search(data,root))
					cout<<"��Ԫ�ش��ڣ�";
				else
					cout<<"��Ԫ�ز����ڣ�";
				cout<<"\n\n";
				break;
			case 3:
				Pprint(root);
				break;
			case 4:
				cout<<"��л����ʹ�ã��ټ���\n";
				return 0;
				break;
			default:
				cout<<"������������ԣ�\n\n";
				break; 
		}
	}
	
	return 0;
}
