#include <iostream>

using namespace std;

class game;

class person
{
	friend game;
private:
	int num;
	person *llink;
	person *rlink;
public:
	person(int pos) :num(pos){}
};

class game
{
private:
	int n;
	int m;
	int s;
	int k;
	person *head;


public:
	void Initial();
	void start();
	void stop();

};


int main()
{
	game liveOrDie;
	liveOrDie.Initial();
	liveOrDie.start();
	liveOrDie.stop();

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

	for (int i = 2; i <= n; i++)
	{
		p = new person(i);
		tail->rlink = p;
		p->llink = tail;
		p->rlink = NULL;
		tail = p;
	}

	tail->rlink = head;
	head->llink = tail;

}

void game::start()
{

	int i, j;
	person *p = head,*temp;
	s--;
	if (s == 0)
		s = n;

	while (p->num != s)
		p = p->rlink;

	for (i = 0; i<n-k; i++)
	{
		for (j = 0; j<m; j++)
			p = p->rlink;

		cout << "第"<<i+1<<"个死者的位置是："<<p->num<<endl;

		if (head->num == p->num)
			head = head->rlink;

		p->llink->rlink = p->rlink;
		p->rlink->llink = p->llink;
		temp = p;
		p = p->llink;
		delete temp;

	}

	cout << endl << "最后剩下：" << k << "人" << endl;
	cout << "剩余的生者位置为：";
	p = head;
	for (i = 0; i <  k; i++)
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










