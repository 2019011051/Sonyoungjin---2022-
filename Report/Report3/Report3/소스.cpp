#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenRandSeed();     // generating the seed number using the time clock information
unsigned int GenRandNum(unsigned int nRange);  // generating the random number
int Line_up_Program();        // �ٹٲٱ� ���α׷� ����
void Multi_Matrix(int A_nRange[5][5], int B_nRange[5][5]);   //���� ��� ���α׷� ����

int main (void)
{
	GenRandSeed();    // assigning seed
	int Line = 0;           // �� ���� ����
	int Row = 0;              // �� ���� ����
	int A_nRange[5][5] = { 0 };        // A����� �迭 ����
	int B_nRange[5][5] = { 0 };         // B����� �迭 ����

	printf("A-Matrix");                    
	printf("\n");
	
	for (Line = 0; Line < 5; Line++)      //  ������ ���� A��Ŀ� �Է� 
	{
		printf("[");                       // �� ��տ� [ ���
		for (Row = 0; Row < 5; Row++)          
		{
			A_nRange[Line][Row] = rand() % 100;         
			printf("%d\t", A_nRange[Line][Row]);           // A��� ���
		}
		printf("]");                            // �� ��տ� ] ���
		printf("\n");
	}
	
	Line_up_Program();               // ���� ���� ���α׷� �Լ� ȣ��

 	printf("B-Matrix");
	printf("\n");

	for (Line = 0; Line < 5; Line++)           // ������ ���� B��Ŀ� �Է� 
	{
		printf("[");                            // �� ��տ� [ ���
		for (Row = 0; Row < 5; Row++)
		{
			B_nRange[Line][Row] = rand() % 100;
			printf("%d\t", B_nRange[Line][Row]);           // B��� ���
		}
		printf("]");                                   // �� ��տ� ] ���
		printf("\n");
	}
	Multi_Matrix(A_nRange, B_nRange);                 //���� ��� ���α׷� ȣ��
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

// �� ���� �Լ�
int Line_up_Program()         
{
	int Line_up = 0;

	for (Line_up = 0; Line_up < 50; Line_up++)
	{
		printf("");
	}
	printf("\n");
	return 0;
}

// �� ����� �� ���ϴ� �Լ� �Ű����� A_nRange[5][5], int B_nRange[5][5]
void Multi_Matrix(int A_nRange[5][5], int B_nRange[5][5])
{
	int Mult=0;
	int Mult_Matrix[5][5]= {0};

	int Line;
	int Row;
	int X;
	
	for (Line = 0; Line < 5; Line++)                // �տ� ������ A��İ� B����� ���� ��Ÿ���� ��
	{
		for (Row = 0; Row < 5; Row++)
		{
			for (X = 0; X < 5; X++)
			{
				Mult += A_nRange[Line][X] * B_nRange[X][Row];
			}
			Mult_Matrix[Line][Row] = Mult;
		}
	}
	printf("A_Matrix X B_Matrix : ");
	printf("\n");

	for (Line = 0; Line < 5; Line++)     // ���� ��� �� ���
	{
		printf("[");
		for (Row = 0; Row < 5; Row++)
		{
			printf("%d\t", Mult_Matrix[Line][Row]);
		}
		printf("]");
		printf("\n");
	}

}

