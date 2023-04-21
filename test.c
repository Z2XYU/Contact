#include "contact.h"

void menu();
int main()

{
    int input = 0;
    // 创建通讯录
    struct Contact con;
    // 初始化通讯录
    InitContact(&con);
    do
    {
        menu();
        printf("请选择选项。\n");
        scanf("%d", &input);
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
            // 释放动态开辟内存
            Save_and_Free(&con);
            printf("退出通讯录。\n");
            Sleep(1000);
            exit(0);
        default:
            printf("请输入正确的选项。\n");
            break;
        }
    } while (input);
    return 0;
}
