#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int A_Matrix[3][3]= {0};
	int Solution[3]= {0};
	int Solution_N;
	int Row_Number, Line_Number;
	int det_A_Matrix=0;
	int The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_first_column_of_the_matrix_A;
	int The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_second_column_of_the_matrix_A;
	int The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_third_column_of_the_matrix_A;
	int x,y,z = 0;

	printf("Input your equation Number");

	for (Line_Number = 0; Line_Number < 3; Line_Number++)
	{
		
		for (Row_Number = 0; Row_Number < 3; Row_Number++)
		{
			scanf_s("%d", &A_Matrix[Line_Number][Row_Number]);
		}
	}
	printf("Input your solution of equations");

	for (Solution_N = 0; Solution_N < 3; Solution_N++)
	{
	
		scanf_s("%d", &Solution[Solution_N]);
	}

	printf("Expressing a quadratic equation as a matrix\n");

	for (Line_Number = 0; Line_Number < 3; Line_Number++)
	{
		printf("{");
		for (Row_Number = 0; Row_Number < 3; Row_Number++)
		{
			printf("%5d\t", A_Matrix[Line_Number][Row_Number]);
		}
		printf("}\n");
	}	
	
	printf("the solution of each equation\n");
	printf("{");
	for (Solution_N = 0; Solution_N < 3; Solution_N++)
	{
		printf("%5d", Solution[Solution_N]);
	}
	printf("}\n");

	det_A_Matrix = A_Matrix[0][0] * (A_Matrix[1][1] * A_Matrix[2][2] - A_Matrix[1][2] * A_Matrix[2][1])
	printf("Det Matrix : %d ", det_A_Matrix); 
		- A_Matrix[0][1] * (A_Matrix[1][0] * A_Matrix[2][2] - A_Matrix[1][2] * A_Matrix[2][0]) + A_Matrix[0][2] * (A_Matrix[1][0] * A_Matrix[2][1] - A_Matrix[1][1] * A_Matrix[2][0]);

}