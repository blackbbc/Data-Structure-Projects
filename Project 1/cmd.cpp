#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
	char title[255];
	
	HANDLE hout;
	CONSOLE_SCREEN_BUFFER_INFO binfo;
	
//	COORD pos={0,0};
	COORD size={100,400};
	
	hout=GetStdHandle(STD_OUTPUT_HANDLE);
	
	
	GetConsoleScreenBufferInfo(hout,&binfo);
	
	SetConsoleTitle("考试管理系统");
	
	GetConsoleTitle(title,255);
	
	SetConsoleScreenBufferSize(hout,size);
	
//	_getch();
	
//	FillConsoleOutputCharacter(hout,' ', binfo.dwSize.X * binfo.dwSize.Y, pos, NULL);
	
	
	SetConsoleTextAttribute(hout,FOREGROUND_RED|FOREGROUND_INTENSITY);
	
	cout<<"Hello World!"<<endl;
	cout<<binfo.dwSize.X<<' '<<binfo.dwSize.Y<<endl;
	cout<<title<<endl;
	
	
	SetConsoleTextAttribute(hout,binfo.wAttributes);
	cout<<"I'm back"<<endl;
	CloseHandle(hout);
	

	
	
	return 0;
}
