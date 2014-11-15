#include <iostream>
#include <cstdlib>

using namespace std;


struct edge
{
	int x;
	int y;
	int val;
};

edge ele[1000];//边 
int n,m,i,j,sum=0;
int fa[1000];//并查集记录父亲 
bool flag[1000];//该边是否使用 

//并查集找爸爸 
int getFa(int x)
{
	int fx;
	fx=(x==fa[x])?x:getFa(fa[x]);
	fa[x]=fx;//路径压缩 
	return fx;
}

//并查集合并 
void uUnion(int x,int y)
{
	int fx,fy;
	fx=getFa(x);
	fy=getFa(y);
	fa[fy]=fx;
}

//快速排序 
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
	cout<<"请输入小区数N和电网数M：";
	cin>>n>>m;
	
	for (i=0;i<n;i++)
		fa[i]=i;
	
	cout<<"请依次输入M条电网数，每行三个数，分别表示两个顶点和费用：\n";
	for (i=0;i<m;i++)
		cin>>ele[i].x>>ele[i].y>>ele[i].val;
	
	//克鲁斯卡尔算法 
	qsort(ele,0,m-1);	
	
	for (i=0;i<m;i++)
		if (getFa(ele[i].x)!=getFa(ele[i].y))
		{
			sum+=ele[i].val;
			uUnion(ele[i].x,ele[i].y);//合并 
			flag[i]=true;//使用了该边 
		}
	
	
	cout<<"\n最少费用为："<<sum<<endl;
	cout<<"方案如下：\n";
	for (i=0;i<m;i++)
		if (flag[i])
			cout<<ele[i].x<<" "<<ele[i].y<<endl;
	
	system("pause");
	
	return 0;
}
