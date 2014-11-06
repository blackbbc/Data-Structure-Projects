#include <iostream>
#include <stack>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

char a[100],*b;
char pri[255];	   //����������ȼ� 
stack<char> expe;  //�洢����ջ 


//Ԥ����������ȼ� 
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


//��׺ת��׺ 
char *houzhui(char *ss,int n)
{
    int i,j,m=0;
    char t;
    
    n++;
    char *a=new char[n];
    strcpy(a,ss);
    
    //��#��Ϊ���ʽ������־ 
    a[n-1]='#';

    char *temp=new char[n];

    expe.push('\0');


	//������ʽ 
    for (i=0;i<n;i++)
    {
    	//���������ֱ����� 
        if (isdigit(a[i]))
        {
            temp[m]=a[i];
            m++; 
        }
        else
        {

			//�����(��ֱ����չ 
            if (a[i]=='(')
                expe.push('(');
            else
            	//�����)����ջֱ��������һ��( 
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
                //����������������������������ȼ�ȷ���Ƿ��ջ 
                else
                {
                	//����ǿ���ջ��Ԫ�����ȼ����ڵ�ǰ���ţ���ջ 
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

//��׺תǰ׺ 
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


//ʹ�ú�׺���ʽ��ֵ 
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
    
    cout<<"��������ʽ��";
    cin>>a;
    cout<<endl;
    
    cout<<"�������ʽ��";
    b=qianzhui(a,strlen(a));
    cout<<b<<endl<<endl;
    
    cout<<"��׺���ʽ��";
    cout<<a<<endl<<endl;
    
    cout<<"�沨�����ʽ��";
	b=houzhui(a,strlen(a));
    cout<<b<<endl<<endl;
    
    cout<<"���ʽ��ֵ��";
    cout<<countexp(b)<<endl<<endl;
    
    system("pause");
    

    return 0;
}
