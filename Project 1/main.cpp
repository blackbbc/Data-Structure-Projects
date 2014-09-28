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
		student &operator=(const student &); //Ϊ�˷�ָֹ�뱻���� ���ظ�ֵ���� 
		~student(){}
};

class sys
{
//	friend student;
	private:
		student *head;                     //�����ͷ 
		student *tail;                     //�����β�� 
		int n;                             //�������� 
		HANDLE hOut;                       //����̨��� 
		CONSOLE_SCREEN_BUFFER_INFO bInfo;  //����̨��Ϣ 
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

//�ж�һ���ַ����Ƿ�Ϊ���֣�����Ǿͷ���������֣���������򷵻�-1 
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


//��ȡѧ����Ϣ 
void student::get()
{
	string s;
	string temp;
	string error="";
	int pos;
	
	
	
	//�������ַ�����Ȼ�����ַ������ж�ÿһλ�Ƿ�Ϸ� 
	while (1)
	{
		
		getline(cin,s);
		
		pos=s.find_first_of(" ",0);
		temp=s.substr(0,pos);
		s.erase(0,pos+1);
		if (temp==""||is_digit(temp)==-1)
		{
			cout<<"ѧ���������������ԣ�"<<endl;
			continue;
		}
		num=is_digit(temp);
		
		pos=s.find_first_of(" ",0);
		temp=s.substr(0,pos);
		s.erase(0,pos+1);
		if (temp=="")
		{
			cout<<"�����������������ԣ�"<<endl;
			continue;
		}
		name=temp;
		
		pos=s.find_first_of(" ",0);
		temp=s.substr(0,pos);
		s.erase(0,pos+1);
		if (temp=="")
		{
			cout<<"�Ա��������������ԣ�"<<endl;
			continue;
		}
		sex=temp;
		
		pos=s.find_first_of(" ",0);
		temp=s.substr(0,pos);
		s.erase(0,pos+1);
		if (temp==""||is_digit(temp)==-1)
		{
			cout<<"�����������������ԣ�"<<endl;
			continue;
		}
		age=is_digit(temp);
		
		temp=s;
		if (temp=="")
		{
			cout<<"��������������������ԣ�"<<endl;
			continue;
		}
		job=temp;
		
		
		
		break;
	}
	
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

//��ӡ����ͷ 
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


//��ʾ���ݿ���Ϣ�����ҽ�nu��ѧ��������ʾ 
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
	
	//�嵽ͷ 
	if (pos==1)
	{
		p->next=head;
		head=p;	
		if (!tail)
			tail=head;		
	} 
	else 
	//�嵽β 
	if (pos==n)
	{
		tail->next=p;
		tail=p;
	} 
	//�嵽�м� 
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
	while (temp!=NULL&&temp->num!=nu)
		temp=temp->next;
	return temp;
}

//ɾ�� 
void sys::del(int nu)
{
	student *p,*fore=head;
	
	p=find(nu);
		
	//Ѱ������Ԫ�صĸ��� 
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

//�޸� 
void sys::mod(int nu,student *pp)
{
	
	*find(nu)=*pp;
	
}

//ͳ�� 
void sys::sta()
{
	show(-1);
	cout<<"һ����"<<n<<"������"<<endl;
	
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

//��ʼ�� 
void sys::initial()
{
	hOut=GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ����̨��� 
	
	GetConsoleScreenBufferInfo(hOut,&bInfo);//��ȡ����̨��Ϣ 
	
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
		
		//����������������ж� 
		switch (op)
		{
			
			
			case 0:
				{
					cout<<"��л����ʹ�ã�"<<endl;
					return;
				}
				
			//���� 
			case 1:
				{
					int pos;
					student *p;
					string temp;
					cout<<"��������Ҫ����Ŀ���λ�ã�";
					
					//������֤ 
					while (cin>>temp)
					{
						if (is_digit(temp)>0&&is_digit(temp)<=n+1)
						{
							pos=is_digit(temp);
							break;
						}
						cout<<"������������ԣ�"<<endl;
					}
					
					
					
					cout<<endl<<"����������Ҫ����Ŀ����Ŀ��ţ��������Ա����估��������!"<<endl;
					p=new student();
					
					cin.get();
					p->get();
					ins(pos,p);
					
					show(p->num);
					break;
				}
				
			//ɾ�� 
			case 2:
				{
					string temp;
					int nu;
					cout<<"��������Ҫɾ���Ŀ����Ŀ��ţ�";
					
					//������֤ 
					while (cin>>temp)
					{
						if (is_digit(temp)>0)
						{
							nu=is_digit(temp);
							break;
						}
						cout<<"������������ԣ�"<<endl;
					}
					
					del(nu);
					
					show(-1);
					break;
				}
				
			//���� 
			case 3:
				{
					string temp;
					int nu;
					student *p;
					cout<<"��������Ҫ���ҵĿ����Ŀ��ţ�";
					
					
					//������֤ 
					while (cin>>temp)
					{
						if (is_digit(temp)>0)
						{
							nu=is_digit(temp);
							break;
						}
						cout<<"������������ԣ�"<<endl;
					}
					
					
					p=find(nu);
					
					if (p==NULL)
						cout<<"���޴��ˣ�";
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
				
			//�޸� 
			case 4:
				{
					int nu;
					student *p;
					string temp;
					
					p=new student();
					
					cout<<"��������Ҫ�޸ĵĿ����Ŀ��ţ�";


					//������֤ 
					while (cin>>temp)
					{
						if (is_digit(temp)>0)
						{
							nu=is_digit(temp);
							break;
						}
						cout<<"������������ԣ�"<<endl;
					}
					
					if (find(nu)==NULL)
					{
						cout<<"���޴��ˣ�"<<endl;
						break;
					}
					
					cout<<endl<<"�������޸ĺ�ÿ����Ŀ��ţ��������Ա����估��������!"<<endl;
					
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
					cout<<"������������ԣ�"<<endl;
					break; 
				}
		}
		 
	}
	
}

void sys::stop()
{
	//�رվ�� 
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
