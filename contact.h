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
// ͨѶ¼����
// ʹ�ö�̬�ڴ���䴴��Contact�ṹ��
typedef struct Contact
{
    struct PeoInfo *data;
    int size;
    int capacity;
} Contact;

// ��������

// ��ӡ�˵�
void menu(void);

// ��ʼ��ͨѶ¼
void InitContact(struct Contact *ps);
// �����Ϣ
void AddContact(struct Contact *ps);
// ��ʾ  ��ӡͨѶ¼����Ϣ
void ShowContact(const struct Contact *ps);
// ɾ����Ϣ
void DelContact(struct Contact *ps);
// ������Ϣ
void SeaechContact(struct Contact *ps);
// �޸���Ϣ
void ModifyContact(struct Contact *ps);
// ��Ϣ����
void SortContact(struct Contact *ps);
// �ͷ��ڴ�
void Save_and_Free(Contact *ps);
// �����ļ�
void saveFile(Contact *ps);
