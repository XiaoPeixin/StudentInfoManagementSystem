/*****************************************************
*文件名：GameLib.c
*描述：用来定义常用的系统操作
*日期：2017年5月24日
*创建人:Creams
******************************************************/
#include "GameLib.h"
void SetTitle(char * title)
{
	SetConsoleTitle(title);
}
void SetColor(int foreColor,int backColor)
{
	HANDLE winHandle;	//句柄
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置文字颜色
	SetConsoleTextAttribute(winHandle,foreColor + backColor * 0x10);
}
void SetPosition(int x,int y)
{
	HANDLE winHandle;	//句柄
	COORD pos = {x, y} ;
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置光标的坐标
	SetConsoleCursorPosition(winHandle,pos);
}
void Clear(int x,int y,int rowCount)
{
	//每行清除78字符 打印空格
	int i,j;
	for(i = 0;i < rowCount;i++)
	{
		SetPosition(x,y + i);
		for(j = 0;j < 76;j++)
		{
			printf(" ");
		}
	}
}
