#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define END_COND 999
#define RAND_MAX 0x7fff


void GenRandSeed()   // generating the seed number using the time clock information
{
	
	srand((unsigned int)(time(NULL)));  // generating the random number using the time seed
	return;
}


unsigned int GenRandNum(unsigned int nRange) // generating the random number
{
	unsigned int nRes = 0;
	unsigned int nNum = rand();
	nRes = ((unsigned int)(nNum) % (nRange));
	return nRes;
}

    int main(void)
    {
        double Vertical[100] = { 0 };            //������ ���� �ֱ� ���� ����, ���� �Ǽ� ���� �ʱ�ȭ
        double Horizon[100] = { 0 };

        double Vertical_V[100] = { 0 };         //V ���� ����
        double Horizon_V[100];

        double Vertical_Z[100] = { 0 };   //Z,K, ���� �����ϴ� Z �Ǽ� ���� ����
        double Vertical_K[100] = { 0 };
        double rVertical_Z[100] = { 0 };

        double Horizon_Z[100] = { 0 };
        double Horizon_K[100] = { 0 };
        double rHorizon_Z[100] = { 0 };

        double Vertical_X[100] = { 0 };
        double Horizon_X[100] = { 0 };

        double RES[100][100];

        srand(((unsigned)time(NULL)));            //�ð����� ������ ���� �ʱ�ȭ �Լ�


        for (int i = 0; i < 100; i++)
        {
            Vertical[i] = (double)rand() / RAND_MAX;      //������ �Ǽ� 100�� ����
            Horizon[i] = (double)rand() / RAND_MAX;
        }

        printf("\n\n���� ���� 100��\n\n ");
        for (int j = 0; j < 100; j++)
        {
            if (j % 10 == 0)
            {
                printf("\n");
            }
            printf("%.3lf\t", Vertical[j]);
        }


        printf("\n\n���� ���� 100��\n\n");
        for (int j = 0; j < 100; j++)
        {
            if (j % 10 == 0)
            {
                printf("\n");
            }
            printf("%.3lf\t", Horizon[j]);

        }
        printf("\n");

        int a = 0;
        while (1)
        {
            if (Vertical_K[99] < 1 - Vertical[99])
            {
                rVertical_Z[99] = Vertical_Z[99];
                break;
            }
            for (int i = a; i < 100; i++)
            {

                Vertical_V[i] = (sqrt(2 / exp(1.0)) * (2 * Vertical[i] - 1));      //1�ܰ�
                Vertical_Z[i] = Vertical_V[i] / Vertical[i];                  //2�ܰ�
                Vertical_K[i] = 0.25 * (pow(Vertical_Z[i], 2));                  //2�ܰ�
                if (Vertical_K[i] < 1 - Vertical[i])                        //3�ܰ� 1������ 
                {
                    rVertical_Z[i] = Vertical_Z[i];
                }
                else if ((Vertical_K[i] >= (0.259 / Vertical[i]) + 0.35) && (Vertical_K[i] > -log10(Vertical[i])))      //3�ܰ� 2������ ���� ��
                {
                    Vertical[i] = (double)rand() / RAND_MAX;                  //������ �ٽ� ����
                    a = i;
                    break;                                             //for �� ���� while ������ �ٽ� �� 3�ܰ� 1������ ������ų ������ �ݺ�
                }
            }
        }
        for (int i = 0; i < 100; i++)                                    //4�ܰ�
        {
            Vertical_X[i] = 0 + rVertical_Z[i] * 1.0;                        //��� 0, ǥ������ 1.0
        }

        int b = 0;
        while (1)
        {
            if (Horizon_K[99] < 1 - Horizon[99])
            {
                rHorizon_Z[99] = Horizon_Z[99];
                break;
            }
            for (int i = a; i < 100; i++)
            {

                Horizon_V[i] = (sqrt(2 / exp(1.0)) * (2 * Horizon[i] - 1));      //V�� �� ����
                Horizon_Z[i] = Horizon_V[i] / Horizon[i];
                Horizon_K[i] = 0.25 * (pow(Horizon_Z[i], 2));
                if (Horizon_K[i] < 1 - Horizon[i])
                {
                    rHorizon_Z[i] = Horizon_Z[i];
                }
                else if ((Horizon_K[i] >= (0.259 / Horizon[i]) + 0.35) && (Horizon[i] > -log10(Horizon[i])))
                {
                    Horizon[i] = (double)rand() / RAND_MAX;
                    b = i;
                    break;
                }
            }
        }
        for (int i = 0; i < 100; i++)
        {
            Horizon_X[i] = 0 + rHorizon_Z[i] * 1.0;
        }

        printf("���� ����_X 100��\n ");
        for (int j = 0; j < 100; j++)
        {
            printf("%.3lf\n", Vertical_X[j]);
        }
        printf("���� ����_X 100��\n ");
        for (int j = 0; j < 100; j++)
        {
            printf("%.3lf\n", Horizon_X[j]);
        }



        return 0;
    }
