#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//��ͷ 
const string title="**          ���׹���ϵͳ          **\n====================================\n**      ��ѡ��Ҫִ�еĲ�����      **\n**        1 --- ��������          **\n**        2 --- ��������          **\n**        3 --- ����              **\n**        4 --- ɾ��              **\n**        5 --- �޸�              **\n**        0 --- �˳�              **\n====================================\n";


//������� 
struct point
{
	string name;		//���� 
	point *next;		//���ֵ� 
	point *child;	 	//���� 
	point *pre;			//���ֵ� 
	point *fa;			//���� 
};

//������ 
class family
{
	private:
		point *head;
	public:
		family():head(NULL){}
		~family();
		void run();
		void build();
		point *fin(point *,string );		//���ҽ�� 
		void ins(string );					//���� 
		void del(point *);					//ɾ���Լ����ֵ� 
		void dell(point *);					//ɾ���Լ� 
		void mod(string );					//�޸� 
		void show(point *);					//չʾ���� 
};


int main()
{
	family fam;
	fam.run();
	
	system("pause");
}

family::~family()
{
	del(head);
}

void family::run()
{
	int opt;
	string s;
	point *p;
	
	build();
	
	while (true)
	{
		cout<<"��ѡ��Ҫִ�еĲ�����";
		cin>>opt;
		switch (opt)
		{
			//�˳�
			case 0:
				cout<<"��л����ʹ�ã�"<<endl;
				return; 
			//�������� 
			case 1:
				cout<<"������Ҫ���ҵ��˵�������";
				cin>>s;
				p=fin(head,s);
				if (!p)
					cout<<"���޴��ˣ�";
				else
					show(p);
					
				cout<<endl;
				break;
			//�������� 
			case 2:
				cout<<"������Ҫ���ҵ��˵�������";
				cin>>s;
				p=fin(head,s);
				if (!p)
					cout<<"���޴��ˣ�";
				else
					cout<<s<<"�������ǣ�"<<p->fa->name<<endl;
					
				cout<<endl;
				break;
				
			//���� 
			case 3:
				cout<<"������Ҫ���뵽�ļ�ͥ�����ȵ�������";
				cin>>s;
				ins(s);
				
				
				cout<<endl;
				break;
			//ɾ�� 
			case 4:
				cout<<"������Ҫɾ�����˵�������";
				cin>>s;
				p=fin(head,s);
				if (!p)
					cout<<"���޴��ˣ�";
				else
				{
					dell(p);
				}
				
				cout<<endl;
				break;
			//�޸� 
			case 5:
				cout<<"������Ҫ�޸ĵ��˵�������";
				cin>>s;
				mod(s);
				
				cout<<endl;
				break;
			default:
				cout<<"�������������"<<endl;
				cout<<endl;
		}
		
		
	}
	
	
}

void family::build()
{
	string s;
	
	cout<<title;
	
	cout<<"�����뽨�����ȣ�"<<endl;
	cout<<"���������ȵ�������";
	cin>>s;
	head=new point();
	head->name=s;
	head->next=NULL;
	head->child=NULL;
	head->pre=NULL;
	head->fa=head;
}

point *family::fin(point *p,string name)
{
	point *pp;
	
	//��ָ�� 
	if (!p)
		return p;
	//�ҵ��� 
	if (p->name==name)
		return p;
	//���ֵ� 
	pp=fin(p->next,name);
	if (pp)
		return pp;
	else
		//�Ҷ��� 
		return fin(p->child,name);
	
}

void family::ins(string name)
{
	int i,n;
	string s;
	point *tem;
	point *pp;
	point *p=fin(head,name);
	if (!p)
	{
		cout<<"���޴��ˣ�"<<endl;
		return;
	}
	
	cout<<"������"<<p->name<<"�Ķ�Ů������";
	cin>>n;
	cout<<"������"<<p->name<<"�Ķ�Ů�������Կո�ָ�����";
	
	//�Ѿ��ж����� 
	if (p->child)
	{
		pp=p->child;
		while (pp->next!=NULL)
			pp=pp->next;
		for (i=0;i<n;i++)
		{
			cin>>s;
			tem=new point();
			tem->name=s;
			tem->next=NULL;
			tem->child=NULL;
			tem->fa=p;
			tem->pre=pp;
			pp->next=tem;
			pp=pp->next;
		}
	}
	//��û�ж��� 
	else
	{
		cin>>s;
		tem=new point();
		tem->name=s;
		tem->next=NULL;
		tem->pre=NULL;
		tem->child=NULL;
		tem->fa=p;
		
		p->child=tem;
		pp=p->child;
		
		for (i=0;i<n-1;i++)
		{
			cin>>s;
			tem=new point();
			tem->name=s;
			tem->next=NULL;
			tem->child=NULL;
			tem->fa=p;
			tem->pre=pp;
			pp->next=tem;
			pp=pp->next;
		}
	}
	
	show(p);
	
}

//���ֵܺͶ��Ӷ�ɾ��� 
void family::del(point *p)
{
	if (!p)
		return;
	del(p->child);
	del(p->next);
	delete p;
	
}

//ɾ����ǰ�㲢������ǰ��ĵ� 
void family::dell(point *p)
{
	point *fa;
	
	//ɾ������ 
	del(p->child);
	fa=p->fa;
	
	//��ǰ��ͷ 
	if (p->pre==NULL)
	{
		//����Ƕ����� 
		if (p->next==NULL)
		{
			fa->child=NULL;
			
		}
		else
		{
			fa->child=p->next;
		}
	}
	else
		//��ǰ��β�� 
		if (p->next==NULL)
		{
			p->pre->next=NULL;
		}
		else
		{
			p->pre->next=p->next;
		}
		
	delete p;
} 
 

void family::mod(string name)
{
	string s;
	point *p;
	p=fin(head,name);
	if (!p)
	{
		cout<<"���޴��ˣ�"<<endl;
		return;
	}
	cout<<"��������ĺ��������";
	cin>>s;
	p->name=s;
}

void family::show(point *src)
{
	point *p=src->child;
	cout<<src->name<<"�ĵ�һ�������ǣ�";
	if (!p)
	{
		cout<<"�ޣ�"<<endl;
		return;
	}

	while (p)
	{
		cout<<p->name<<"   ";
		p=p->next;
	}
	cout<<endl;
}
