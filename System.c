/***************************************************
 * 文件名：System.c
 * 描述：欢迎页、信息页、用户界面和其他咋想的函数
 * 作者：Creams
 * 时间：2017年5月30日
 * 版权：Creams
 ****************************************************/

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
    SetTitle("大连海事大学学生信息管理系统");
    SetPosition(MARGIN_X, 0);
    printf("%s", HEAD);
    SetPosition(MARGIN_X, 1);
    printf("|");
    SetPosition(MARGIN_X + 21, 1);
    printf("欢迎使用大连海事大学学生信息管理系统");
    SetPosition(MARGIN_X + 77, 1);
    printf("|");
    SetPosition(MARGIN_X, 2);
    printf("%s", HEAD);
}
//显示信息区域
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
    printf("用户身份验证");
    SetPosition(MARGIN_X + 30, INFO_START_Y + 6);
    printf("账号:");
    SetPosition(MARGIN_X + 30, INFO_START_Y + 7);
    printf("密码:");
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
        printf("验证成功 正在进入系统");
        SetPosition(MARGIN_X + 33, INFO_START_Y + 7);
        printf("请稍后");
        Sleep(3000);
        Clear(MARGIN_X + 1, INFO_START_Y + 1, 16);
        ShowUser();
    }
    else
    {
        SetPosition(MARGIN_X + 32, INFO_START_Y + 12);
        printf("验证失败!");
        Sleep(1000);
        system("cls");//清屏
        exit(0);
    }

}
//显示用户区域
void ShowUser()
{
    SetPosition(MARGIN_X, INFO_START_Y + 20 + 0);
    printf("1、管理学生信息");
    SetPosition(MARGIN_X, INFO_START_Y + 20 + 1);
    printf("2、打印学生信息");
    SetPosition(MARGIN_X, INFO_START_Y + 20 + 2);
    printf("3、学生成绩排名");
    SetPosition(MARGIN_X, INFO_START_Y + 20 + 3);
    printf("4、播放音乐");
    SetPosition(MARGIN_X, INFO_START_Y + 20 + 4);
    printf("5、退出程序");
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
            Choice2();
            ShowUser();
            break;
        case '3':
            Clear(MARGIN_X, INFO_END_Y + 4, 5);
            Choice3();
            ShowUser();
            break;
        case '4':
            Clear(MARGIN_X, INFO_END_Y + 4, 5);
            Choice4();
            ShowUser();
            break;
        case '5':
            system("cls");//清屏
            exit(0);
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
    printf("1、录入学生成绩");
    SetPosition(MARGIN_X + 28, INFO_START_Y + 7);
    printf("2、删除学生成绩");
    SetPosition(MARGIN_X + 28, INFO_START_Y + 8);
    printf("3、返回到主菜单");
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
            printf("请输入学生的相关信息");
            SetPosition(MARGIN_X + 25, INFO_START_Y + 5);
            printf("学号:");
            SetPosition(MARGIN_X + 25, INFO_START_Y + 6);
            printf("姓名:");
            SetPosition(MARGIN_X + 25, INFO_START_Y + 7);
            printf("性别:");
            SetPosition(MARGIN_X + 25, INFO_START_Y + 8);
            printf("专业:");
            SetPosition(MARGIN_X + 25, INFO_START_Y + 9);
            printf("班级:");
            SetPosition(MARGIN_X + 21, INFO_START_Y + 10);
            printf("数学成绩:");
            SetPosition(MARGIN_X + 21, INFO_START_Y + 11);
            printf("英语成绩:");
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
            printf("保存成功 是否继续录入(按Y继续录入 其他键退出...)");
//            for(i = 0; i < 100; i++)
//            {
//                rewind(fl);
//                InputStd.English++;
//                fwrite(&InputStd, sizeof(STD), 1, fl);
//            }
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
        printf("删除");
        SetPosition(MARGIN_X + 22, INFO_START_Y + 5);
        printf("请输入要删除学生的学号:");
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
            printf("已找到该学生 信息如下");
            SetPosition(MARGIN_X + 15, INFO_START_Y + 2);
            printf("学号 姓名 性别    专业    班级 数学成绩 英语成绩");
            SetPosition(MARGIN_X + 15, INFO_START_Y + 3);
            printf("%s %s %s   %s    %d     %d      %d", tempdata[i].num, tempdata[i].name, tempdata[i].sex, tempdata[i].major, tempdata[i].classNo, tempdata[i].math, tempdata[i].English);
            SetPosition(MARGIN_X + 25, INFO_START_Y + 8);
            printf("按Y删除 其他键回主菜单");
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
            printf("未找到该学生 按任意键回主菜单");
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
        printf("删除");
        SetPosition(MARGIN_X + 25, INFO_START_Y + 5);
        printf("删除成功 按任意键回主菜单");
        getch();
        Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
        break;
    case '3':
        Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
        break;
    }
}
void Choice2()
{

}
void Choice3()
{
    FILE * fl;
    int count = 0, i,j,page,pagenow,rank = 1,upanddown = 1;
    float *sum,ave[3] = {0,0,0};
    STD OutputStd, * tempdata,temp;
    char rankchoice,act,choice;
    Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
    form1(24, 8, 24, 3);
    SetPosition(MARGIN_X + 28, INFO_START_Y + 6);
    printf("1、总成绩排名");
    SetPosition(MARGIN_X + 28, INFO_START_Y + 7);
    printf("2、单科成绩排名");
    SetPosition(MARGIN_X + 28, INFO_START_Y + 8);
    printf("3、返回到主菜单");
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
        sum = (float *)malloc(count * sizeof(float));
        for(i = 0; i < count; i++)
        {
            sum[i] += tempdata[i].math + tempdata[i].English;
            ave[0] += tempdata[i].math + tempdata[i].English;
            ave[1] += tempdata[i].math;
            ave[2] += tempdata[i].English;
        }
        for(i = 0; i < count; i++)
        {
            for(j = 0; j < count - i - 1; j++)
            {
                if(tempdata[j].English + tempdata[j].math < tempdata[j + 1].English + tempdata[j + 1].math )
                {
                    temp = tempdata[j];
                    tempdata[j] = tempdata[j + 1];
                    tempdata[j + 1] = temp;
                }
            }
        }
        //共 %d 位同学
        page = count / 18 + 1;
        pagenow = 1;
        SetPosition(MARGIN_X + 4,INFO_START_Y + 21);
        printf("共 %d 名同学 总分平均分:%.2lf 数学平均分:%.2lf 英语平均分:%.2lf",count,ave[0] / count,ave[1] / count,ave[2] / count);
        SetPosition(MARGIN_X +15,INFO_START_Y + 20);
        printf("第 %d 页 共 %d 页(左右键翻页 上下键升降序 按0退出)",pagenow,page);
        SetPosition(MARGIN_X + 1,INFO_START_Y );
        printf("排名 学号    姓名     性别    专业     班级   数学成绩    英语成绩    总分");

        while(1)
        {
            if(pagenow == page)
            {
                for(i = (pagenow - 1) * 18,j = 0,rank = (pagenow - 1) * 18 + 1 ; i < count; i++,rank++,j++)
                {
                    SetPosition(MARGIN_X + 1,INFO_START_Y + 1 + j);
                    if(upanddown == 1)
                        printf(" %-5d%-5s %-10s %-s    %--12s%-7d%-13d%-9d%d",rank,tempdata[i].num,tempdata[i].name,tempdata[i].sex,tempdata[i].major,tempdata[i].classNo,tempdata[i].math,tempdata[i].English,(tempdata[i].math) + (tempdata[i].English));
                    else
                        printf(" %-5d%-5s %-10s %-s    %--12s%-7d%-13d%-9d%d",count - rank + 1,tempdata[i].num,tempdata[i].name,tempdata[i].sex,tempdata[i].major,tempdata[i].classNo,tempdata[i].math,tempdata[i].English,(tempdata[i].math) + (tempdata[i].English));
                }
            }
            else
            {
                for(i = (pagenow - 1) * 18,j = 0,rank = (pagenow - 1) * 18 + 1; i <  pagenow  * 18 ; i++,rank++,j++)
                {
                    SetPosition(MARGIN_X + 1,INFO_START_Y + 1 + j);
                    if(upanddown == 1)
                        printf(" %-5d%-5s %-10s %-s    %--12s%-7d%-13d%-9d%d",rank,tempdata[i].num,tempdata[i].name,tempdata[i].sex,tempdata[i].major,tempdata[i].classNo,tempdata[i].math,tempdata[i].English,(tempdata[i].math) + (tempdata[i].English));
                    else
                        printf(" %-5d%-5s %-10s %-s    %--12s%-7d%-13d%-9d%d",count - rank + 1,tempdata[i].num,tempdata[i].name,tempdata[i].sex,tempdata[i].major,tempdata[i].classNo,tempdata[i].math,tempdata[i].English,(tempdata[i].math) + (tempdata[i].English));
                }
            }
            act = getch();
            switch(act)
            {
            case 72:
                pagenow = 1;
                upanddown = -1;
                SetPosition(MARGIN_X +15,INFO_START_Y + 20);
                printf("第 %d 页 共 %d 页(左右键翻页 上下键升降序 按0退出)",pagenow,page);
                for(i = 0; i < count; i++)
                {
                    for(j = 0; j < count - i - 1; j++)
                    {
                        if(tempdata[j].English + tempdata[j].math > tempdata[j + 1].English + tempdata[j + 1].math )
                        {
                            temp = tempdata[j];
                            tempdata[j] = tempdata[j + 1];
                            tempdata[j + 1] = temp;
                        }
                    }
                }

                break;
            case 80:
                pagenow = 1;
                upanddown = 1;
                SetPosition(MARGIN_X +15,INFO_START_Y + 20);
                printf("第 %d 页 共 %d 页(左右键翻页 上下键升降序 按0退出)",pagenow,page);
                for(i = 0; i < count; i++)
                {
                    for(j = 0; j < count - i - 1; j++)
                    {
                        if(tempdata[j].English + tempdata[j].math < tempdata[j + 1].English + tempdata[j + 1].math )
                        {
                            temp = tempdata[j];
                            tempdata[j] = tempdata[j + 1];
                            tempdata[j + 1] = temp;
                        }
                    }
                }
                break;
            case 75:
                Clear(MARGIN_X + 1,INFO_START_Y + 20,1);
                if(pagenow > 1)
                    pagenow--;
                SetPosition(MARGIN_X +15,INFO_START_Y + 20);
                printf("第 %d 页 共 %d 页(左右键翻页 上下键升降序 按0退出)",pagenow,page);
                Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
                break;
            case 77:
                Clear(MARGIN_X + 1,INFO_START_Y + 20,1);
                if(pagenow < page)
                    pagenow++;
                SetPosition(MARGIN_X +15,INFO_START_Y + 20);
                printf("第 %d 页 共 %d 页(左右键翻页 上下键升降序 按0退出)",pagenow,page);
                Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
                break;
            case '0':
                Clear(MARGIN_X + 1,INFO_START_Y + 20,2);
                Clear(MARGIN_X + 1,INFO_START_Y + 20,1);
                break;
            }
            if(act == '0')
                break;
        }
        Clear(MARGIN_X + 1, INFO_START_Y, 19);
        break;
    case'2':
        Clear(MARGIN_X + 1, INFO_START_Y, 18);
        form1(24, 8, 24, 3);
        SetPosition(MARGIN_X + 28, INFO_START_Y + 6);
        printf("1、英语成绩排名");
        SetPosition(MARGIN_X + 28, INFO_START_Y + 7);
        printf("2、数学成绩排名");
        SetPosition(MARGIN_X + 28, INFO_START_Y + 8);
        printf("3、返回到主菜单");
        while(1)
        {
            choice = getch();
            if(choice == '1' || choice == '2' || choice == '3')
                break;
        }
        switch(choice)
        {
        case '1':
            Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
            for(i = 0; i < count; i++)
            {
                ave[2] += tempdata[i].English;
            }
            for(i = 0; i < count; i++)
            {
                for(j = 0; j < count - i - 1; j++)
                {
                    if(tempdata[j].English < tempdata[j + 1].English)
                    {
                        temp = tempdata[j];
                        tempdata[j] = tempdata[j + 1];
                        tempdata[j + 1] = temp;
                    }
                }
            }
            upanddown = 1;
            page = count / 18 + 1;
            pagenow = 1;
            SetPosition(MARGIN_X + 24,INFO_START_Y + 21);
            printf("共 %d 名同学 英语平均分:%.2lf",count,ave[2] / count);
            SetPosition(MARGIN_X +15,INFO_START_Y + 20);
            printf("第 %d 页 共 %d 页(左右键翻页 上下键升降序 按0退出)",pagenow,page);
            SetPosition(MARGIN_X + 10,INFO_START_Y );
            printf("序号 学号    姓名     性别    专业     班级   英语成绩    ");

            while(1)
            {
                if(pagenow == page)
                {
                    for(i = (pagenow - 1) * 18,j = 0,rank = (pagenow - 1) * 18 + 1 ; i < count; i++,rank++,j++)
                    {
                        SetPosition(MARGIN_X + 10,INFO_START_Y + 1 + j);
                        if(upanddown == 1)
                            printf(" %-5d%-5s %-10s %-s    %--12s%-7d%-9d",rank,tempdata[i].num,tempdata[i].name,tempdata[i].sex,tempdata[i].major,tempdata[i].classNo,tempdata[i].English);
                        else
                            printf(" %-5d%-5s %-10s %-s    %--12s%-7d%-9d",count - rank + 1,tempdata[i].num,tempdata[i].name,tempdata[i].sex,tempdata[i].major,tempdata[i].classNo,tempdata[i].English);
                    }
                }
                else
                {
                    for(i = (pagenow - 1) * 18,j = 0,rank = (pagenow - 1) * 18 + 1; i <  pagenow  * 18 ; i++,rank++,j++)
                    {
                        SetPosition(MARGIN_X + 10,INFO_START_Y + 1 + j);
                        if(upanddown == 1)
                            printf(" %-5d%-5s %-10s %-s    %--12s%-7d%-9d",rank,tempdata[i].num,tempdata[i].name,tempdata[i].sex,tempdata[i].major,tempdata[i].classNo,tempdata[i].English);
                        else
                            printf(" %-5d%-5s %-10s %-s    %--12s%-7d%-9d",count - rank + 1,tempdata[i].num,tempdata[i].name,tempdata[i].sex,tempdata[i].major,tempdata[i].classNo,tempdata[i].English);
                    }
                }
                act = getch();
                switch(act)
                {
                case 72:
                    pagenow = 1;
                    upanddown = -1;
                    SetPosition(MARGIN_X +15,INFO_START_Y + 20);
                    printf("第 %d 页 共 %d 页(左右键翻页 上下键升降序 按0退出)",pagenow,page);
                    for(i = 0; i < count; i++)
                    {
                        for(j = 0; j < count - i - 1; j++)
                        {
                            if(tempdata[j].English > tempdata[j + 1].English)
                            {
                                temp = tempdata[j];
                                tempdata[j] = tempdata[j + 1];
                                tempdata[j + 1] = temp;
                            }
                        }
                    }

                    break;
                case 80:
                    pagenow = 1;
                    upanddown = 1;
                    SetPosition(MARGIN_X +15,INFO_START_Y + 20);
                    printf("第 %d 页 共 %d 页(左右键翻页 上下键升降序 按0退出)",pagenow,page);
                    for(i = 0; i < count; i++)
                    {
                        for(j = 0; j < count - i - 1; j++)
                        {
                            if(tempdata[j].English< tempdata[j + 1].English)
                            {
                                temp = tempdata[j];
                                tempdata[j] = tempdata[j + 1];
                                tempdata[j + 1] = temp;
                            }
                        }
                    }
                    break;
                case 75:
                    Clear(MARGIN_X + 1,INFO_START_Y + 20,1);
                    if(pagenow > 1)
                        pagenow--;
                    SetPosition(MARGIN_X +15,INFO_START_Y + 20);
                    printf("第 %d 页 共 %d 页(左右键翻页 上下键升降序 按0退出)",pagenow,page);
                    Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
                    break;
                case 77:
                    Clear(MARGIN_X + 1,INFO_START_Y + 20,1);
                    if(pagenow < page)
                        pagenow++;
                    SetPosition(MARGIN_X +15,INFO_START_Y + 20);
                    printf("第 %d 页 共 %d 页(左右键翻页 上下键升降序 按0退出)",pagenow,page);
                    Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
                    break;
                case '0':
                    Clear(MARGIN_X + 1,INFO_START_Y + 20,2);
                    Clear(MARGIN_X + 1,INFO_START_Y + 20,1);
                    break;
                }
                if(act == '0')
                    break;
            }

            break;
        case '2':
            upanddown = 1;
            Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
            for(i = 0; i < count; i++)
            {
                ave[1] += tempdata[i].math;
            }
            for(i = 0; i < count; i++)
            {
                for(j = 0; j < count - i - 1; j++)
                {
                    if(tempdata[j].math < tempdata[j + 1].math)
                    {
                        temp = tempdata[j];
                        tempdata[j] = tempdata[j + 1];
                        tempdata[j + 1] = temp;
                    }
                }
            }
            page = count / 18 + 1;
            pagenow = 1;
            SetPosition(MARGIN_X + 24,INFO_START_Y + 21);
            printf("共 %d 名同学 数学平均分:%.2lf",count,ave[1] / count);
            SetPosition(MARGIN_X +15,INFO_START_Y + 20);
            printf("第 %d 页 共 %d 页(左右键翻页 上下键升降序 按0退出)",pagenow,page);
            SetPosition(MARGIN_X + 10,INFO_START_Y );
            printf("排名 学号    姓名     性别    专业     班级   数学成绩    ");

            while(1)
            {
                if(pagenow == page)
                {
                    for(i = (pagenow - 1) * 18,j = 0,rank = (pagenow - 1) * 18 + 1 ; i < count; i++,rank++,j++)
                    {
                        SetPosition(MARGIN_X + 10,INFO_START_Y + 1 + j);
                        if(upanddown == 1)
                            printf(" %-5d%-5s %-10s %-s    %--12s%-7d%-9d",rank,tempdata[i].num,tempdata[i].name,tempdata[i].sex,tempdata[i].major,tempdata[i].classNo,tempdata[i].math);
                        else
                            printf(" %-5d%-5s %-10s %-s    %--12s%-7d%-9d",count - rank + 1,tempdata[i].num,tempdata[i].name,tempdata[i].sex,tempdata[i].major,tempdata[i].classNo,tempdata[i].math);
                    }
                }
                else
                {
                    for(i = (pagenow - 1) * 18,j = 0,rank = (pagenow - 1) * 18 + 1; i <  pagenow  * 18 ; i++,rank++,j++)
                    {
                        SetPosition(MARGIN_X + 10,INFO_START_Y + 1 + j);
                        if(upanddown == 1)
                            printf(" %-5d%-5s %-10s %-s    %--12s%-7d%-9d",rank,tempdata[i].num,tempdata[i].name,tempdata[i].sex,tempdata[i].major,tempdata[i].classNo,tempdata[i].math);
                        else
                            printf(" %-5d%-5s %-10s %-s    %--12s%-7d%-9d",count - rank + 1,tempdata[i].num,tempdata[i].name,tempdata[i].sex,tempdata[i].major,tempdata[i].classNo,tempdata[i].math);

                    }
                }
                act = getch();
                switch(act)
                {
                case 72:
                    pagenow = 1;
                    upanddown = -1;
                    SetPosition(MARGIN_X +15,INFO_START_Y + 20);
                    printf("第 %d 页 共 %d 页(左右键翻页 上下键升降序 按0退出)",pagenow,page);
                    for(i = 0; i < count; i++)
                    {
                        for(j = 0; j < count - i - 1; j++)
                        {
                            if(tempdata[j].math > tempdata[j + 1].math)
                            {
                                temp = tempdata[j];
                                tempdata[j] = tempdata[j + 1];
                                tempdata[j + 1] = temp;
                            }
                        }
                    }

                    break;
                case 80:
                    pagenow = 1;
                    upanddown = 1;
                    SetPosition(MARGIN_X +15,INFO_START_Y + 20);
                    printf("第 %d 页 共 %d 页(左右键翻页 上下键升降序 按0退出)",pagenow,page);
                    for(i = 0; i < count; i++)
                    {
                        for(j = 0; j < count - i - 1; j++)
                        {
                            if(tempdata[j].math< tempdata[j + 1].math)
                            {
                                temp = tempdata[j];
                                tempdata[j] = tempdata[j + 1];
                                tempdata[j + 1] = temp;
                            }
                        }
                    }
                    break;
                case 75:
                    Clear(MARGIN_X + 1,INFO_START_Y + 20,1);
                    if(pagenow > 1)
                        pagenow--;
                    SetPosition(MARGIN_X +15,INFO_START_Y + 20);
                    printf("第 %d 页 共 %d 页(左右键翻页 上下键升降序 按0退出)",pagenow,page);
                    Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
                    break;
                case 77:
                    Clear(MARGIN_X + 1,INFO_START_Y + 20,1);
                    if(pagenow < page)
                        pagenow++;
                    SetPosition(MARGIN_X +15,INFO_START_Y + 20);
                    printf("第 %d 页 共 %d 页(左右键翻页 上下键升降序 按0退出)",pagenow,page);
                    Clear(MARGIN_X + 1, INFO_START_Y + 1, 18);
                    break;
                case '0':
                    Clear(MARGIN_X + 1,INFO_START_Y + 20,2);
                    Clear(MARGIN_X + 1,INFO_START_Y + 20,1);
                    break;
                }
                if(act == '0')
                    break;
            }
            break;
        case '3':
            break;
        }
        Clear(MARGIN_X + 1, INFO_START_Y, 19);
        break;
    case'3':
        free(tempdata);
        free(sum);
        Clear(MARGIN_X + 1, INFO_START_Y, 19);
        break;
    }

}
void form1(int m, int n, int x, int y)//在信息框的X Y中 打印n行m列的小框框
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

void Choice4()
{
    PlaySound(TEXT("sounds\\大连海事大学校歌.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    char press;
    SetPosition(MARGIN_X + 24,INFO_START_Y );
    printf("渤海畔，黄海滨 集合着大海的灵魂");
    SetPosition(MARGIN_X + 27,INFO_START_Y + 1 );
    printf("扬气慨，抖精神浩海纵鹏鲲");
    SetPosition(MARGIN_X + 30,INFO_START_Y + 2 );
    printf("啊，海大  啊，大海");
    SetPosition(MARGIN_X + 29,INFO_START_Y + 3 );
    printf("抒手放飞理想畅怀奔腾");
    SetPosition(MARGIN_X + 29,INFO_START_Y + 4 );
    printf("奔腾，奔腾，奔腾青春");
    SetPosition(MARGIN_X + 24,INFO_START_Y + 8);
    printf("知路远，守本根 肩负着中华的责任");
    SetPosition(MARGIN_X + 27,INFO_START_Y + 9 );
    printf("扬气慨，抖精神青史见功勋");
    SetPosition(MARGIN_X + 30,INFO_START_Y + 10 );
    printf("啊，海大  啊，大海");
    SetPosition(MARGIN_X + 29,INFO_START_Y + 11 );
    printf("曙光托起希望放眼世界");
    SetPosition(MARGIN_X + 29,INFO_START_Y + 12 );
    printf("世界，世界，世界风云");
    SetPosition(MARGIN_X + 33,INFO_START_Y + 13 );
    printf("放眼世界风云");
    SetPosition(MARGIN_X +68,INFO_START_Y + 18 );
    printf("(按0退出)");
    SetPosition(MARGIN_X +100,INFO_START_Y + 100 );
    while(1)
    {
        press = getch();
        if(press == '0')
        {
            PlaySound(NULL, NULL, NULL);  //音乐停止
            Clear(MARGIN_X + 1, INFO_START_Y, 19);
            break;
        }

    }
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); //查找换行符
        if(find)                //如果地址不是 NULL
            *find = '\0';       //才此处放置一个空字符
        else
            while(getchar() != '\n')
                continue;       //处理剩余数入行
    }
    return ret_val;
}
