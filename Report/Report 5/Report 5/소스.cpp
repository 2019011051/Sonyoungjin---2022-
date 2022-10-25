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
        double Vertical[100] = { 0 };            //무작위 수를 넣기 위한 수직, 수평 실수 변수 초기화
        double Horizon[100] = { 0 };

        double Vertical_V[100] = { 0 };         //V 변수 선언
        double Horizon_V[100];

        double Vertical_Z[100] = { 0 };   //Z,K, 범위 만족하는 Z 실수 변수 선언
        double Vertical_K[100] = { 0 };
        double rVertical_Z[100] = { 0 };

        double Horizon_Z[100] = { 0 };
        double Horizon_K[100] = { 0 };
        double rHorizon_Z[100] = { 0 };

        double Vertical_X[100] = { 0 };
        double Horizon_X[100] = { 0 };

        double RES[100][100];

        srand(((unsigned)time(NULL)));            //시간마다 무작위 변수 초기화 함수


        for (int i = 0; i < 100; i++)
        {
            Vertical[i] = (double)rand() / RAND_MAX;      //무작위 실수 100개 생성
            Horizon[i] = (double)rand() / RAND_MAX;
        }

        printf("\n\n수직 변수 100개\n\n ");
        for (int j = 0; j < 100; j++)
        {
            if (j % 10 == 0)
            {
                printf("\n");
            }
            printf("%.3lf\t", Vertical[j]);
        }


        printf("\n\n수평 변수 100개\n\n");
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

                Vertical_V[i] = (sqrt(2 / exp(1.0)) * (2 * Vertical[i] - 1));      //1단계
                Vertical_Z[i] = Vertical_V[i] / Vertical[i];                  //2단계
                Vertical_K[i] = 0.25 * (pow(Vertical_Z[i], 2));                  //2단계
                if (Vertical_K[i] < 1 - Vertical[i])                        //3단계 1번조건 
                {
                    rVertical_Z[i] = Vertical_Z[i];
                }
                else if ((Vertical_K[i] >= (0.259 / Vertical[i]) + 0.35) && (Vertical_K[i] > -log10(Vertical[i])))      //3단계 2번조건 만족 시
                {
                    Vertical[i] = (double)rand() / RAND_MAX;                  //난수를 다시 생성
                    a = i;
                    break;                                             //for 문 나와 while 문으로 다시 들어가 3단계 1번조건 만족시킬 떄가지 반복
                }
            }
        }
        for (int i = 0; i < 100; i++)                                    //4단계
        {
            Vertical_X[i] = 0 + rVertical_Z[i] * 1.0;                        //평균 0, 표준편차 1.0
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

                Horizon_V[i] = (sqrt(2 / exp(1.0)) * (2 * Horizon[i] - 1));      //V값 식 대입
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

        printf("수직 변수_X 100개\n ");
        for (int j = 0; j < 100; j++)
        {
            printf("%.3lf\n", Vertical_X[j]);
        }
        printf("수평 변수_X 100개\n ");
        for (int j = 0; j < 100; j++)
        {
            printf("%.3lf\n", Horizon_X[j]);
        }



        return 0;
    }
