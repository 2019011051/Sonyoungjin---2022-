#include<stdio.h>
#include<stdlib.h>

#define MINCHESTSIZE 90                 // 90 definition
#define MAXCHESTSIZE 100                // 100 definition
int main(void)
{
	int nChestsize = 0;                   // chestsize variable settings
	char chChestsize;                    


	printf("input your chest size:\n");      // input chestsize
	scanf_s("%d", &nChestsize);

	if (nChestsize <= MINCHESTSIZE)             //Select S if chestsize is less than or equal to 90
	{
		chChestsize ='S';
	}
	else if ((nChestsize >MINCHESTSIZE) && (nChestsize <=MAXCHESTSIZE))      // Select M if chestsize is greater than 90 and less than or equal to 100
	{
		chChestsize = 'M';
	}
	else                                             // Chestsize is greater than 100 and L is selected
	{
		chChestsize = 'L';
	} 

	printf("Your chestsize is %c", chChestsize);     // input your chestsize
	system("pause");
	return 0;
}