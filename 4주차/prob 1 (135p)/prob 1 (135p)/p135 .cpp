#include<stdio.h>
#include<stdlib.h>

#define MINCHESTSIZE 90
#define MAXCHESTSIZE 100
int main(void)
{
	int nChestsize = 0;               
	char chChestsize;


	printf("input your chest size:\n");
	scanf_s("%d", &nChestsize);

	if (nChestsize <= MINCHESTSIZE)
	{
		chChestsize ='S';
	}
	else if ((nChestsize >MINCHESTSIZE) && (nChestsize <=MAXCHESTSIZE))
	{
		chChestsize = 'M';
	}
	else
	{
		chChestsize = 'L';
	} 

	printf("Your chestsize is %c", chChestsize);
	system("pause");
	return 0;
}