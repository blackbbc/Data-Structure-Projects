#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//题头 
const string title="**          家谱管理系统          **\n====================================\n**      请选择要执行的操作：      **\n**        1 --- 查找子孙          **\n**        2 --- 查找祖先          **\n**        3 --- 插入              **\n**        4 --- 删除              **\n**        5 --- 修改              **\n**        0 --- 退出              **\n====================================\n";


//结点类型 
struct point
{
	string name;		//名称 
	point *next;		//右兄弟 
	point *child;	 	//儿子 
	point *pre;			//左兄弟 
	point *fa;			//父亲 
};

//整棵树 
class family
{
	private:
		point *head;
	public:
		family():head(NULL){}
		~family();
		void run();
		void build();
		point *fin(point *,string );		//查找结点 
		void ins(string );					//插入 
		void del(point *);					//删除自己和兄弟 
		void dell(point *);					//删除自己 
		void mod(string );					//修改 
		void show(point *);					//展示儿子 
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
		cout<<"请选择要执行的操作：";
		cin>>opt;
		switch (opt)
		{
			//退出
			case 0:
				cout<<"感谢您的使用！"<<endl;
				return; 
			//查找子孙 
			case 1:
				cout<<"请输入要查找的人的姓名：";
				cin>>s;
				p=fin(head,s);
				if (!p)
					cout<<"查无此人！";
				else
					show(p);
					
				cout<<endl;
				break;
			//查找祖先 
			case 2:
				cout<<"请输入要查找的人的姓名：";
				cin>>s;
				p=fin(head,s);
				if (!p)
					cout<<"查无此人！";
				else
					cout<<s<<"的祖先是："<<p->fa->name<<endl;
					
				cout<<endl;
				break;
				
			//插入 
			case 3:
				cout<<"请输入要插入到的家庭的祖先的姓名：";
				cin>>s;
				ins(s);
				
				
				cout<<endl;
				break;
			//删除 
			case 4:
				cout<<"请输入要删除的人的姓名：";
				cin>>s;
				p=fin(head,s);
				if (!p)
					cout<<"查无此人！";
				else
				{
					dell(p);
				}
				
				cout<<endl;
				break;
			//修改 
			case 5:
				cout<<"请输入要修改的人的姓名：";
				cin>>s;
				mod(s);
				
				cout<<endl;
				break;
			default:
				cout<<"输入错误！请重试"<<endl;
				cout<<endl;
		}
		
		
	}
	
	
}

void family::build()
{
	string s;
	
	cout<<title;
	
	cout<<"首先请建立祖先！"<<endl;
	cout<<"请输入祖先的姓名：";
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
	
	//空指针 
	if (!p)
		return p;
	//找到了 
	if (p->name==name)
		return p;
	//找兄弟 
	pp=fin(p->next,name);
	if (pp)
		return pp;
	else
		//找儿子 
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
		cout<<"查无此人！"<<endl;
		return;
	}
	
	cout<<"请输入"<<p->name<<"的儿女个数：";
	cin>>n;
	cout<<"请输入"<<p->name<<"的儿女姓名（以空格分隔）：";
	
	//已经有儿子了 
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
	//还没有儿子 
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

//把兄弟和儿子都删光光 
void family::del(point *p)
{
	if (!p)
		return;
	del(p->child);
	del(p->next);
	delete p;
	
}

//删除当前点并且连接前面的点 
void family::dell(point *p)
{
	point *fa;
	
	//删除儿子 
	del(p->child);
	fa=p->fa;
	
	//当前是头 
	if (p->pre==NULL)
	{
		//如果是独生子 
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
		//当前是尾巴 
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
		cout<<"查无此人！"<<endl;
		return;
	}
	cout<<"请输入更改后的姓名：";
	cin>>s;
	p->name=s;
}

void family::show(point *src)
{
	point *p=src->child;
	cout<<src->name<<"的第一代子孙是：";
	if (!p)
	{
		cout<<"无！"<<endl;
		return;
	}

	while (p)
	{
		cout<<p->name<<"   ";
		p=p->next;
	}
	cout<<endl;
}
