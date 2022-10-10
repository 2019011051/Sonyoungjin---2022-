#include <stdio.h>

int main(void)
{
	int i, n;
	int res;
	int count = 0;

	printf("Input your imformation : ");
	scanf_s("%d", &i);

	for (i = 2; i <= 100; i++)
	{
		for (n = 2; n <= i; n++)
		{
			if (i % n == 0)
			{
				if (i > n)break;

				else
				{
					printf("%5d", i);
					count++;
					if (count % 5 == 0)
						printf("\n");
				}

			}
		}

	}
	return 0;
}
