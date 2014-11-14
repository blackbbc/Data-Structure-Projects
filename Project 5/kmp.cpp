#include <iostream>
#include <cstring>

using namespace std;

int i,j,n,m;

char a[100],b[100];
int p[100];

int find()
{
    int i,j,sum=0;
    j=-1;

    for (i=0;i<n;i++)
    {
        while(j>=0&&b[j+1]!=a[i])
            j=p[j];
                
        if (b[j+1]==a[i])
            j++;
        if (j==m-1)
        {
//            return (i-m+1);
			sum=sum+1;
            j=p[j];
        }

    }

   return sum; 
}


      
void initial()
{
    p[0]=-1;
    j=-1;
    
    for(i=1;i<m;i++)
    {

        while (j>=0&&b[j+1]!=b[i])
            j=p[j];
        if (b[j+1]==b[i])
            j++;
        p[i]=j;
    }
}


int main()
{
	cin.getline(a,100);
	cin.getline(b,100);
	n=strlen(a);
	m=strlen(b);
	
	initial();
	
	cout<<find();
	
    return 0;
}
