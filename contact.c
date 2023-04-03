#include"contact.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps)
{
    memset(ps->date,0,sizeof(ps->date));
    ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
}


//�����Ϣ
void AddContact(struct Contact* ps)
{
    if(ps->size==1000)
    {
        printf("�������޷�����\n");
    }
    else
        {
            printf("��������:");
            scanf("%s",ps->date[ps->size].name);
            printf("��������:");
            scanf("%d",&(ps->date[ps->size].age));
            printf("�����Ա�:");
            scanf("%s",ps->date[ps->size].male);
            printf("����绰:");
            scanf("%s",ps->date[ps->size].tele);
            printf("�����ַ:");
            scanf("%s",ps->date[ps->size].addr);
        }
        ps->size++;
        printf("��ӳɹ�\n");
}

//��ʾ  ��ӡͨѶ¼����Ϣ
void ShowContact(const struct Contact* ps)
{
    printf("��ʾ���:\n");
    if(ps->size==0)
    {
        printf("��\n");
    }
    else
    {
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","��ַ");

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

//ɾ����Ϣ
void DelContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("������ɾ���˵����֣�");
    scanf("%s",name);
    int i;
    for(i=0;i<ps->size;i++)
    {
        if(i==ps->size)
        {
            printf("û�и��˵���Ϣ\n");
            break;
        }
        else if(ps->size==1)
        {
            memset(ps->date,0,sizeof(ps->date));
            ps->size = 0;
        }
        //ɾ����Ϣ 
        else      
        {
            int j;
            for(j=i;j<ps->size-1;j++)
            {
                ps->date[j]=ps->date[j+1];
                ps->size--;
            }
        }
        printf("ɾ���ɹ�\n");
        system("pause");
    }
}
//������Ϣ
void SeaechContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("����������˵����֣�");
    scanf("%s",name);
    int i;
    printf("���ҽ��:\n");
    for(i=0;i<ps->size;i++)
    {
        if(i==ps->size)
        {
            printf("û�и��˵���Ϣ\n");
            system("pause");
            break;
        }
        else if(0==strcmp(name,ps->date[i].name))
        {
            printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","��ַ");

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
//�޸���Ϣ
void ModifyContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("�������޸��˵����֣�");
    scanf("%s",name);
    int i;
    for(i=0;i<ps->size;i++)
    {
        if(i==ps->size)
        {
            printf("û�и��˵���Ϣ\n");
            system("pause");
            break;
        }  
        else if(0==strcmp(name,ps->date[i].name))
        {
            printf("��������:");
            scanf("%s",ps->date[i].name);
            printf("��������:");
            scanf("%d",&(ps->date[i].age));
            printf("�����Ա�:");
            scanf("%s",ps->date[i].male);
            printf("����绰:");
            scanf("%s",ps->date[i].tele);
            printf("�����ַ:");
            scanf("%s",ps->date[i].addr);
        }
        printf("�޸ĳɹ�\n");
        system("pause");
    }  
}
//��Ϣ����
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
    printf("�������\n");
    system("pause");
}
