#include <iostream>

using namespace std;


struct edge
{
	int x;
	int y;
	int val;
};

edge ele[1000];
int n,m,i,j,sum=0;
int fa[1000];

int getFa(int x)
{
	int fx;
	fx=(x==fa[x])?x:getFa(fa[x]);
	fa[x]=fx;//Â·¾¶Ñ¹Ëõ 
	return fx;
}

void uUnion(int x,int y)
{
	int fx,fy;
	fx=getFa(x);
	fy=getFa(y);
	fa[fy]=fx;
}

void qsort(edge a[],int left,int right)
{
	int i,j,mid;
	edge t;
	if (left>right)
		return;
	i=left;
	j=right;
	mid=(i+j)>>1;
	
	do
	{
		while (a[i].val<a[mid].val) i++;
		while (a[j].val>a[mid].val) j--;
		
		if (i<=j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			i++;
			j--;
		}
	}
	while (i<=j);
	
	qsort(a,left,j);
	qsort(a,i,right);
	
}



int main()
{
	cin>>n>>m;
	
	for (i=0;i<n;i++)
		fa[i]=i;
	
	for (i=0;i<m;i++)
		cin>>ele[i].x>>ele[i].y>>ele[i].val;
	
	qsort(ele,0,m-1);	
	
	for (i=0;i<m;i++)
		if (getFa(ele[i].x)!=getFa(ele[i].y))
		{
			sum+=ele[i].val;
			uUnion(ele[i].x,ele[i].y);
		}
	
	cout<<sum;
	
	return 0;
}
