#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define END_COND 999
void GenRandSeed();
unsigned int GenRandNum(unsigned int nRange); // generating the random number
int Ran_Num();
int Average();


int main(void)
{
	Average();
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

int Ran_Num()
{
	GenRandSeed();          // assigning seed

	int a_number;
	int nRange[10] = { 0 };
	int sum = 0;
	for (a_number = 0; a_number < 10; a_number++)
	{
		nRange[a_number] = rand()%100;
	}
	for (a_number = 0; a_number < 10; a_number++)
	{
		printf("%4d", nRange[a_number]);
		sum += nRange[a_number];
	}
	return sum;
}

int Average()
{
	GenRandSeed();
	int savesum[10] = {Ran_Num()};
	int* Psum = &savesum[10];
	double avg = 0;
    avg = *Psum /static_cast<double>(10);
	printf("Average : %lf\n", avg);
	return 0;
}

