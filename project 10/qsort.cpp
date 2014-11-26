#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int a[100];
int i,j,n;

void qsort(int a[],int left,int right)
{
	int i,j,mid,t;
	if (left>right)
		return;
	i=left;
	j=right;
	mid=(i+j)>>1;
	
	do
	{
		while (a[i]<a[mid]) i++;
		while (a[j]>a[mid]) j--;
		
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
	srand(time(0));

	cin>>n;
	for (i=0;i<n;i++)
		a[i]=rand()%101;
	qsort(a,0,n-1);
	for (i=0;i<n;i++)
		cout<<a[i]<<" ";
	
	return 0;
}
