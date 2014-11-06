#include <iostream>
#include <stack>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

char a[100],*b;
char pri[255];	   //定义符号优先级 
stack<char> expe;  //存储符号栈 


//预处理符号优先级 
void initial()
{ 
    pri['\0']=0;
    pri['#']=0;
    pri['^']=7;
    pri['*']=5;
    pri['/']=5;
    pri['%']=5;
    pri['+']=3;
    pri['-']=3;
    pri['(']=1;
    pri[')']=1;
}


//中缀转后缀 
char *houzhui(char *ss,int n)
{
    int i,j,m=0;
    char t;
    
    n++;
    char *a=new char[n];
    strcpy(a,ss);
    
    //用#作为表达式结束标志 
    a[n-1]='#';

    char *temp=new char[n];

    expe.push('\0');


	//处理表达式 
    for (i=0;i<n;i++)
    {
    	//如果是数字直接输出 
        if (isdigit(a[i]))
        {
            temp[m]=a[i];
            m++; 
        }
        else
        {

			//如果是(，直接入展 
            if (a[i]=='(')
                expe.push('(');
            else
            	//如果是)，出栈直到弹出第一个( 
                if (a[i]==')')
                {
                    while (expe.top()!='(')
                    {
                        temp[m]=expe.top();
                        m++;
                        expe.pop();
                    }
                    expe.pop();
                }
                //如果是其他运算符，根据运算符优先级确定是否进栈 
                else
                {
                	//如果非空且栈顶元素优先级大于当前符号，出栈 
                    while ((!expe.empty())&&(pri[expe.top()]>=pri[a[i]]))
                    {
                        temp[m]=expe.top();
                        m++;
                        expe.pop();
                    }
                    expe.push(a[i]);
                }
        }
    }
    

    return temp;

}

//中缀转前缀 
char *qianzhui(char *ss,int n)
{
    int i,j,m=0;
    char swap;
    char t;
    
    
	n++;
    char *temp=new char[n];
    char *a=new char[n];
    a[0]='#';
    a[1]='\0';
    strcat(a,ss);


    for (i=n-1;i>=0;i--)
    {
        if (isdigit(a[i]))
        {
            temp[m]=a[i];
            m++; 
        }
        else
        {

            if (a[i]==')')
                expe.push(')');
            else
                if (a[i]=='(')
                {
                    while (expe.top()!=')')
                    {
                        temp[m]=expe.top();
                        m++;
                        expe.pop();
                    }
                    expe.pop();
                }
                else
                {
                    while ((!expe.empty())&&(pri[expe.top()]>pri[a[i]]))
                    {
                        temp[m]=expe.top();
                        m++;
                        expe.pop();
                    }
                    expe.push(a[i]);
                }
        }
    }
    
    temp[m]='\0';
    m++;
    
    for (i=0;i<m/2;i++)
    {
    	swap=temp[i];
    	temp[i]=temp[m-i-2];
    	temp[m-i-2]=swap;
    }

    return temp;

}


//使用后缀表达式求值 
float countexp(char *ex)
{
	int i,j;
	stack<float> ans;
	int n=strlen(ex);
	
	float a,b,c;
	
	for (i=0;i<n;i++)
	{
		if (isdigit(ex[i]))
		{
			ans.push(ex[i]-'0');
		}
		else
		{
			switch (ex[i])
			{
				case '+':
					b=ans.top();
					ans.pop();
					a=ans.top();
					ans.pop();
					c=a+b;
					ans.push(c);
					break;
				case '-':;
					b=ans.top();
					ans.pop();
					a=ans.top();
					ans.pop();
					c=a-b;
					ans.push(c);
					break;
				case '*':;
					b=ans.top();
					ans.pop();
					a=ans.top();
					ans.pop();
					c=a*b;
					ans.push(c);
					break;
				case '/':;
					b=ans.top();
					ans.pop();
					a=ans.top();
					ans.pop();
					c=a/b;
					ans.push(c);
					break;
			}
		}
		
		
	}
	
	return ans.top();
	
}




int main()
{

    initial();
    
    cout<<"请输入表达式：";
    cin>>a;
    cout<<endl;
    
    cout<<"波兰表达式：";
    b=qianzhui(a,strlen(a));
    cout<<b<<endl<<endl;
    
    cout<<"中缀表达式：";
    cout<<a<<endl<<endl;
    
    cout<<"逆波兰表达式：";
	b=houzhui(a,strlen(a));
    cout<<b<<endl<<endl;
    
    cout<<"表达式的值：";
    cout<<countexp(b)<<endl<<endl;
    
    system("pause");
    

    return 0;
}
