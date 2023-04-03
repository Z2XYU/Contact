#include"contact.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//初始化通讯录
void InitContact(struct Contact* ps)
{
    memset(ps->date,0,sizeof(ps->date));
    ps->size = 0;//设置通讯录最初只有0个元素
}


//添加信息
void AddContact(struct Contact* ps)
{
    if(ps->size==1000)
    {
        printf("已满，无法增加\n");
    }
    else
        {
            printf("输入名字:");
            scanf("%s",ps->date[ps->size].name);
            printf("输入年龄:");
            scanf("%d",&(ps->date[ps->size].age));
            printf("输入性别:");
            scanf("%s",ps->date[ps->size].male);
            printf("输入电话:");
            scanf("%s",ps->date[ps->size].tele);
            printf("输入地址:");
            scanf("%s",ps->date[ps->size].addr);
        }
        ps->size++;
        printf("添加成功\n");
}

//显示  打印通讯录的信息
void ShowContact(const struct Contact* ps)
{
    printf("显示结果:\n");
    if(ps->size==0)
    {
        printf("空\n");
    }
    else
    {
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");

        for(int i=0;i<ps->size;i++)
        {
            printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
            ps->date[i].name,
            ps->date[i].age,
            ps->date[i].male,
            ps->date[i].tele,
            ps->date[i].addr);
        }
        system("pause");
    }
}

//删除信息
void DelContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("请输入删除人的名字：");
    scanf("%s",name);
    int i;
    for(i=0;i<ps->size;i++)
    {
        if(i==ps->size)
        {
            printf("没有该人的信息\n");
            break;
        }
        else if(ps->size==1)
        {
            memset(ps->date,0,sizeof(ps->date));
            ps->size = 0;
        }
        //删除信息 
        else      
        {
            int j;
            for(j=i;j<ps->size-1;j++)
            {
                ps->date[j]=ps->date[j+1];
                ps->size--;
            }
        }
        printf("删除成功\n");
        system("pause");
    }
}
//查找信息
void SeaechContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("请输入查找人的名字：");
    scanf("%s",name);
    int i;
    printf("查找结果:\n");
    for(i=0;i<ps->size;i++)
    {
        if(i==ps->size)
        {
            printf("没有该人的信息\n");
            system("pause");
            break;
        }
        else if(0==strcmp(name,ps->date[i].name))
        {
            printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","名字","年龄","性别","电话","地址");

                printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                ps->date[i].name,
                ps->date[i].age,
                ps->date[i].male,
                ps->date[i].tele,
                ps->date[i].addr);

            system("pause");
        }
    }
}
//修改信息
void ModifyContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("请输入修改人的名字：");
    scanf("%s",name);
    int i;
    for(i=0;i<ps->size;i++)
    {
        if(i==ps->size)
        {
            printf("没有该人的信息\n");
            system("pause");
            break;
        }  
        else if(0==strcmp(name,ps->date[i].name))
        {
            printf("输入名字:");
            scanf("%s",ps->date[i].name);
            printf("输入年龄:");
            scanf("%d",&(ps->date[i].age));
            printf("输入性别:");
            scanf("%s",ps->date[i].male);
            printf("输入电话:");
            scanf("%s",ps->date[i].tele);
            printf("输入地址:");
            scanf("%s",ps->date[i].addr);
        }
        printf("修改成功\n");
        system("pause");
    }  
}
//信息排序
void SortContact(struct Contact* ps)
{
    int i,j;
    struct PeoInfo temp;
   for(i = 0;i < ps->size-1;i++)
   {
        for(j = 0;j < ps->size-1-i;j++)
        {
            if(strcmp(ps->date[j].name,ps->date[j+1].name) > 0)
            {
                temp = ps->date[j+1];
                ps->date[j+1] = ps->date[j];
                ps->date[j] = temp;
            }
        }
   }
    printf("排序完成\n");
    system("pause");
}
