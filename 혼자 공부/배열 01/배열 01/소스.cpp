#include <stdio.h>

int main(void)

{
	int score[5];
	int i;
	int total = 0;
	double avg = 0;

	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &score[i]);
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d\t", score[i]);
	}

	return 0;

}