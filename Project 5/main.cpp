#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int i,j,n,m;

char b[100],temp[255],text[10000],a[10000];
int p[100];

ifstream fin;
ofstream fout;

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

void getText()
{
	char filename[255];
	cout<<"关键字检索系统"<<endl;
	cout<<"请输入文件名：";
	cin>>filename;
	
	fout.open(filename);
	
	cout<<"请输入一段英文："<<endl;
	while (cin.getline(temp,255))
		strcat(text,temp);
	
	//清除错误位 
	cin.clear();
	
	fout<<text;
	fout.close();
	
	cout<<"请输入要检索的关键字：";
	cin.getline(b,100);
	m=strlen(b);
	
	cout<<"显示源文件\" "<<filename<<" \""<<endl<<endl;
	
	fin.open(filename);
	while (fin.getline(temp,255))
		strcat(a,temp);
	n=strlen(a);
	cout<<a<<endl;
	
}

void findText()
{
	initial();	
	
	cout<<"在源文件中共检索到："<<find()<<" 个关键字\" "<<b<<" \""<<endl;
}

int main()
{
	getText();
	findText();

	
    return 0;
}
