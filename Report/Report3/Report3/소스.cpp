#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Line_number 5
#define Row_number 5
#define zero 0
#define Max 5

void GenRandSeed();     // generating the seed number using the time clock information
unsigned int GenRandNum(unsigned int nRange);  // generating the random number
int Line_up_Program();        // Declaring a new line program
void Multi_Matrix(int A_nRange[Line_number][Row_number], int B_nRange[Line_number][Row_number]);   //Multiplication Matrix Program Declaration

int main (void)
{
	GenRandSeed();    // assigning seed
	int Line = zero;           // Declare line variables 
	int Row = zero;              //Declare Row variables
	int A_nRange[Line_number][Row_number] = { zero };        // Declare the array of A matrices
	int B_nRange[Line_number][Row_number] = { zero };         // Declare the array of B matrices


	printf("A-Matrix");                    
	printf("\n");
	
	for (Line = zero; Line < Max; Line++)      //  Put in a random number A matrix 
	{
		printf("[");                       //Before each row [ output
		for (Row = zero; Row < Max; Row++)
		{
			A_nRange[Line][Row] = rand() % 100;         
			printf("%d\t", A_nRange[Line][Row]);           // A matrix output
		}
		printf("]");                            // After each row ] output
		printf("\n");
	}
	
	Line_up_Program();              // Call line float program function
 	printf("B-Matrix");
	printf("\n");

	for (Line = zero; Line < Max; Line++)           // Enter into a random number B matrix 
	{
		printf("[");                            // Before each row [ output
		for (Row = zero; Row < Max; Row++)
		{
			B_nRange[Line][Row] = rand() % 100;
			printf("%d\t", B_nRange[Line][Row]);           //B matrix output
		}
		printf("]");                                   // After each row ] output
		printf("\n");
	}
	Line_up_Program();
	Multi_Matrix(A_nRange, B_nRange);                 //Invoke multiplication matrix program
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

// The product of two matrices function parameters A_nRange[5][5], int B_nRange[5][5]
void Multi_Matrix(int A_nRange[Line_number][Row_number], int B_nRange[Line_number][Row_number])
{
	int Mult=0;
	int Mult_Matrix[Line_number][Row_number]= {0};

	int Line;
	int Row;
	int X;
	
	for (Line = zero; Line < Max; Line++)                // An expression that represents the product of the previously declared matrix A and B
	{
		for (Row = zero; Row < Max; Row++)
		{
			for (X = zero; X < Max; X++)
			{
				Mult += A_nRange[Line][X] * B_nRange[X][Row];
			}
			Mult_Matrix[Line][Row] = Mult;
		}

	}
	printf("A_Matrix X B_Matrix : ");
	printf("\n");

	for (Line = zero; Line < Max; Line++)     // Multiplied matrix value output
	{
		printf("[");
		for (Row = zero; Row < Max; Row++)
		{
			printf("%d\t", Mult_Matrix[Line][Row]);
		}
		printf("]");
		printf("\n");
	}

}

