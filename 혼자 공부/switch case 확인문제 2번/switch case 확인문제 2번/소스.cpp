#include <stdio.h>

int main(void)
{
	int n;
	printf("Input your n : ");
	scanf_s("%d", &n);
	
	switch (n % 3)
	{
	case  0:
		printf("����");
		break;

	default :
		printf("��");
		break;

	}
	return 0;

}