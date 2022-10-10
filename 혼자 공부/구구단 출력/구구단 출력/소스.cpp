#include <stdio.h>

int main(void)
{
	int i, j;
	int res;

	for (i = 2; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			res = i * j;
			printf("%d*%d=%d\n", i, j, res);
		}
	}
	return 0;
}