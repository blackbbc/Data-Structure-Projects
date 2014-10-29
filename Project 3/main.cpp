#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

const int n = 10;//行数 
const int m = 10;//列数 

//点 
struct point
{
	int x;
	int y;
};


//地图 
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


point dir[4] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };//四个方向

point start, goal;//起点和终点 


//控制屏幕输出（颜色） 
HANDLE hout;
CONSOLE_SCREEN_BUFFER_INFO binfo;

//输出地图 
void printmap(string title);


//搜索地图，返回True(成功）或者False（失败） 
bool dfs(int, int);

//输出答案 
void printAns();



int main()
{

	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hout, &binfo);

	printmap("迷宫地图：");



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
		cout << i << "列" << "    ";
	cout << endl;

	for (int i = 0; i<n; i++)
	{
		cout << i << "行" << "    ";
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

	//如果找到了终点，就返回True 
	if ((x == goal.x) && (y == goal.y))
	{
		map[x][y] = 'x';
		return true;
	}

	for (int i = 0; i<4; i++)
	if (map[x + dir[i].x][y + dir[i].y] == '0')//如果下一个位置可以放 
	{

		//在当前位置做个标记 
		map[x][y] = 'x';

		//进入递归搜索 
		if (dfs(x + dir[i].x, y + dir[i].y))
			return true;

		//撤回标记 
		map[x][y] = '0';

	}


	return false;

}

void printAns()
{
	int x = start.x;
	int y = start.y;


	printmap("迷宫路径：");

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
