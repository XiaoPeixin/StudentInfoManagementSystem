/**
 * �ļ�����System.c
 * ��������ӭҳ����Ϣҳ���û����������զ��ĺ���
 * ���ߣ�Creams
 * ʱ�䣺2017��5��30��
 * ��Ȩ��Creams
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include "System.h"
#define MARGIN_X 28
#define HEAD "------------------------------------------------------------------------------"
#define INFO_START_Y 3
#define INFO_END_Y 19
#define ACCOUNT "1"
#define PASSWARD "1"

typedef struct _student
{
    char num[20];
    char name[30];
    char sex[5];
    char major[20];
    int classNo;
    int math;
    int English;
} STD;
void ShowWelcome()
{
    SetColor(10, 0);
    SetTitle("�������´�ѧѧ����Ϣ����ϵͳ");
    SetPosition(MARGIN_X, 0);
    printf("%s", HEAD);
    SetPosition(MARGIN_X, 1);
    printf("|");
    SetPosition(MARGIN_X + 21, 1);
    printf("��ӭʹ�ô������´�ѧѧ����Ϣ����ϵͳ");
    SetPosition(MARGIN_X + 77, 1);
    printf("|");
    SetPosition(MARGIN_X, 2);
    printf("%s", HEAD);
}
//��ʾ��Ϣ����
void ShowInfo()
{
    SetPosition(MARGIN_X, INFO_END_Y);
    int i, j;
    char account[30];
    char passward [30];
    char passsimple;
    for(i = 0; i < 19; i++)
    {
        SetPosition(MARGIN_X, INFO_START_Y + i);
        printf("|");
        SetPosition(MARGIN_X + 77, INFO_START_Y + i);
        printf("|");
    }
    SetPosition(MARGIN_X, INFO_START_Y + i);
    printf("%s", HEAD);
    Clear(MARGIN_X+1, INFO_START_Y, 19);
    form1(24, 6, 24, 3);
    SetPosition(MARGIN_X + 31, INFO_START_Y + 4);
    printf("�û������֤");
    SetPosition(MARGIN_X + 30, INFO_START_Y + 6);
    printf("�˺�:");
    SetPosition(MARGIN_X + 30, INFO_START_Y + 7);
    printf("����:");
    SetPosition(MARGIN_X + 35, INFO_START_Y + 6);
    fflush(stdin);
    s_gets(account, 30);
    SetPosition(MARGIN_X + 35, INFO_START_Y + 7);
    i = 0;
    while(1)
    {

        fflush(stdin);
        passsimple = getch();

        if(passsimple == 13)
        {
            passward[i] = '\0';
            putchar('\n');
            break;
        }
        else  if(passsimple == 8 )
        {
            if(i == 0)
                continue;

            putchar('\b');
            printf("  ");
            putchar('\b');
            putchar('\b');
            passward[i - 1] = '\0';
            if(i >0)
                i--;
        }
        else
        {
            passward[i] = passsimple;
            i++;
            if(i <= 13)
                printf("*");

        }
    }
    fflush(stdin);
    if(strcmp(account, ACCOUNT) == 0 && strcmp(passward, PASSWARD) == 0)
    {
        Clear(MARGIN_X+1, INFO_START_Y, 19);
        form1(24, 6, 24, 3);
        SetPosition(MARGIN_X + 26, INFO_START_Y + 6);
        printf("��֤�ɹ� ���ڽ���ϵͳ");
        SetPosition(MARGIN_X + 33, INFO_START_Y + 7);
        printf("���Ժ�");
//        Sleep(3000);
        Clear(MARGIN_X + 1, INFO_START_Y + 1, 16);
        ShowUser();
    }
    else
    {
        SetPosition(MARGIN_X + 32, INFO_START_Y + 12);
        printf("��֤ʧ��!");
        Sleep(1000);
        system("cls");//����
        exit(0);
    }

}
//��ʾ�û�����
void ShowUser()
{
    SetPosition(MARGIN_X, INFO_START_Y + 20 + 0);
    printf("1������ѧ����Ϣ");
    SetPosition(MARGIN_X, INFO_START_Y + 20 + 1);
    printf("2����ӡѧ����Ϣ");
    SetPosition(MARGIN_X, INFO_START_Y + 20 + 2);
    printf("3��ѧ���ɼ�����");
    SetPosition(MARGIN_X, INFO_START_Y + 20 + 3);
    printf("4����������");
    SetPosition(MARGIN_X, INFO_START_Y + 20 + 4);
    printf("5���˳�����");
    UserChoice();
}

void UserChoice()
{
    char key;
    while(1)
    {
        SetPosition(MARGIN_X, INFO_START_Y + 20 + 5);
        key = getch();
        switch(key)
        {
        case '1':
            Clear(MARGIN_X, INFO_END_Y + 4, 5);
            Choice1();
            ShowUser();
            break;
        case '2':
            Clear(MARGIN_X, INFO_END_Y + 4, 5);
            ShowUser();
            break;
        case '3':
            Clear(MARGIN_X, INFO_END_Y + 4, 5);
            Choice3();
            ShowUser();
            break;
        case '4':
            printf("4");
            Clear(MARGIN_X, INFO_END_Y + 4, 5);
            ShowUser();
            break;
        case '5':
            printf("5");
            Clear(MARGIN_X, INFO_END_Y + 4, 5);
            ShowUser();
            break;
        }
    }
}
void Choice1()
{
    char choice, gochoice, delconfirm;
    FILE * fl;
    STD InputStd, OutputStd = {}, *tempdata;
    char Delnum[20];
    int count = 0;
    int i, confirm = 0;
    if((fl = fopen("studentInit.dat", "a + b")) == NULL)
    {
        fputs("Can't open file\n", stderr);
        exit(1);
    }
    Clear(MARGIN_X + 1, INFO_START_Y + 1, 16);
    form1(24, 8, 24, 3);
    SetPosition(MARGIN_X + 28, INFO_START_Y + 6);
    printf("1��¼��ѧ���ɼ�");
    SetPosition(MARGIN_X + 28, INFO_START_Y + 7);
    printf("2��ɾ��ѧ���ɼ�");
    SetPosition(MARGIN_X + 28, INFO_START_Y + 8);
    printf("3�����ص����˵�");
    do
    {
        choice = getch();
    }
    while(choice != '1' && choice != '2'&& choice != '3');
    switch(choice)
    {
    case '1':
        Clear(MARGIN_X + 1, INFO_START_Y + 1, 16);

        do
        {
            fl = fopen("studentInit.dat", "a + b");
            rewind(fl);
            Clear(MARGIN_X + 1, INFO_START_Y + 1, 16);
            form1(35, 10, 20, 2);
            SetPosition(MARGIN_X + 28, INFO_START_Y + 3);
            printf("������ѧ���������Ϣ");
            SetPosition(MARGIN_X + 25, INFO_START_Y + 5);
            printf("ѧ��:");
            SetPosition(MARGIN_X + 25, INFO_START_Y + 6);
            printf("����:");
            SetPosition(MARGIN_X + 25, INFO_START_Y + 7);
            printf("�Ա�:");
            SetPosition(MARGIN_X + 25, INFO_START_Y + 8);
            printf("רҵ:");
            SetPosition(MARGIN_X + 25, INFO_START_Y + 9);
            printf("�༶:");
            SetPosition(MARGIN_X + 21, INFO_START_Y + 10);
            printf("��ѧ�ɼ�:");
            SetPosition(MARGIN_X + 21, INFO_START_Y + 11);
            printf("Ӣ��ɼ�:");
            SetPosition(MARGIN_X + 31, INFO_START_Y + 5);
            fflush(stdin);
            s_gets(InputStd.num, 20);
            SetPosition(MARGIN_X + 31, INFO_START_Y + 6);
            fflush(stdin);
            s_gets(InputStd.name, 30);
            SetPosition(MARGIN_X + 31, INFO_START_Y + 7);
            fflush(stdin);
            s_gets(InputStd.sex, 5);
            SetPosition(MARGIN_X + 31, INFO_START_Y + 8);
            fflush(stdin);
            s_gets(InputStd.major, 20);
            SetPosition(MARGIN_X + 31, INFO_START_Y + 9);
            fflush(stdin);
            scanf("%d", &InputStd.classNo);
            SetPosition(MARGIN_X + 31, INFO_START_Y + 10);
            fflush(stdin);
            scanf("%d", &InputStd.math);
            SetPosition(MARGIN_X + 31, INFO_START_Y + 11);
            fflush(stdin);
            scanf("%d", &InputStd.English);
            SetPosition(MARGIN_X + 34, INFO_START_Y + 12);
            Sleep(500);
            fflush(stdin);
            fwrite(&InputStd, sizeof(STD), 1, fl);
            SetPosition(MARGIN_X + 21 + 8, INFO_START_Y + 12 + 6);
            printf("����ɹ� �Ƿ����¼��(��Y����¼�� �������˳�...)");
            fclose(fl);
            gochoice = getch();
            Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
        }
        while(gochoice == 'y'||gochoice == 'Y');
        fclose(fl);
        Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
        break;
    case'2':
        fl = fopen("studentInit.dat", "a + b");
        rewind(fl);
        while(1)
        {
            OutputStd.classNo = -1;
            fread(&OutputStd, sizeof(STD), 1, fl);
            if(OutputStd.classNo == -1)
                break;
            count++;
        }
        tempdata = (STD *)malloc(count * sizeof(STD));
        rewind(fl);
        for(i = 0; i < count; i++)
        {
            fread(&tempdata[i], sizeof(STD), 1, fl);
//		 printf("%s", tempdata[i].num);
//            getch();
        }
        fclose(fl);

        Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
        form1(35, 4, 20, 2);
        SetPosition(MARGIN_X + 36, INFO_START_Y + 3);
        printf("ɾ��");
        SetPosition(MARGIN_X + 22, INFO_START_Y + 5);
        printf("������Ҫɾ��ѧ����ѧ��:");
        fflush(stdin);
        s_gets(Delnum, 20);
        Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
        for(i = 0; i < count; i++)
        {
            if(strcmp(Delnum, tempdata[i].num) == 0)
            {
                confirm = 1;
                break;
            }
        }
        if(confirm == 1)
        {
            SetPosition(MARGIN_X + 26, INFO_START_Y + 1);
            printf("���ҵ���ѧ�� ��Ϣ����");
            SetPosition(MARGIN_X + 15, INFO_START_Y + 2);
            printf("ѧ�� ���� �Ա�    רҵ    �༶ ��ѧ�ɼ� Ӣ��ɼ�");
            SetPosition(MARGIN_X + 15, INFO_START_Y + 3);
            printf("%s %s %s   %s    %d     %d      %d", tempdata[i].num, tempdata[i].name, tempdata[i].sex, tempdata[i].major, tempdata[i].classNo, tempdata[i].math, tempdata[i].English);
            SetPosition(MARGIN_X + 25, INFO_START_Y + 8);
            printf("��Yɾ�� �����������˵�");
            delconfirm = getch() ;
            if(delconfirm != 'Y' && delconfirm != 'y')
            {
                Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
                break;
            }
        }
        else
        {
            SetPosition(MARGIN_X + 25, INFO_START_Y + 3);
            printf("δ�ҵ���ѧ�� ������������˵�");
            getch();
            Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
            break;
        }
        fl = fopen("studentInit.dat", "wb");
        fflush(stdin);
        rewind(fl);
        for(i = 0; i < count; i++)
        {
            if(strcmp(Delnum, tempdata[i].num) == 0)
                continue;
            fwrite(&tempdata[i], sizeof(STD), 1, fl);
        }
        Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
        fclose(fl);
        free(tempdata);
        Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
        form1(35, 4, 20, 2);
        SetPosition(MARGIN_X + 36, INFO_START_Y + 3);
        printf("ɾ��");
        SetPosition(MARGIN_X + 25, INFO_START_Y + 5);
        printf("ɾ���ɹ� ������������˵�");
        getch();
        Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
        break;
    case '3':
        Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
        break;
    }
}
void Choice3()
{
    FILE * fl;
    int count = 0, i,j,page, * sum;
    STD OutputStd, * tempdata,temp;
    char rankchoice;
    Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
    form1(24, 8, 24, 3);
    SetPosition(MARGIN_X + 28, INFO_START_Y + 6);
    printf("1���ܳɼ�����");
    SetPosition(MARGIN_X + 28, INFO_START_Y + 7);
    printf("2�����Ƴɼ�����");
    SetPosition(MARGIN_X + 28, INFO_START_Y + 8);
    printf("3�����ص����˵�");
    fl = fopen("studentInit.dat", "a + b");
    rewind(fl);
    while(1)
    {
        OutputStd.classNo = -1;
        fread(&OutputStd, sizeof(STD), 1, fl);
        if(OutputStd.classNo == -1)
            break;
        count++;
    }
    tempdata = (STD *)malloc(count * sizeof(STD));
    rewind(fl);
    for(i = 0; i < count; i++)
    {
        fread(&tempdata[i], sizeof(STD), 1, fl);
//		 printf("%s", tempdata[i].num);
//            getch();
    }
    do
    {
        rankchoice = getch();
    }
    while(rankchoice != '1' && rankchoice != '2'&& rankchoice != '3');
    switch(rankchoice)
    {
    case'1':
        Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
        for(i = 0; i < 19; i++)
        {
            SetPosition(MARGIN_X + 39, INFO_START_Y + i);
            printf("|");
        }
        sum = (int *)malloc(count * sizeof(int));
        for(i = 0; i < count; i++)
        {
            sum[i] += tempdata[i].math + tempdata[i].English;
        }
        for(i = 0;i < count;i++)
		{
			for(j = 0;j < count - i - 1;j++)
			{
				if(tempdata[j].English + tempdata[j].math < tempdata[j + 1].English + tempdata[j + 1].math )
				{
					temp = tempdata[j];
					tempdata[j] = tempdata[j + 1];
					tempdata[j + 1] = temp;
				}
			}
		}
        page = count / 34 + 1;
        SetPosition(MARGIN_X + 70,INFO_START_Y + 18);
        printf("�� %d ҳ",page);
        SetPosition(MARGIN_X + 1,INFO_START_Y );
        printf("ѧ��     ����    ��ѧ    Ӣ��    �ܷ�");
        SetPosition(MARGIN_X + 40,INFO_START_Y);
        printf("ѧ��     ����    ��ѧ    Ӣ��    �ܷ�");
        for(i = 0;i < 17;i++)
		{
			 SetPosition(MARGIN_X + 1,INFO_START_Y + 1 + i);
			 printf("%s   %s   %d   %d   %d",tempdata[i].num,tempdata[i].name,tempdata[i].math,tempdata[i].English,tempdata[i].math + tempdata[i].English);
		}

        break;
    case'2':
        break;
    case'3':
        Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
        break;
    }

}
void form1(int m, int n, int x, int y)//����Ϣ���X Y�� ��ӡn��m�е�С���
{
    int i;
    SetPosition(MARGIN_X + x, INFO_START_Y + y);
    for(i = 0; i < m + 1; i++)
        printf("-");
    SetPosition(MARGIN_X + x, INFO_START_Y + y + 1);
    for(i = 0; i < m + 1; i++)
        printf("-");
    for(i = 0; i <n - 1; i++)
    {
        SetPosition(MARGIN_X + x, INFO_START_Y + y + i + 1);
        printf("|");
        SetPosition(MARGIN_X + x + m, INFO_START_Y + y + i + 1);
        printf("|");
    }
    SetPosition(MARGIN_X + x, INFO_START_Y + y + n);
    for(i = 0; i < m + 1; i++)
        printf("-");
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); //���һ��з�
        if(find)                //�����ַ���� NULL
            *find = '\0';       //�Ŵ˴�����һ�����ַ�
        else
            while(getchar() != '\n')
                continue;       //����ʣ��������
    }
    return ret_val;
}
