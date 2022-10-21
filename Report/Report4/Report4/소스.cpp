#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Size 10

int Line_up_Program();

int main(void)
{
	int n,i, j, temp = 0;            //변수 선언
	int Number[Size] = { rand() };    //배열안에 무작위 숫자 설정
	
	// 배열1~10까지 출력
	for (n = 0; n < Size; n++)
	{
		Number[n] = rand() % 100;
		printf("This is %d number : %d\n", n, Number[n]);
	}  

	//줄 띄우기 프로그램 호출
	Line_up_Program();

	// 설정된 배열을 오름차수로 정리하기
	for (i = 0; i < Size; i++)
	{
		for (j= i+1; j< Size; j++)
		{
			if (*(Number+ i) > *(Number+j))
			{
				temp = *(Number + i);
				* (Number + i) = *(Number + j);
				*(Number + j) = temp;
			}
		}
	}
	// 정리한 오름차수 출력하기
	for (i = 0; i < Size; i++)
	{
		printf("오름차수 %d number : %d\n", i, Number[i]);
	}
	
	// 줄띄우기 프로그램 호출
	Line_up_Program();

	//설정된 배열을 내림차수로 정리
	for (i = 0; i < Size; i++)
	{
		for (j = i + 1; j < Size; j++)
		{
			if (*(Number + i) < *(Number + j))
			{
				temp = *(Number + i);
				*(Number + i) = *(Number + j);
				*(Number + j) = temp;
			}
		}
	}
	//정리된 내림차수를 출력
	for (i = 0; i < Size; i++)
	{
		printf("내림차수 %d number : %d\n", i, Number[i]);
	}
	return 0;
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
