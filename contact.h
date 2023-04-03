#include<stdio.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_MALE 5
#define MAX_ADDR 30

struct PeoInfo
{
    char name[MAX_NAME];
    char tele[MAX_TELE];
    char male[MAX_MALE];
    int age;
    char addr[MAX_ADDR];
};
enum option
{
    EXIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
    SORT
};
//通讯录类型
struct Contact
{
    struct PeoInfo date[MAX];//存放一的信息。
    int size;//记录当前已经有的元素个数。
};

//声明函数

//初始化通讯录
void InitContact(struct Contact* ps);
//添加信息
void AddContact(struct Contact* ps);
//显示  打印通讯录的信息
void ShowContact(const struct Contact* ps);
//删除信息
void DelContact(struct Contact* ps);
//查找信息
void SeaechContact(struct Contact* ps);
//修改信息
void ModifyContact(struct Contact* ps);
//信息排序
void SortContact(struct Contact* ps);
