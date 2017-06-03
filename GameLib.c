/*****************************************************
*�ļ�����GameLib.c
*�������������峣�õ�ϵͳ����
*���ڣ�2017��5��24��
*������:Creams
******************************************************/
#include "GameLib.h"
void SetTitle(char * title)
{
	SetConsoleTitle(title);
}
void SetColor(int foreColor,int backColor)
{
	HANDLE winHandle;	//���
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//����������ɫ
	SetConsoleTextAttribute(winHandle,foreColor + backColor * 0x10);
}
void SetPosition(int x,int y)
{
	HANDLE winHandle;	//���
	COORD pos = {x, y} ;
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ù�������
	SetConsoleCursorPosition(winHandle,pos);
}
void Clear(int x,int y,int rowCount)
{
	//ÿ�����78�ַ� ��ӡ�ո�
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
