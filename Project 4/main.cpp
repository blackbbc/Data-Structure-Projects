#include <iostream>


using namespace std;

int n,sum,upperlim;

void test(int row,int ld,int rd)
{
    int pos,p;

    if (row!=upperlim)
    {
        pos=upperlim&~(row|ld|rd);
        while (pos)
        {
            p=pos&-pos;
            pos-=p;
            test(row+p,(ld+p)<<1,(rd+p)>>1);

        }


    }
    else
    {
        sum++;
    }




}

int main()
{


   // cout<<(10&-10);

    cin>>n;

    upperlim=(1<<n)-1;
    test(0,0,0);
    cout<<sum;

    return 0;


}
