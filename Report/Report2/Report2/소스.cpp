#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define Size 10  // Array size is 10


void GenRandSeed();
unsigned int GenRandNum(unsigned int nRange); // generating the random numberd

double Ran_Num();               // Ran_Num function declaration

double Average(double sum);          //  Declare a function to be averaged
double Dispersion(double Dis);       // Declare a function to obtain variance

 

int main(void)
{
	Ran_Num();                      // Calling the Ran_Num function
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
	double res ,res1 , res2 =0;  // Mean, Variance, Standard Deviation Storage Variables
	double sum = 0;              // a sum variable
	double Dis = 0;              // Molecular Variables in Variance Calculations
	double Disperation=0;
    

    int a_number;                // Array number variable
	double nRange[Size] = { 0 };      // Declare random number arrangement
	

	// Putting random numbers in order `in a random number array
	for (a_number = 0; a_number < Size; a_number++)    
	{
         nRange[a_number] = rand()%100;
	}
	for (a_number = 0; a_number < Size; a_number++)
	{
		printf("%5.0f", nRange[a_number]);              // Random numeric array output
        sum += nRange[a_number];                         // Sum of random number arrays
		Dis += (nRange[a_number] - Average(sum)) * (nRange[a_number] - Average(sum));   // Array of unoccupied numbers - the sum of the squares of the means
	}
	res = Average(sum);                                   // Call the mean function and store the value in res
	res1 =Dispersion(Dis);                                // Invoke a variance function and store its value in res1
	res2 = sqrt(res1);                                    // Store the value of res1 in res2 by square root
	
	printf("\nAverage : %.2f", res);                      // Average Value Output
  	printf("\nDispersion : % .2f", res1);                 // Output Distributed Values
 	printf("\nStandard Deviation : %.2f", res2);           // Standard deviation value output
	return 0;
}

// function parameter sum obtained by averaging
double Average(double sum)
{
	double avg;
    avg = sum /Size;
	return avg;
}

// Variance Obtaining Function Parameters Dis
double Dispersion(double Dis)
{
	double Disperation;

	Disperation = Dis / Size;

	return Disperation;
}



