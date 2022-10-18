#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define END_COND 999

void GenRandArray()
{

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

int main(void)
{

	GenRandSeed();    // assigning seed


	int nRange = 0;   // initializing variables

	while (1)
	{

		printf("Input a single number, for generating the random number related to your input:\n");  // generating the input information
		printf("if you want to end the loop, please input 999\n");
		scanf_s("%d", &nRange);


		if (nRange == END_COND)  // escaping the while loop
		{
			printf("end of the infinite while loop...\n");
			break;
		}
		else
		{

			int nRes = GenRandNum(nRange);   // generating the random number


			printf("Result:random number generator, %d\n\n", nRes);  // for debugging
		}
	}

	system("pause");
	return 0;
}
