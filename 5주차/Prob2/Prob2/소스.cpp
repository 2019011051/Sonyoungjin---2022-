#include <stdio.h>

int main(void)
{
	int i;
	int n;
	int k;
	int cnt = 0;

	printf("Enter an integer greater than or equal to 2 : ");
	scanf_s("%d", &k);
	
	for (i = 2; i <=k; i++)
	{
		for (n = 2; n <=i; n++)
		{
			if (i%n==0)
			{
				if (i>n) break;

				else
				{
					printf("%5d", i);
					cnt++;
					if(cnt % 5 == 0)
					printf("\n");
				}

			}
	
		}
	}
	return 0;
}