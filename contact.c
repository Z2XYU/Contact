#include "contact.h"

// 打印菜单
void menu()
{
    system("cls");
    printf("*****************************************\n");
    printf("****1.添加联系人         2.删除联系人****\n");
    printf("****3.查找联系人         4.修改联系人****\n");
    printf("****5.显示联系人         6.排序      ****\n");
    printf("****0.退出                          *****\n");
    printf("*****************************************\n");
}

// 增加容量
void AddCapcity(struct Contact *ps)
{
    if (ps->size == ps->capacity)
    {
        // 增加容量
        struct PeoInfo *ptr = realloc(ps->data, (ps->capacity + 1) * sizeof(PeoInfo));
        if (ptr != NULL)
        {
            ps->data = ptr;
            ps->capacity += 1;
        }
    }
}
// 初始化通讯录
void InitContact(struct Contact *ps)
{
    // 申请初始容量的动态内存
    ps->data = (PeoInfo *)malloc(DEFAULT_SZ * sizeof(PeoInfo));
    if (ps->data == NULL)
    {
        return;
    }
    ps->size = 0;
    ps->capacity = DEFAULT_SZ;

    // 加载文件
    FILE *pfRead = fopen("contact.dat", "rb");
    if (pfRead == NULL)
    {
        printf("%s\n", strerror(errno));
        return;
    }
    // 加载
    struct PeoInfo temp = {0};
    while (fread(&temp, sizeof(struct PeoInfo), 1, pfRead))
    {
        AddCapcity(ps);
        ps->data[ps->size] = temp;
        ps->size++;
    }
    fclose(pfRead);
    pfRead = NULL;
}

// 添加信息
void AddContact(struct Contact *ps)
{
    // 增加当前通讯录的容量
    system("cls");
    AddCapcity(ps);
    printf("输入名字:");
    scanf("%s", ps->data[ps->size].name);
    printf("输入年龄:");
    scanf("%d", &(ps->data[ps->size].age));
    printf("输入性别:");
    scanf("%s", ps->data[ps->size].male);
    printf("输入电话:");
    scanf("%s", ps->data[ps->size].tele);
    printf("输入地址:");
    scanf("%s", ps->data[ps->size].addr);
    ps->size++;
    printf("添加成功\n");
    Sleep(1000);
}

// 显示  打印通讯录的信息
void ShowContact(const struct Contact *ps)
{
    system("cls");
    printf("显示结果:\n");
    if (ps->size == 0)
    {
        printf("空\n");
        system("pause");
    }
    else
    {
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");

        for (int i = 0; i < ps->size; i++)
        {
            printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                   ps->data[i].name,
                   ps->data[i].age,
                   ps->data[i].male,
                   ps->data[i].tele,
                   ps->data[i].addr);
        }
        system("pause");
    }
}

// 删除信息
void DelContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入删除人的名字：");
    scanf("%s", name);
    int i;
    for (i = 0; i < ps->size; i++)
    {
        if (i == ps->size)
        {
            printf("没有该人的信息\n");
            break;
        }
        else if (ps->size == 1)
        {
            memset(ps->data, 0, sizeof(ps->data));
            ps->size = 0;
        }
        // 删除信息
        else
        {
            int j;
            for (j = i; j < ps->size - 1; j++)
            {
                ps->data[j] = ps->data[j + 1];
                ps->size--;
            }
        }
        printf("删除成功\n");
        Sleep(1000);
    }
}

// 查找信息
void SeaechContact(struct Contact *ps)
{
    system("cls");
    char name[MAX_NAME];
    printf("请输入查找人的名字：");
    scanf("%s", name);
    int i;
    printf("查找结果:\n");
    for (i = 0; i < ps->size; i++)
    {
        if (i == ps->size)
        {
            printf("没有该人的信息\n");
            system("pause");
            break;
        }
        else if (0 == strcmp(name, ps->data[i].name))
        {
            printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");

            printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                   ps->data[i].name,
                   ps->data[i].age,
                   ps->data[i].male,
                   ps->data[i].tele,
                   ps->data[i].addr);

            system("pause");
        }
    }
}

// 修改信息
void ModifyContact(struct Contact *ps)
{
    system("cls");
    char name[MAX_NAME];
    printf("请输入修改人的名字：");
    scanf("%s", name);
    int i;
    for (i = 0; i < ps->size; i++)
    {
        if (i == ps->size)
        {
            printf("没有该人的信息\n");
            system("pause");
            break;
        }
        else if (0 == strcmp(name, ps->data[i].name))
        {
            printf("输入名字:");
            scanf("%s", ps->data[i].name);
            printf("输入年龄:");
            scanf("%d", &(ps->data[i].age));
            printf("输入性别:");
            scanf("%s", ps->data[i].male);
            printf("输入电话:");
            scanf("%s", ps->data[i].tele);
            printf("输入地址:");
            scanf("%s", ps->data[i].addr);
        }
        printf("修改成功\n");
        Sleep(1000);
    }
}

// 按照姓名信息排序
void SortContact(struct Contact *ps)
{
    int i, j;
    struct PeoInfo temp;
    for (i = 0; i < ps->size - 1; i++)
    {
        for (j = 0; j < ps->size - 1 - i; j++)
        {
            if (strcmp(ps->data[j].name, ps->data[j + 1].name) > 0)
            {
                temp = ps->data[j + 1];
                ps->data[j + 1] = ps->data[j];
                ps->data[j] = temp;
            }
        }
    }
    printf("排序完成\n");
    Sleep(1000);
}

// 保存文件
void saveFile(struct Contact *ps)
{
    FILE *pfWrite = fopen("contact.dat", "wb");
    if (pfWrite == NULL)
    {
        printf("%s\n", strerror(errno));
        return;
    }
    // 保存
    for (int i = 0; i < ps->size; i++)
    {
        fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfWrite);
    }

    printf("保存成功\n");
    Sleep(1000);
    fclose(pfWrite);
    pfWrite = NULL;
}

// 释放内存 保存文件
void Save_and_Free(Contact *ps)
{
    char choose;
    printf("是否保存此次更改\n请输入Y或N\n");
    setbuf(stdin, NULL);
    scanf("%c", &choose);
    if (choose == 'Y' || choose == 'y')
    {
        saveFile(ps);
        free(ps->data);
        ps->data = NULL;
    }
    else if (choose == 'N' || choose == 'n')
    {
        printf("信息未保存\n");
        free(ps->data);
        ps->data = NULL;
    }
}