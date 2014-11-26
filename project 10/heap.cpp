#include <iostream>

using namespace std;

int a[100];
int n;

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

int main()
{ 
    int i;
    
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];

    createHeap();

    while(n>0)
    {
    	cout<<a[1];
    	a[1]=a[n];
    	n--;
 		
		siftDown(1);
		    	
    }
    

    return 0;
}
