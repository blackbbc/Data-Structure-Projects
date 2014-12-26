#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int a[100000];
int b[100000];
int c[100000];
int temp[100000];
long countt=0;
int i,j,n;

//ð������ 
void bubbleSort(int a[],int n)
{
	int i,j,t;
	for (i=0;i<n-1;i++)
		for (j=i+1;j<n;j++)
		{
			countt++;
			if (a[j]<a[i])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}

}

//ѡ������
void selectSort(int a[],int n)
{
	int i,j,min,t;
	for (i=0;i<n;i++)
	{
		min=i;
		for (j=i+1;j<n;j++)
		{
			countt++;
			if (a[j]<a[min])
				min=j;
		}

		if (min!=i)
		{
			t=a[min];
			a[min]=a[i];
			a[i]=t;
		}
	}
}

//��������
void insertSort(int a[],int n)
{
	int i,j,t;
	for (i=1;i<n;i++)
	{
		t=a[i];
		j=i;
		while (j>0&&a[j-1]>t)
		{
			countt++;
			a[j]=a[j-1];
			j--;
		}
		a[j]=t;
	}
}

//ϣ������
void shellSort(int a[],int n)
{
	int i,j,t,gap;
	for (gap=n/2;gap>0;gap/=2)
		for (i=gap;i<n;i++)
		{
			t=a[i];
			j=0;
			for (j=i-gap;j>=0&&a[j]>t;j-=gap)
			{
				a[j+gap]=a[j];
				countt++;
			}
			a[j+gap]=t;
		}
}

 
//�������� 
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
		while (a[i]<a[mid]) 
		{
			countt++;
			i++;
		}
		while (a[j]>a[mid]) 
		{
			countt++;
			j--;
		}
		
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
    	countt++;
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
		countt++;
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

//������
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

void mergeArray(int a[],int left,int mid,int right)
{
	int i=left;
	int j=mid+1;
	int m=mid;
	int n=right;
	int k=0;
	
	while ( i<=m && j<=n)
	{
		countt++;
		if (a[i]<a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while (i<=m)
		temp[k++]=a[i++];
	while (j<n)
		temp[k++]=a[j++];
		
	for (i=0;i<k;i++)
		a[left+i]=temp[i];
}


//�鲢����
void mergeSort(int a[],int left,int right)
{
	if (left<right)
	{
		int mid=(left+right)>>1;
		mergeSort(a,left,mid);
		mergeSort(a,mid+1,right);
		mergeArray(a,left,mid,right);
	}
}

//���������λ 
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


//������
void bucketSort(int a[],int n)
{
	int d=maxbit(a,n);
	int countt[10];
	int i,j,t;
	int radix=1;
	
	//����D������ 
	for (i=0;i<d;i++)
	{
		for (j=0;j<10;j++)
			countt[j]=0;//��Ͱ�������� 
		for (j=0;j<n;j++)
		{
			t=(a[j]/radix)%10;//�����Iλ�ϵ�����
			countt[t]++; 
		}
		for (j=1;j<10;j++)
			countt[j]+=countt[j-1];//������λ�� 
		
		for (j=n-1;j>=0;j--)//�ռ�Ͱ 
		{
			t=(a[j]/radix)%10;//�����Iλ�ϵ����� 
			temp[countt[t]-1]=a[j];
			countt[t]--;
		}
		
		for (j=0;j<n;j++)
			a[j]=temp[j];
		
		radix*=10;	
	}
}

void initial(int n)
{
	countt=0;
	for (int i=0;i<n;i++)
	{
		a[i]=c[i];
		b[i]=a[i];
		temp[i]=0;
	}
}  

int main()
{
	clock_t start,finish;
	double totaltime;
	
	srand(time(0));	
	
	cout<<"������Ҫ������������ĸ�����";
	cin>>n;
	
	for (i=0;i<n;i++)
		c[i]=rand()%10000000;
	
	cout<<endl;
	
	//������ð������ 
	initial(n);
	start=clock();
	bubbleSort(a,n);
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
	cout<<"ð����������ʱ�䣺"<<totaltime<<endl;
	cout<<"ð������Ƚϴ�����"<<countt<<endl;
	cout<<endl;

	//������ѡ������ 
	initial(n);
	start=clock();
	selectSort(a,n);
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
	cout<<"ѡ����������ʱ�䣺"<<totaltime<<endl;
	cout<<"ѡ������Ƚϴ�����"<<countt<<endl;
	cout<<endl;
	
	//�������� 
	initial(n);
	start=clock();
	insertSort(a,n);
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
	cout<<"������������ʱ�䣺"<<totaltime<<endl;
	cout<<"��������Ƚϴ�����"<<countt<<endl;
	cout<<endl;
	
	//ϣ������ 
	initial(n);
	start=clock();
	shellSort(a,n);
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
	cout<<"ϣ����������ʱ�䣺"<<totaltime<<endl;
	cout<<"ϣ������Ƚϴ�����"<<countt<<endl;
	cout<<endl;
	
	//�鲢���� 
	initial(n);
	start=clock();
	mergeSort(a,0,n-1);
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
	cout<<"�鲢��������ʱ�䣺"<<totaltime<<endl;
	cout<<"�鲢����Ƚϴ�����"<<countt<<endl;
	cout<<endl;
	
	//�������� 
	initial(n);
	start=clock();
	quickSort(a,0,n-1);
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
	cout<<"������������ʱ�䣺"<<totaltime<<endl;
	cout<<"��������Ƚϴ�����"<<countt<<endl;
	cout<<endl;
	
	//������ 
	initial(n);
	start=clock();
	heapSort(a,n);
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
	cout<<"����������ʱ�䣺"<<totaltime<<endl;
	cout<<"������Ƚϴ�����"<<countt<<endl;
	cout<<endl;
	
	//�������� 
	initial(n);
	start=clock();
	bucketSort(a,n);
	finish=clock();
	totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
	cout<<"������������ʱ�䣺"<<totaltime<<endl;
	cout<<"��������Ƚϴ�����"<<countt<<endl;
	cout<<endl;
	
	system("pause");
	
	return 0;
}
