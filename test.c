#include "contact.h"

void menu();
int main()

{
    int input = 0;
    // ����ͨѶ¼
    struct Contact con;
    // ��ʼ��ͨѶ¼
    InitContact(&con);
    do
    {
        menu();
        printf("��ѡ��ѡ�\n");
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
            // �ͷŶ�̬�����ڴ�
            Save_and_Free(&con);
            printf("�˳�ͨѶ¼��\n");
            Sleep(1000);
            exit(0);
        default:
            printf("��������ȷ��ѡ�\n");
            break;
        }
    } while (input);
    return 0;
}
