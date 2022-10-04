#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 20;
	int c = 10;
	int res = 0;

	res = (a > b);
	printf(" a > b : %d\n", res);
	res = (a >= b);
	printf("a>=b : %d\n", res);
	res = (a < b);
	printf("a < b : %d\n", res);
	res = (a == b);
	printf("a==b : %d\n", res);

	return 0;

}