#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define Size 10


void GenRandSeed();
unsigned int GenRandNum(unsigned int nRange); // generating the random numberd

double Ran_Num();               // Ran_Num 함수 선언

double Average(double sum);          //  평균 구하는 함수 선언
double Dispersion(double Dis);       // 분산 구하는 함수 선언

 

int main(void)
{
	Ran_Num();                      // Ran_Num 함수 호출
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
	double res ,res1 , res2 =0;  // 평균, 분산, 표준편차 저장 변수
	double sum = 0;              // 합 변수
	double Dis = 0;              // 분산계산식의 분자 변수
	double Disperation=0;
    

    int a_number;                // 배열번호 변수
	double nRange[Size] = { 0 };      // 무작위 숫자 배열 선언
	

	// 무작위 숫자 배열에 차례대로 무작위 숫자 넣기
	for (a_number = 0; a_number < 10; a_number++)    
	{
         nRange[a_number] = rand()%100;
	}
	for (a_number = 0; a_number < 10; a_number++)
	{
		printf("%5.0f", nRange[a_number]);              // 무작위 숫자 배열 호출
        sum += nRange[a_number];                         // 무작위 숫자 배열의 총합 
		Dis += (nRange[a_number] - Average(sum)) * (nRange[a_number] - Average(sum));   // 무직위 숫자 배열- 평균 의 제곱의 총합
	}
	res = Average(sum);                                   // 평균함수 호출하여 그 값을 res에 저장
	res1 =Dispersion(Dis);                                // 분산 함수 호출하여 그 값을 res1에 저장
	res2 = sqrt(res1);                                    // res1의 값을 제곱근하여 res2에 저장
	
	printf("\nAverage : %.2f", res);                      // 평균 값 출력
  	printf("\nDispersion : % .2f", res1);                 // 분산 값 출력
 	printf("\nStandard Deviation : %.2f", res2);           // 표준편차 값 출력
	return 0;
}

// 평균 구하는 함수 매개변수 sum
double Average(double sum)
{
	double avg;
    avg = sum /10;
	return avg;
}

// 분산 구하는 함수 매개변수 Dis
double Dispersion(double Dis)
{
	double Disperation;

	Disperation = Dis / 10;

	return Disperation;
}



