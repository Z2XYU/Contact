#include"contact.h"
#include<stdio.h>
#include<stdlib.h>
void menu();
int main()

{
    int input=0;
    //����ͨѶ¼
    struct Contact con;
    //��ʼ��ͨѶ¼
    InitContact(&con);
    do
    {
        menu();
        printf("��ѡ��ѡ�\n");
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
            //�ͷŶ�̬�����ڴ�
            Free(&con);
            printf("�˳�ͨѶ¼��\n");
            break;
        default:
        printf("��������ȷ��ѡ�\n");
            break;
        }
    }while(input);
    return 0;
}
//��ӡ�˵�
void menu()
{
    system("cls");
    printf("*****************************************\n");
    printf("****1.�����ϵ��         2.ɾ����ϵ��*****\n");
    printf("****3.������ϵ��         4.�޸���ϵ��*****\n");
    printf("****5.��ʾ��ϵ��         6.����**********\n");
    printf("****0.�˳�                 *************\n");
    printf("****************************************\n");
}
