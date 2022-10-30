#include <stdio.h>

int main(void)
{
	int Matrix[3][3]= {0};
	int Solution[10]= {0};
	int Solution_N;
	int Row_Number, Line_Number;

	printf("Input your equation Number");

	for (Line_Number = 0; Line_Number < 3; Line_Number++)
	{
		
		for (Row_Number = 0; Row_Number < 3; Row_Number++)
		{
			scanf_s("%d", &Matrix[Line_Number][Row_Number]);
		}
	}
	printf("Input your solution of equations");

	for (Solution_N = 0; Solution_N < 3; Solution_N++)
	{
		scanf_s("%d", &Solution);
	}

	for (Line_Number = 0; Line_Number < 3; Line_Number++)
	{
		printf("{");
		for (Row_Number = 0; Row_Number < 3; Row_Number++)
		{
			printf("%5d\t", Matrix[Line_Number][Row_Number]);
		}
		printf("}\n");
	}
	for (Solution_N = 0; Solution_N < 3; Solution_N++)
	{
		printf("%5d", Solution[Solution_N]);
	}


}