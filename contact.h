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
//ͨѶ¼����
struct Contact
{
    struct PeoInfo date[MAX];//���һ����Ϣ��
    int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ�����
};

//��������

//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps);
//�����Ϣ
void AddContact(struct Contact* ps);
//��ʾ  ��ӡͨѶ¼����Ϣ
void ShowContact(const struct Contact* ps);
//ɾ����Ϣ
void DelContact(struct Contact* ps);
//������Ϣ
void SeaechContact(struct Contact* ps);
//�޸���Ϣ
void ModifyContact(struct Contact* ps);
//��Ϣ����
void SortContact(struct Contact* ps);
