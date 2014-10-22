#include <iostream>

using namespace std;

class game;

class person
{
	friend game;
private:
	int num;             //��� 
	person *llink;       //����� 
	person *rlink;       //�Ҷ��� 
public:
	person(int pos) :num(pos){}
};

class game
{
private:
	int n;             //������ 
	int m;             //�������� 
	int s;             //��ʼλ�� 
	int k;             //ʣ������ 
	person *head;      //������ڣ�ͷָ�룩 


public:
	void Initial();    //��ʼ������ 
	void start();      //��ʼ��Ϸ 
	void stop();       //�ͷ����� 

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

	cout << "������������Ϸ��������N��";
	cin >> n;
	cout << "��������Ϸ��ʼ��λ��S��";
	cin >> s;
	cout << "��������������M��";
	cin >> m;
	cout << "������ʣ�����������K��";
	cin >> k;
	cout << endl;

	head = new person(1);
	tail = head;

	//����˫������+ѭ������ 
	for (int i = 2; i <= n; i++)
	{
		p = new person(i);
		tail->rlink = p;
		p->llink = tail;
		p->rlink = NULL;
		tail = p;
	}
	//��ͷָ����βָ�����ӵ�һ�� 
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
	
	//�ҵ���ʼλ�õ�ǰһ���ˣ���Ϊ��ʼλ�� 
	while (p->num != s)
		p = p->rlink;

	for (i = 0; i<n - k; i++)
	{
		//��M���� 
		for (j = 0; j<m; j++)
			p = p->rlink;
		//������ 
		cout << "��" << i + 1 << "�����ߵ�λ���ǣ�" << p->num << endl;
		
		//���ɾ������ͷָ�룬��ͷָ��������һλ 
		if (head->num == p->num)
			head = head->rlink;
		//ɾ����ǰ��Pָ�� 
		p->llink->rlink = p->rlink;
		p->rlink->llink = p->llink;
		temp = p;
		p = p->llink;
		delete temp;

	}

	cout << endl << "���ʣ�£�" << k << "��" << endl;
	cout << "ʣ�������λ��Ϊ��";
	
	//���ʣ������ 
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










