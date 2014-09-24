#include <iostream>
#include <cstring>
#include <iomanip>
#include <conio.h>
#include <windows.h>

#define WIDTH 6

using namespace std;

class sys;

class student
{
	friend sys;
	private:
		int num;        //׼��֤�� 
		string name;    //���� 
		string sex;     //�Ա� 
		int age;        //���� 
		string job;     //ְҵ
		student *next;  //���ӵ���һ����Ϣ 
	public:
		void get();     //��ȡ��Ϣ 
		void print();   //��ӡ��Ϣ 
		student();
		student &operator=(const student &);
		~student(){}
};

class sys
{
//	friend student;
	private:
		student *head;
		student *tail;
		int n;
		HANDLE hOut;
		CONSOLE_SCREEN_BUFFER_INFO bInfo;
	public:
		void build();                      //���� 
		void run();                        //���� 
		void stop();                       //ֹͣ 
		void ins(int pos,student *p);      //���� 
		void del(int nu);                  //ɾ�� 
		student * find(int nu);            //���� 
		void mod(int nu,student *p);       //�޸� 
		void sta();                        //ͳ�� 
		void show(int nu);                 //��ʾȫ������
		void title(); 		               //��ʾ���� 
		void initial();                    //��ʼ�� 
		sys();
		~sys();
};

int main()
{
	
	//���Ƚ�������ϵͳ 
	sys exam;
	
	//��ʼ������ϵͳ
	exam.initial(); 
	
	//���п���ϵͳ	
	exam.run();
	
	//��������ϵͳ
	exam.stop(); 
	
	return 0;
}


student::student()
{
	next=NULL;
}

//��ȡѧ����Ϣ 
void student::get()
{
	cin>>num>>name>>sex>>age>>job;
}

//��ֵ��������
student &student::operator=(const student &p)
{
	num=p.num;
	name=p.name;
	sex=p.sex;
	age=p.age;
	job=p.job;
} 

//��ӡѧ����Ϣ 
void student::print()
{
	//��ȿ���
	cout<<left
		<<setw(WIDTH)<<num
		<<setw(WIDTH)<<name
		<<setw(WIDTH)<<sex
		<<setw(WIDTH)<<age
		<<setw(WIDTH)<<job
		<<endl;
	
}

void sys::title()
{
	cout<<left
		<<setw(WIDTH)<<"����"
		<<setw(WIDTH)<<"����"
		<<setw(WIDTH)<<"�Ա�"
		<<setw(WIDTH)<<"����"
		<<setw(WIDTH)<<"�������"
		<<endl;
}

//��ʾ
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

//���� 
void sys::ins(int pos,student *p)
{
	n++;
	if (pos==1)
	{
		p->next=head;
		head=p;	
		if (!tail)
			tail=head;		
	} 
	else 
	if (pos==n)
	{
		tail->next=p;
		tail=p;
	} 
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

//���� 
student *sys::find(int nu)
{
	student *temp=head;
	while (temp->num!=nu)
		temp=temp->next;
	return temp;
}

//ɾ�� 
void sys::del(int nu)
{
	student *p,*fore=head;
	
	p=find(nu);
		
	while (fore->next&&fore->next->num!=nu)
	{
//		p->print();
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

//�޸� 
void sys::mod(int nu,student *pp)
{
	
	*find(nu)=*pp;
	
}

//ͳ�� 
void sys::sta()
{
	
	
}

//���� 
void sys::build()
{
	student *p;
	int i,m;
	cout<<"�����뽨��������Ϣϵͳ��"<<endl
		<<"�����뿼��������";
	cin>>m;
	cout<<endl<<"���������뿼���Ŀ��ţ��������Ա����估�������"<<endl;
	for (i=1;i<=m;i++)
	{
		p=new student();
		p->get();
		ins(i,p);
	}
	
	cout<<endl;
	
	show(-1);
	
}

//��ʼ�� 
void sys::initial()
{
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	
	GetConsoleScreenBufferInfo(hOut,&bInfo);
	
	SetConsoleTitle("���Ա���ϵͳ");
}

void sys::run()
{
	
	cout<<"��ӭʹ�ÿ��Ա���ϵͳ��"<<endl;
	
	//���Ƚ�������ϵͳ 
	build();
	
	while (true)
	{
		int op;
		
		cout<<"��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ��������"<<endl
			<<"��ѡ����Ҫ���еĲ�����";
		cin>>op;
		cout<<endl;
		
		switch (op)
		{
			case 0:
				{
					cout<<"��л����ʹ�ã�"<<endl;
					return;
				}
			case 1:
				{
					int pos;
					student *p;
					cout<<"��������Ҫ����Ŀ���λ�ã�";
					cin>>pos;
					cout<<endl<<"����������Ҫ����Ŀ����Ŀ��ţ��������Ա����估��������!"<<endl;
					p=new student();
					p->get();
					ins(pos,p);
					
					show(p->num);
					break;
				}
			case 2:
				{
					int nu;
					cout<<"��������Ҫɾ���Ŀ����Ŀ��ţ�";
					cin>>nu;
					del(nu);
					
					show(-1);
					break;
				}
			case 3:
				{
					int nu;
					cout<<"��������Ҫ���ҵĿ����Ŀ��ţ�";
					cin>>nu;
					title();
					
					SetConsoleTextAttribute(hOut,FOREGROUND_RED|FOREGROUND_INTENSITY);
					find(nu)->print();
					SetConsoleTextAttribute(hOut,bInfo.wAttributes);
					
					
					cout<<endl;
					break;
				}
			case 4:
				{
					int nu;
					student *p;
					
					p=new student();
					
					cout<<"��������Ҫ�޸ĵĿ����Ŀ��ţ�";
					cin>>nu;
					
					cout<<endl<<"�������޸ĺ�ÿ����Ŀ��ţ��������Ա����估��������!"<<endl;
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
					cout<<"������������ԣ�"<<endl;
					break; 
				}
		}
		 
	}
	
}

void sys::stop()
{
	
	
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
	//�ͷ�����
	
	student *p=head;
	
	while (head)
	{
		head=head->next;
		delete p;
		p=head;
	} 
	
}
