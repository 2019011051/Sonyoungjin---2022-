#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Size 10

int Line_up_Program();

int main(void)
{
	int n,i, j, temp = 0;            //variable declaration
	int Number[Size] = { 0 };    //Set a random number in an array
	
	// Output from Array 1 to 10
	for (n = 0; n < Size; n++)
	{
		Number[n] = rand() % 100;
		printf("This is %d number : %d\n", n, Number[n]);
	}  

	//Call Line Plot Program
	Line_up_Program();

	// To organize a set array in ascending order
	for (i = 0; i < Size; i++)
	{
		for (j= i+1; j< Size; j++)
		{
			// A sentence that moves the integer value by rotating the for statement and comparing the arrangement in order
			if (*(Number+ i) > *(Number+j))    
			{
				temp = *(Number + i);       // ex) Number[0]값ex) Store the value of Number[0] in the temp value을 temp값에 저장
				* (Number + i) = *(Number + j);   // ex) Number[1]값을 Number[0]ex) Store the value of Number[1] in Number[0]에 저장
				*(Number + j) = temp;              // ex) Save the saved temp value to Number[1]
			}
		}
	}
	// To output a summary of the ascending order
	for (i = 0; i < Size; i++)
	{
		printf("ascending order %d number : %d\n", i, Number[i]);
	}
	// Calling a jump-off program
	Line_up_Program();

	//Organize the set array in descending order        

	for (i = 0; i < Size; i++)        ////Systems such as ascending above
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
	//Output organized descending order
	for (i = 0; i < Size; i++)
	{
		printf("descending %d number : %d\n", i, Number[i]);
	}
	return 0;
}


// Line Plot Function
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
