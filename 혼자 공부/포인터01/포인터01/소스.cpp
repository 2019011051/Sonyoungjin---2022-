#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 15;
	int total;
    double avg;



	int* pa, * pb;
	int* pt = &total;
	double* pavg = &avg;

	pa = &a;
	pb = &b;

	*pt = *pa + *pb;
	*pavg = *pt /2.0;

	printf("�������� �� : %d %d\n", *pa, *pb);
	printf("�������� �� : %d\n", *pt);
	printf("�������� ��� : %.1If", *pavg);

	return 0;
}