
#include<stdio.h>
#include<stdlib.h>

int main()
{
	//Variable declaration
	int number;
	int* pn;
	int i, j;
	int count = 0;

	printf("> 양수 입력 : ");
	scanf_s("%d", &number);

	//Connect pointer after dynamic memory allocation
	pn = (int*)malloc((number-1)*sizeof(int));
	
	//Putting numbers in an array
	for (i = 0; i < (number - 1); i++)
	{
		pn[i] = i + 2;
	}
	

	//In order to distinguish between prime and non-minority parts when printing
	// the non-minority part is designated as 1
	for (i = 0; i < (number - 1); i++)            
	{
		for (j = 2; j <= number; j++)
		{
			if ((i + 2 != j) && ((i + 2) % j == 0))
			{
				pn[i] = 1;
			}
		}
	}
	
	
	//X in non-minority parts
	for (i = 0; i < (number - 1); i++)
	{
		if ((count != 0) && (count % 5 == 0)) // If the number is not zero or divided by five, then there is no remainder
		{
			printf("\n");
		}
		count++;   

		if (pn[i] == 1)
		{
			printf("%5c", 'X');
		}
		else
		{
			printf("%5d", pn[i]);
		}
	}
	free(pn);         //Return Dynamic Assignment Area
	return 0;
}