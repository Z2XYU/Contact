#include"contact.h"
#include<stdio.h>
#include<stdlib.h>
void menu();
int main()

{
    int input=0;
    //创建通讯录
    struct Contact con;
    //初始化通讯录
    InitContact(&con);
    do
    {
        menu();
        printf("请选择选项。\n");
        scanf("%d",&input);
        switch (input)
        {
        case ADD:
            AddContact(&con);
            break;
        case DEL:
            DelContact(&con);
            break;
            
        case SEARCH:
            SeaechContact(&con);
            break;
        case MODIFY:
            ModifyContact(&con);
            break;
        case SHOW:
            ShowContact(&con);
            break;
        case SORT:
            SortContact(&con);
            break;
        case EXIT:
            //释放动态开辟内存
            Free(&con);
            printf("退出通讯录。\n");
            break;
        default:
        printf("请输入正确的选项。\n");
            break;
        }
    }while(input);
    return 0;
}
//打印菜单
void menu()
{
    system("cls");
    printf("*****************************************\n");
    printf("****1.添加联系人         2.删除联系人*****\n");
    printf("****3.查找联系人         4.修改联系人*****\n");
    printf("****5.显示联系人         6.排序**********\n");
    printf("****0.退出                 *************\n");
    printf("****************************************\n");
}
