#include<stdio.h>
#include<stdlib.h>

#define Zero 0

int main()
{
	// Setting Variables
	int num;
	int* pn;    //Declare the pointer to which the dynamic assignment is to be linked

	int i, j;
	int count = Zero;

	printf("> Positive Input : ");
	scanf_s("%d", &num);

	//Allocate String Storage
	pn = (int*)malloc((num - 1) * sizeof(int));

	//Exception handling syntax when out of memory
	if (pn == NULL)
	{
		printf("Out of memory!\n");
		exit(1);
	}
	
	// i is repeated from 0 to num-1
	for (i = Zero; i < (num - 1); i++)
	{
		pn[i] = i + 2 ;          //Store i+2 in a dynamically assigned array 
	}

	for (i = Zero; i < (num - 1); i++)           
	{
		for (j = 2; j <= num; j++)
		{
			if ((i + 2 != j) && ((i + 2) % j == Zero))    //If i + 2 is not equal to j and i + 2 is divided by j and the rest is 0 
			{
				pn[i] = 1;  // pn[i] is 1
			}
		}
	}

	for (i = Zero; i < (num - 2); i++)           // I use num-1 to express it up to 29 as shown in the book
	{
		if ((count != Zero) && (count % 5 == Zero))   
		{
			printf("\n");
		}
		count++;         //Increase count 

		if (pn[i] == 1)     //If pn[i] is 1, then x - output
		{
			printf("%5c", 'X');
		}
		else                     
		{ 
			printf("%5d", pn[i]);
		}
	}

	free(pn);   //Return Dynamic Assignment Area
	return 0;
}