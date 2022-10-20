#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenRandSeed();     // generating the seed number using the time clock information
unsigned int GenRandNum(unsigned int nRange);  // generating the random number
int Line_up_Program();        // 줄바꾸기 프로그램 선언
void Multi_Matrix(int A_nRange[5][5], int B_nRange[5][5]);   //곱셈 행렬 프로그램 선언

int main (void)
{
	GenRandSeed();    // assigning seed
	int Line = 0;           // 행 변수 선언
	int Row = 0;              // 열 변수 선언
	int A_nRange[5][5] = { 0 };        // A행렬의 배열 선언
	int B_nRange[5][5] = { 0 };         // B행렬의 배열 선언

	printf("A-Matrix");                    
	printf("\n");
	
	for (Line = 0; Line < 5; Line++)      //  무작위 숫자 A행렬에 입력 
	{
		printf("[");                       // 각 행앞에 [ 출력
		for (Row = 0; Row < 5; Row++)          
		{
			A_nRange[Line][Row] = rand() % 100;         
			printf("%d\t", A_nRange[Line][Row]);           // A행렬 출력
		}
		printf("]");                            // 각 행앞에 ] 출력
		printf("\n");
	}
	
	Line_up_Program();               // 라인 띄우기 프로그램 함수 호출

 	printf("B-Matrix");
	printf("\n");

	for (Line = 0; Line < 5; Line++)           // 무작위 숫자 B행렬에 입력 
	{
		printf("[");                            // 각 행앞에 [ 출력
		for (Row = 0; Row < 5; Row++)
		{
			B_nRange[Line][Row] = rand() % 100;
			printf("%d\t", B_nRange[Line][Row]);           // B행렬 출력
		}
		printf("]");                                   // 각 행앞에 ] 출력
		printf("\n");
	}
	Multi_Matrix(A_nRange, B_nRange);                 //곱셈 행렬 프로그램 호출
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

// 줄 띄우기 함수
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

// 두 행렬의 곱 구하는 함수 매개변수 A_nRange[5][5], int B_nRange[5][5]
void Multi_Matrix(int A_nRange[5][5], int B_nRange[5][5])
{
	int Mult=0;
	int Mult_Matrix[5][5]= {0};

	int Line;
	int Row;
	int X;
	
	for (Line = 0; Line < 5; Line++)                // 앞에 선언한 A행렬과 B행렬의 곱을 나타내는 식
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

	for (Line = 0; Line < 5; Line++)     // 곱한 행렬 값 출력
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

