#include <stdio.h>
#include <string.h>

#define PIN "7042"     // PIN�ѹ� 7042�� ����
#define Array_size 10  // �迭ũ�� 10���� ����

int PIN_Program(void);    // �Լ� ����

int main(void)
{
    PIN_Program();             // �Լ� ȣ�� 
    return 0;
}

int PIN_Program(void)
{
    char C_Password[10] = { PIN };   // �迭C_Password �迭�� 10 �ϰ� ���� ���� PIN 7 0 4 2 �׵ڷδ� ��.
    char M_Password[10] = "";  // M_Password �� �η� �ʱ�ȭ


    while (1)    //���ѹݺ��� ����
    {
        printf("Input your Password : ");    // Input your Password
        scanf_s("%s", M_Password, 10);       // 
        
        if (strcmp(C_Password, M_Password) == 0)break;  //����  C_Password �� M_Password�� ���ٸ� �ݺ��� Ż��

        else                                      // ���� �ʴٸ� 
        {
            printf("not matched, retry...");     // not matched,retry.. ���
        }

    }
    printf("normal termination");           //normal termination ���
    return 0;
}