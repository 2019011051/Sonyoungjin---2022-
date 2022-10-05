#include <stdio.h>

int main(void)
{
	int i;                    // Specify a variable
	int n;                   //Specify a variable
	int k;                     //Specify a variable
	int cnt = 0;                 //Specify a variable

	printf("Enter an integer greater than or equal to 2 : ");     // "input Enter an integer greater than or equal to 2 "
	scanf_s("%d", &k);                                          // input your k
	
	for (i = 2; i <=k; i++)  
	{
		for (n = 2; n <=i; n++)
		{
			if (i%n==0)                         // If i divided by n and the rest is zero,                          
			{
				if (i>n) break;           // If i is greater than n, escape the inner repeat door

				else                     // If i divided by n and the rest is zero,
				{
					printf("%5d", i);      // 5 i-output with space
					cnt++;                 // CNT rear-end increment/decrease operator
					if(cnt % 5 == 0)       //   If you divide the cnt by 5 and divide it
					printf("\n");          //  Line out
				}

			}
	
		}
	}
	return 0;
}