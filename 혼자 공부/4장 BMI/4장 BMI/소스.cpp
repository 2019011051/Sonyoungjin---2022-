#include <stdio.h>

int main(void)
{
	double cm=0;
	double m=0;
    int kg = 0;
	double bmi;
	double res = 0;

	m = cm / 100;
	bmi = kg / (m * m);
	
	printf("Input your kg and cm : ");
	scanf_s("%d%lf", &kg, &cm);

    res= (bmi >= 20) && (25 > bmi) ? printf("표준입니다.") : printf("체중관리가 필요합니다.");

 

	
	return 0;
}