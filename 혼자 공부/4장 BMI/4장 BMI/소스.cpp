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

    res= (bmi >= 20) && (25 > bmi) ? printf("ǥ���Դϴ�.") : printf("ü�߰����� �ʿ��մϴ�.");

 

	
	return 0;
}