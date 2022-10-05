#include <stdio.h>

int main(void)
{
	int i, j;         //Specify variables i, j

	for (i = 2; i<=9; i++)        
	{
		for (j = 1; j <= 9; j++)
		{
			printf("%d*%d= %d\n", i, j, i * j);     //Utilize repeat control variables i and j
		}
	}


}