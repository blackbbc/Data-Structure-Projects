#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

const int n = 10;//���� 
const int m = 10;//���� 

//�� 
struct point
{
	int x;
	int y;
};


//��ͼ 
char map[50][50] = { "##########",
"#0#0000###",
"#0#0##000#",
"#000#00#0#",
"#0#0000#0#",
"#0#0#00#0#",
"#0#0#00#0#",
"#0#0#00#0#",
"#0#0#00#0#",
"##########" };


point dir[4] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };//�ĸ�����

point start, goal;//�����յ� 


//������Ļ�������ɫ�� 
HANDLE hout;
CONSOLE_SCREEN_BUFFER_INFO binfo;

//�����ͼ 
void printmap(string title);


//������ͼ������True(�ɹ�������False��ʧ�ܣ� 
bool dfs(int, int);

//����� 
void printAns();



int main()
{

	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hout, &binfo);

	printmap("�Թ���ͼ��");



	if (dfs(start.x, start.y))
		printAns();
	else
	{
		SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "No Answer!";
		SetConsoleTextAttribute(hout, binfo.wAttributes);
	}

	cout << endl;
	system("pause");

	CloseHandle(hout);

	return 0;
}

void printmap(string title)
{

	start.x = 1; start.y = 1;
	goal.x = 8; goal.y = 8;

	cout << title << endl;

	cout << "       ";
	for (int i = 0; i<m; i++)
		cout << i << "��" << "    ";
	cout << endl;

	for (int i = 0; i<n; i++)
	{
		cout << i << "��" << "    ";
		for (int j = 0; j<m; j++)
		{
			if (map[i][j] == 'x')
				SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << map[i][j] << "      ";
			SetConsoleTextAttribute(hout, binfo.wAttributes);
		}
		cout << endl << endl;
	}

}


bool dfs(int x, int y)
{

	//����ҵ����յ㣬�ͷ���True 
	if ((x == goal.x) && (y == goal.y))
	{
		map[x][y] = 'x';
		return true;
	}

	for (int i = 0; i<4; i++)
	if (map[x + dir[i].x][y + dir[i].y] == '0')//�����һ��λ�ÿ��Է� 
	{

		//�ڵ�ǰλ��������� 
		map[x][y] = 'x';

		//����ݹ����� 
		if (dfs(x + dir[i].x, y + dir[i].y))
			return true;

		//���ر�� 
		map[x][y] = '0';

	}


	return false;

}

void printAns()
{
	int x = start.x;
	int y = start.y;


	printmap("�Թ�·����");

	cout << "<" << x << "," << y << ">";

	while ((x != goal.x) || (y != goal.y))
	{
		for (int i = 0; i<4; i++)
		if (map[x + dir[i].x][y + dir[i].y] == 'x')
		{
			map[x][y] = '0';
			x += dir[i].x;
			y += dir[i].y;
			break;
		}

		cout << " ---> " << "<" << x << "," << y << ">";
	}
}
