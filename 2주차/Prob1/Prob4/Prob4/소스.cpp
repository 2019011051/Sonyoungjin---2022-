#include <stdio.h>

int main(void)
{
	int Kg;                   //Specify a weight variable
	double m;                 //Height Specify a variable
	double Bmi;               //Specifying Bmi Variables


	printf("input height and kg : ");                   // Input height and m
	scanf_s("%d%lf", &Kg, &m);
	double Heightm = (Kg * 0.01);
	Bmi = (Kg) / (m * m);                              // Bmi Calculation
	double res = (Bmi >= 20) && (Bmi < 25) ? printf("ǥ��ü���Դϴ�") : printf("ü�߰������ʿ��մϴ�");

	return 0;

}