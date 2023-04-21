#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <errno.h>

#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_MALE 5
#define MAX_ADDR 30
#define DEFAULT_SZ 3

typedef struct PeoInfo
{
    char name[MAX_NAME];
    char tele[MAX_TELE];
    char male[MAX_MALE];
    int age;
    char addr[MAX_ADDR];
} PeoInfo;
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
// 通讯录类型
// 使用动态内存分配创建Contact结构体
typedef struct Contact
{
    struct PeoInfo *data;
    int size;
    int capacity;
} Contact;

// 声明函数

// 打印菜单
void menu(void);

// 初始化通讯录
void InitContact(struct Contact *ps);
// 添加信息
void AddContact(struct Contact *ps);
// 显示  打印通讯录的信息
void ShowContact(const struct Contact *ps);
// 删除信息
void DelContact(struct Contact *ps);
// 查找信息
void SeaechContact(struct Contact *ps);
// 修改信息
void ModifyContact(struct Contact *ps);
// 信息排序
void SortContact(struct Contact *ps);
// 释放内存
void Save_and_Free(Contact *ps);
// 保存文件
void saveFile(Contact *ps);
