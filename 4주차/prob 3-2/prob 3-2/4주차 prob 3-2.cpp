#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	int nA, nB, res;                     // Set three variables
	char arithmeticoperations;          //Set four-factor operation variable

	printf("Input your nA, arithmeticoperations, nB:");      //Input your information
	scanf_s("%d%c%d", &nA, &arithmeticoperations, 1, &nB);   // scan enter A, operation, B

	if (arithmeticoperations == '+')      //If the arithmetic symbol is +
	{
		res = nA + nB;                    //additon cacluation 
		printf("addtion:\n");             // Show this operation is additon
	}
	else if (arithmeticoperations == '-')  //If the arithmetic symbol is -
	{
		res = nA - nB;                   //substraction cacluation
		printf("subtraction:\n");        //Show this operation is substraction
	}
	else if (arithmeticoperations == '/')  //If the arithmetic symbol is /
	{
		res = nA / nB;                 //division cacluation
		printf("division:\n");         // Show this operation is division
	}
	else                               //If the arithmetic symbol is *
	{
		res = nA * nB;                  //multiplication cacluation
		printf("multiplication:\n");    // Show this operation is multiplicationmultiplication cacluation

	}
	
		
	printf("%d%c%d = %d\n", nA, arithmeticoperations, nB, res);  // show the result
	system("pause");
	return 0;
}
