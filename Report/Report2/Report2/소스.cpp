#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define Size 10


void GenRandSeed();
unsigned int GenRandNum(unsigned int nRange); // generating the random numberd

double Ran_Num();               // Ran_Num �Լ� ����

double Average(double sum);          //  ��� ���ϴ� �Լ� ����
double Dispersion(double Dis);       // �л� ���ϴ� �Լ� ����

 

int main(void)
{
	Ran_Num();                      // Ran_Num �Լ� ȣ��
	return 0;
}

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

double Ran_Num()
{
	GenRandSeed();          // assigning seed
	double res ,res1 , res2 =0;  // ���, �л�, ǥ������ ���� ����
	double sum = 0;              // �� ����
	double Dis = 0;              // �л������ ���� ����
	double Disperation=0;
    

    int a_number;                // �迭��ȣ ����
	double nRange[Size] = { 0 };      // ������ ���� �迭 ����
	

	// ������ ���� �迭�� ���ʴ�� ������ ���� �ֱ�
	for (a_number = 0; a_number < 10; a_number++)    
	{
         nRange[a_number] = rand()%100;
	}
	for (a_number = 0; a_number < 10; a_number++)
	{
		printf("%5.0f", nRange[a_number]);              // ������ ���� �迭 ȣ��
        sum += nRange[a_number];                         // ������ ���� �迭�� ���� 
		Dis += (nRange[a_number] - Average(sum)) * (nRange[a_number] - Average(sum));   // ������ ���� �迭- ��� �� ������ ����
	}
	res = Average(sum);                                   // ����Լ� ȣ���Ͽ� �� ���� res�� ����
	res1 =Dispersion(Dis);                                // �л� �Լ� ȣ���Ͽ� �� ���� res1�� ����
	res2 = sqrt(res1);                                    // res1�� ���� �������Ͽ� res2�� ����
	
	printf("\nAverage : %.2f", res);                      // ��� �� ���
  	printf("\nDispersion : % .2f", res1);                 // �л� �� ���
 	printf("\nStandard Deviation : %.2f", res2);           // ǥ������ �� ���
	return 0;
}

// ��� ���ϴ� �Լ� �Ű����� sum
double Average(double sum)
{
	double avg;
    avg = sum /10;
	return avg;
}

// �л� ���ϴ� �Լ� �Ű����� Dis
double Dispersion(double Dis)
{
	double Disperation;

	Disperation = Dis / 10;

	return Disperation;
}



