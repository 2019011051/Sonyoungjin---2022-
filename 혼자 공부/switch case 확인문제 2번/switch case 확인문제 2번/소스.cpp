#include <stdio.h>

int main(void)
{
	int n;
	printf("Input your n : ");
	scanf_s("%d", &n);
	
	switch (n % 3)
	{
	case  0:
		printf("°ÅÁş");
		break;

	default :
		printf("Âü");
		break;

	}
	return 0;

}