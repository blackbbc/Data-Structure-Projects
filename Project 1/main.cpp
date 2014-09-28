#include <iostream>
#include <cstring>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <cctype>

#define WIDTH 6

using namespace std;

class sys;

class student
{
	friend sys;
	private:
		int num;        //准考证号 
		string name;    //姓名 
		string sex;     //性别 
		int age;        //年龄 
		string job;     //职业
		student *next;  //链接到下一条信息 
	public:
		void get();     //获取信息 
		void print();   //打印信息 
		student();
		student &operator=(const student &); //为了防止指针被乱用 重载赋值函数 
		~student(){}
};

class sys
{
//	friend student;
	private:
		student *head;                     //链表的头 
		student *tail;                     //链表的尾巴 
		int n;                             //考生数量 
		HANDLE hOut;                       //控制台句柄 
		CONSOLE_SCREEN_BUFFER_INFO bInfo;  //控制台信息 
	public:
		void build();                      //建立 
		void run();                        //运行 
		void stop();                       //停止 
		void ins(int pos,student *p);      //插入 
		void del(int nu);                  //删除 
		student * find(int nu);            //查找 
		void mod(int nu,student *p);       //修改 
		void sta();                        //统计 
		void show(int nu);                 //显示全部数据
		void title(); 		               //显示标题 
		void initial();                    //初始化 
		sys();
		~sys();
};

int main()
{
	
	//首先建立考试系统 
	sys exam;
	
	//初始化考试系统
	exam.initial(); 
	
	//运行考试系统	
	exam.run();
	
	//结束考试系统
	exam.stop(); 
	
	return 0;
}

//判断一个字符串是否为数字，如果是就返回这个数字，如果不是则返回-1 
int is_digit(string s)
{
	int n=s.length();
	int sum=0;
	
	for (int i=0;i<n;i++)
	{
		if (!isdigit(s[i]))
			return -1;
		else
		{
			sum=sum*10+s[i]-'0';
		}
	}
	
	return sum;
}


student::student()
{
	next=NULL;
}


//获取学生信息 
void student::get()
{
	string s;
	string temp;
	string error="";
	int pos;
	
	
	
	//先输入字符串，然后拆分字符串，判断每一位是否合法 
	while (1)
	{
		
		getline(cin,s);
		
		pos=s.find_first_of(" ",0);
		temp=s.substr(0,pos);
		s.erase(0,pos+1);
		if (temp==""||is_digit(temp)==-1)
		{
			cout<<"学号输入有误，请重试！"<<endl;
			continue;
		}
		num=is_digit(temp);
		
		pos=s.find_first_of(" ",0);
		temp=s.substr(0,pos);
		s.erase(0,pos+1);
		if (temp=="")
		{
			cout<<"姓名输入有误，请重试！"<<endl;
			continue;
		}
		name=temp;
		
		pos=s.find_first_of(" ",0);
		temp=s.substr(0,pos);
		s.erase(0,pos+1);
		if (temp=="")
		{
			cout<<"性别输入有误，请重试！"<<endl;
			continue;
		}
		sex=temp;
		
		pos=s.find_first_of(" ",0);
		temp=s.substr(0,pos);
		s.erase(0,pos+1);
		if (temp==""||is_digit(temp)==-1)
		{
			cout<<"年龄输入有误，请重试！"<<endl;
			continue;
		}
		age=is_digit(temp);
		
		temp=s;
		if (temp=="")
		{
			cout<<"报考类别输入有误，请重试！"<<endl;
			continue;
		}
		job=temp;
		
		
		
		break;
	}
	
}

//赋值函数重载
student &student::operator=(const student &p)
{
	num=p.num;
	name=p.name;
	sex=p.sex;
	age=p.age;
	job=p.job;
} 

//打印学生信息 
void student::print()
{
	//宽度控制
	cout<<left
		<<setw(WIDTH)<<num
		<<setw(WIDTH)<<name
		<<setw(WIDTH)<<sex
		<<setw(WIDTH)<<age
		<<setw(WIDTH)<<job
		<<endl;
	
}

//打印标题头 
void sys::title()
{
	cout<<left
		<<setw(WIDTH)<<"考号"
		<<setw(WIDTH)<<"姓名"
		<<setw(WIDTH)<<"性别"
		<<setw(WIDTH)<<"年龄"
		<<setw(WIDTH)<<"报考类别"
		<<endl;
}


//显示数据库信息，并且将nu号学生高亮显示 
void sys::show(int nu)
{
	
	student *p=head;
	
	title();
		
	while (p)
	{
		if (p->num==nu)
		{
			SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_INTENSITY);
			p->print();
			SetConsoleTextAttribute(hOut,bInfo.wAttributes);
		}
		else
		{
			p->print();
		}
		
		p=p->next;
	}
	
	cout<<endl;
	
} 

//插入 
void sys::ins(int pos,student *p)
{
	n++;
	
	//插到头 
	if (pos==1)
	{
		p->next=head;
		head=p;	
		if (!tail)
			tail=head;		
	} 
	else 
	//插到尾 
	if (pos==n)
	{
		tail->next=p;
		tail=p;
	} 
	//插到中间 
	else
	{
		int i=0;
		student *temp=head;
		
		for (i=0;i<pos-2;i++)
			temp=temp->next;
		p->next=temp->next;
		temp->next=p;
	}
}

//查找 
student *sys::find(int nu)
{
	student *temp=head;
	while (temp!=NULL&&temp->num!=nu)
		temp=temp->next;
	return temp;
}

//删除 
void sys::del(int nu)
{
	student *p,*fore=head;
	
	p=find(nu);
		
	//寻找所需元素的父亲 
	while (fore->next&&fore->next->num!=nu)
	{
		fore=fore->next;
	}
	
	if (p==head)
	{
		head=head->next;
		delete p;
	}
	else
	if (p)
	{
		fore->next=p->next;
		delete p;
	}
	
	cout<<endl;
}

//修改 
void sys::mod(int nu,student *pp)
{
	
	*find(nu)=*pp;
	
}

//统计 
void sys::sta()
{
	show(-1);
	cout<<"一共有"<<n<<"名考生"<<endl;
	
}

//建立 
void sys::build()
{
	student *p;
	int i,m;
	cout<<"首先请建立考生信息系统！"<<endl
		<<"请输入考生人数：";
	cin>>m;
	cout<<endl<<"请依次输入考生的考号，姓名，性别，年龄及报考类别！"<<endl;
	cin.get();
	for (i=1;i<=m;i++)
	{
		p=new student();
		p->get();
		ins(i,p);
	}
	
	cout<<endl;
	
	show(-1);
	
}

//初始化 
void sys::initial()
{
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);//获取控制台句柄 
	
	GetConsoleScreenBufferInfo(hOut,&bInfo);//获取控制台信息 
	
	SetConsoleTitle("考试报名系统");
}

void sys::run()
{
	
	cout<<"欢迎使用考试报名系统！"<<endl;
	
	//首先建立考试系统 
	build();
	
	while (true)
	{
		int op;
		
		cout<<"请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）"<<endl
			<<"请选择您要进行的操作：";
		cin>>op;
		cout<<endl;
		
		//针对输入的情况进行判定 
		switch (op)
		{
			
			
			case 0:
				{
					cout<<"感谢您的使用！"<<endl;
					return;
				}
				
			//插入 
			case 1:
				{
					int pos;
					student *p;
					string temp;
					cout<<"请输入您要插入的考生位置：";
					
					//数据验证 
					while (cin>>temp)
					{
						if (is_digit(temp)>0&&is_digit(temp)<=n+1)
						{
							pos=is_digit(temp);
							break;
						}
						cout<<"输入错误，请重试！"<<endl;
					}
					
					
					
					cout<<endl<<"请依次输入要插入的考生的考号，姓名，性别，年龄及报考类型!"<<endl;
					p=new student();
					
					cin.get();
					p->get();
					ins(pos,p);
					
					show(p->num);
					break;
				}
				
			//删除 
			case 2:
				{
					string temp;
					int nu;
					cout<<"请输入您要删除的考生的考号：";
					
					//数据验证 
					while (cin>>temp)
					{
						if (is_digit(temp)>0)
						{
							nu=is_digit(temp);
							break;
						}
						cout<<"输入错误，请重试！"<<endl;
					}
					
					del(nu);
					
					show(-1);
					break;
				}
				
			//查找 
			case 3:
				{
					string temp;
					int nu;
					student *p;
					cout<<"请输入您要查找的考生的考号：";
					
					
					//数据验证 
					while (cin>>temp)
					{
						if (is_digit(temp)>0)
						{
							nu=is_digit(temp);
							break;
						}
						cout<<"输入错误，请重试！"<<endl;
					}
					
					
					p=find(nu);
					
					if (p==NULL)
						cout<<"查无此人！";
					else
					{
						title();
						SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_INTENSITY);
						p->print();
						SetConsoleTextAttribute(hOut,bInfo.wAttributes);
					}
					

					
					
					cout<<endl;
					break;
				}
				
			//修改 
			case 4:
				{
					int nu;
					student *p;
					string temp;
					
					p=new student();
					
					cout<<"请输入您要修改的考生的考号：";


					//数据验证 
					while (cin>>temp)
					{
						if (is_digit(temp)>0)
						{
							nu=is_digit(temp);
							break;
						}
						cout<<"输入错误，请重试！"<<endl;
					}
					
					if (find(nu)==NULL)
					{
						cout<<"查无此人！"<<endl;
						break;
					}
					
					cout<<endl<<"请输入修改后该考生的考号，姓名，性别，年龄及报考类型!"<<endl;
					
					cin.get();
					p->get();
					
					mod(nu,p);
					
					show(p->num);
					
					delete p;
					
					break;
				}
			case 5:
				{
					sta();
					break;
				}
			default:
				{
					cout<<"输入错误，请重试！"<<endl;
					break; 
				}
		}
		 
	}
	
}

void sys::stop()
{
	//关闭句柄 
	CloseHandle(hOut);
}

sys::sys()
{
	head=NULL;
	tail=NULL;
	n=0;
}

sys::~sys()
{
	//释放链表
	
	student *p=head;
	
	while (head)
	{
		head=head->next;
		delete p;
		p=head;
	} 
	
}
