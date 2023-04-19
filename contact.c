#include"contact.h"

//��ʼ��ͨѶ¼
void InitContact(struct Contact* ps)
{
    //�����ʼ�����Ķ�̬�ڴ�
    ps->data=(PeoInfo*)malloc(DEFAULT_SZ*sizeof(PeoInfo));
    if(ps->data==NULL)
    {
        return;
    }
    ps->size=0;
    ps->capacity=DEFAULT_SZ;
}



void CheckCapcity(struct Contact *ps)
{
    if(ps->size==ps->capacity)
    {
        //��������
        struct PeoInfo *ptr =realloc(ps->data,(ps->capacity+1)*sizeof(PeoInfo));
        if(ptr!=NULL)
        {
            ps->data = ptr;
            ps->capacity +=1;
        }
    }
}
//�����Ϣ
void AddContact(struct Contact* ps)
{
  //���ӵ�ǰͨѶ¼������
    system("cls");
    CheckCapcity(ps);
    printf("��������:");
    scanf("%s",ps->data[ps->size].name);
    printf("��������:");
    scanf("%d",&(ps->data[ps->size].age));
    printf("�����Ա�:");
    scanf("%s",ps->data[ps->size].male);
    printf("����绰:");
    scanf("%s",ps->data[ps->size].tele);
    printf("�����ַ:");
    scanf("%s",ps->data[ps->size].addr);
    ps->size++;
    printf("��ӳɹ�\n");
    Sleep(1000);
}





//��ʾ  ��ӡͨѶ¼����Ϣ
void ShowContact(const struct Contact* ps)
{
    system("cls");
    printf("��ʾ���:\n");
    if(ps->size==0)
    {
        printf("��\n");
        system("pause");
    }
    else
    {
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","��ַ");

        for(int i=0;i<ps->size;i++)
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
            memset(ps->data,0,sizeof(ps->data));
            ps->size = 0;
        }
        //ɾ����Ϣ 
        else      
        {
            int j;
            for(j=i;j<ps->size-1;j++)
            {
                ps->data[j]=ps->data[j+1];
                ps->size--;
            }
        }
        printf("ɾ���ɹ�\n");
        Sleep(1000);
    }
}



//������Ϣ
void SeaechContact(struct Contact* ps)
{
    system("cls");
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
        else if(0==strcmp(name,ps->data[i].name))
        {
            printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","��ַ");

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





//�޸���Ϣ
void ModifyContact(struct Contact* ps)
{
    system("cls");
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
        else if(0==strcmp(name,ps->data[i].name))
        {
            printf("��������:");
            scanf("%s",ps->data[i].name);
            printf("��������:");
            scanf("%d",&(ps->data[i].age));
            printf("�����Ա�:");
            scanf("%s",ps->data[i].male);
            printf("����绰:");
            scanf("%s",ps->data[i].tele);
            printf("�����ַ:");
            scanf("%s",ps->data[i].addr);
        }
        printf("�޸ĳɹ�\n");
        Sleep(1000);

    }  
}




//����������Ϣ����
void SortContact(struct Contact* ps)
{
    int i,j;
    struct PeoInfo temp;
   for(i = 0;i < ps->size-1;i++)
   {
        for(j = 0;j < ps->size-1-i;j++)
        {
            if(strcmp(ps->data[j].name,ps->data[j+1].name) > 0)
            {
                temp = ps->data[j+1];
                ps->data[j+1] = ps->data[j];
                ps->data[j] = temp;
            }
        }
   }
    printf("�������\n");
    Sleep(1000);
}




//�ͷ��ڴ�
void Free(Contact *ps)
{
    free(ps->data);
    ps->data =NULL;
}
