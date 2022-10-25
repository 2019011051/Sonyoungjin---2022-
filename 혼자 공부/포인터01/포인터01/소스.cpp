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

	printf("두정수의 값 : %d %d\n", *pa, *pb);
	printf("두정수의 합 : %d\n", *pt);
	printf("두정수의 평균 : %.1If", *pavg);

	return 0;
}