#include <iostream>
#include <string>

using namespace std;

int n,m,sum,upperlim;
int ans[20];

void printAns()
{
    int i,j;
	int aa[20];
	for (i=0;i<20;i++)
		aa[i]=ans[i];

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
			cout<<aa[i]%2<<' ';
            aa[i]=aa[i]>>1;
        
        }
        cout<<endl;
    }
    cout<<endl;
}

void test(int row,int ld,int rd)
{
    int pos,p;

    if (row!=upperlim)
    {
        pos=upperlim&~(row|ld|rd);
        while (pos)
        {
            p=pos&-pos;
            ans[m]=p;
            m++;
            pos-=p;
            test(row+p,(ld+p)<<1,(rd+p)>>1);
            m--;
        }

    }
    else
    {
        printAns();
        sum++;
    }

}

int main()
{
    cin>>n;
    m=0;
    upperlim=(1<<n)-1;
    test(0,0,0);
    cout<<sum;
    return 0;
}
