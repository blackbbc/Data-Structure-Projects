#include <iostream>

using namespace std;

class game;

class person
{
	friend game;
private:
	int num;             //序号 
	person *llink;       //左儿子 
	person *rlink;       //右儿子 
public:
	person(int pos) :num(pos){}
};

class game
{
private:
	int n;             //总人数 
	int m;             //死亡数字 
	int s;             //开始位置 
	int k;             //剩余人数 
	person *head;      //链表入口（头指针） 


public:
	void Initial();    //初始化链表 
	void start();      //开始游戏 
	void stop();       //释放链表 

};


int main()
{
	game liveOrDie;
	liveOrDie.Initial();
	liveOrDie.start();
	liveOrDie.stop();
	system("pause");
}

void game::Initial()
{
	person *p, *tail;

	cout << "请输入生死游戏的总人数N：";
	cin >> n;
	cout << "请输入游戏开始的位置S：";
	cin >> s;
	cout << "请输入死亡数字M：";
	cin >> m;
	cout << "请输入剩余的生者人数K：";
	cin >> k;
	cout << endl;

	head = new person(1);
	tail = head;

	//建立双向链表+循环链表 
	for (int i = 2; i <= n; i++)
	{
		p = new person(i);
		tail->rlink = p;
		p->llink = tail;
		p->rlink = NULL;
		tail = p;
	}
	//将头指针与尾指针链接到一起 
	tail->rlink = head;
	head->llink = tail;

}

void game::start()
{

	int i, j;
	person *p = head, *temp;
	s--;
	if (s == 0)
		s = n;
	
	//找到开始位置的前一个人，设为初始位置 
	while (p->num != s)
		p = p->rlink;

	for (i = 0; i<n - k; i++)
	{
		//数M个人 
		for (j = 0; j<m; j++)
			p = p->rlink;
		//输出序号 
		cout << "第" << i + 1 << "个死者的位置是：" << p->num << endl;
		
		//如果删除的是头指针，则将头指针往后移一位 
		if (head->num == p->num)
			head = head->rlink;
		//删除当前的P指针 
		p->llink->rlink = p->rlink;
		p->rlink->llink = p->llink;
		temp = p;
		p = p->llink;
		delete temp;

	}

	cout << endl << "最后剩下：" << k << "人" << endl;
	cout << "剩余的生者位置为：";
	
	//输出剩余人数 
	p = head;
	for (i = 0; i < k; i++)
	{
		cout << p->num << " ";
		p = p->rlink;
	}
	cout << endl;

}

void game::stop()
{
	int i;
	person *p = head;

	for (i = 0; i<k; i++)
	{
		head = head->rlink;
		delete p;
		p = head;
	}

}










