#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int a[100];
int b[100];
int i,j,n;

//Ã°ÅÝÅÅÐò 
void bubbleSort(int a[],int n)
{
	int i,j,t;
	for (i=0;i<n-1;i++)
		for (j=i+1;j<n;j++)
			if (a[j]<a[i])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
}

//Ñ¡ÔñÅÅÐò
void selectSort(int a[],int n)
{
	int i,j,min,t;
	for (i=0;i<n;i++)
	{
		min=i;
		for (j=i+1;j<n;j++)
			if (a[j]<a[min])
				min=j;
		if (min!=i)
		{
			t=a[min];
			a[min]=a[i];
			a[i]=t;
		}
	}
}

//²åÈëÅÅÐò
void insertSort(int a[],int n)
{
	int i,j,t;
	for (i=1;i<n;i++)
	{
		t=a[i];
		j=i;
		while (j>0&&a[j-1]>t)
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=t;
	}
}

//Ï£¶ûÅÅÐò
 void shellSort(int a[],int n)
 {
 	int i,j,t;
 	
 }

 
//¿ìËÙÅÅÐò 
void quickSort(int a[],int left,int right)
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
	quickSort(a,left,j);
	quickSort(a,i,right);
	
}

void siftDown(int now)
{
    int x,j;
    x=a[now];
    do
    {
        if (2*now>n)
            break;
        else
            j=2*now;
        if ((2*now+1<=n)&&(a[2*now+1]<a[2*now]))
            j=2*now+1;
        if (a[j]<x)
        {
            a[now]=a[j];
            now=j;
        } 
        else
            break;
    }
    while(1);
    a[now]=x;
}

void siftUp(int now)
{
	int x,i;
	x=a[now];
	do
	{
		i=now/2;
		if (x<a[i])
		{
			a[now]=a[i];
			now=i;
		}
		else
			break;
	}
	while (1);
	a[now]=x;
}

void createHeap()
{
    int i;
    i=0;
	for (i=n;i>0;i--)
	{
		siftDown(i);
	}
}

//¶ÑÅÅÐò
void heapSort(int a[],int n)
{
	int i=0;
	createHeap();
	while (n>0)
	{
		b[i]=a[1];
		a[1]=a[n];
		n--;
		i++;
		siftDown(1);
	}
} 

//¹é²¢ÅÅÐò
void mergeSort(int a[],int n)
{
		
}

//ÇóÊý¾Ý×î´óÎ» 
int maxbit(int a[],int n)
{
	int d=1;
	int p=10;
	for (int i=0;i<n;i++)
	{
		while (a[i]>=p)
		{
			p*=10;
			d++;
		}
	}
	return d;
}


//»ùÅÅÐò
void bucketSort(int a[],int n)
{
	int d=maxbit(a,n);
}
  

int main()
{
	srand(time(0));	
	
	cin>>n;
	for (i=0;i<n;i++)
	{
		a[i]=rand()%101;
		b[i]=a[i];	
	}
	
//	bubbleSort(a,n);
//	selectSort(a,n);
//	insertSort(a,n);
//	quickSort(a,0,n-1);
//	heapSort(a,n);
	
	for (i=0;i<n;i++)
		cout<<a[i]<<" ";
	
	return 0;
}
