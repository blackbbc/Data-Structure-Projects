#include <iostream>
#include <stack>

using namespace std;

int a[100];
int flag[100];
int i,j,k,n,now,temp;
stack<int> sta;

int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
		cin>>a[i];
		
	now=1;
	
	while (true)
	{
		switch (flag[now])
		{
			case 0:
				flag[now]=1;
				sta.push(now);
				
				if (a[2*now]>0)
					now=2*now;
				else
				{
					now=sta.top();
					sta.pop();
				}
				break;
				
			case 1:
				flag[now]=2;
				sta.push(now);
				if (a[2*now+1]>0)
					now=2*now+1;
				else
				{
					now=sta.top();
					sta.pop();
				}
				break;
			case 2:
				cout<<now;
				
				if (sta.empty())
					return 0;
				else
				{
					now=sta.top();
					sta.pop();
				}
				break;
		}		

		
	}
	
	
	return 0;
}
