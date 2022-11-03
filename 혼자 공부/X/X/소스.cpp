#include <stdio.h>
#include <stdlib.h>

#define first_row 0
#define second_row 1 
#define third_row 2
#define first_Line 0
#define second_Line 1
#define third_Line 2



int main(void)
{
	int A_Matrix[3][3] = { 0 };
	int Solution[3] = { 0 };
	int Solution_N;
	int Row_Number, Line_Number;
	int det_A_Matrix = 0;
	int The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_first_column_of_the_matrix_A;
	int The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_second_column_of_the_matrix_A;
	int The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_third_column_of_the_matrix_A;
	int x, y, z = 0;

	printf("Input your equation Number");

	for (Row_Number = 0; Row_Number < 3; Row_Number++)
	{

		for (Line_Number = 0; Line_Number < 3; Line_Number++)
		{
			scanf_s("%d", &A_Matrix[Row_Number][Line_Number]);
		}
	}
	printf("Input your solution of equations");

	for (Solution_N = 0; Solution_N < 3; Solution_N++)
	{

		scanf_s("%d", &Solution[Solution_N]);
	}

	printf("Expressing a quadratic equation as a matrix\n");

	for (Row_Number = 0; Row_Number < 3; Row_Number++)
	{
		printf("{");
		for (Line_Number = 0; Line_Number < 3; Line_Number++)
		{
			printf("%5d\t", A_Matrix[Row_Number][Line_Number]);
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

	det_A_Matrix =
		A_Matrix[first_row][first_Line] * (A_Matrix[second_row][second_Line] * A_Matrix[third_row][third_Line] - A_Matrix[second_row][third_Line] * A_Matrix[third_row][second_Line])
		- A_Matrix[first_row][second_Line] * (A_Matrix[second_row][first_Line] * A_Matrix[third_row][third_Line] - A_Matrix[second_row][third_Line] * A_Matrix[third_row][first_Line])
		+ A_Matrix[first_row][third_Line] * (A_Matrix[second_row][first_Line] * A_Matrix[third_row][second_Line] - A_Matrix[second_row][second_Line] * A_Matrix[third_row][first_Line]);
	printf("Det Matrix : %d\n ", det_A_Matrix);

	The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_first_column_of_the_matrix_A =
		Solution[first_Line] * (A_Matrix[second_row][second_Line] * A_Matrix[third_row][third_Line] - A_Matrix[second_row][third_Line] * A_Matrix[third_row][second_Line])
		- Solution[second_Line] * (Solution[second_Line] * A_Matrix[third_row][third_Line] - A_Matrix[second_row][third_Line] * Solution[third_Line])
		+ Solution[third_Line] * (Solution[second_Line] * A_Matrix[third_row][second_Line] - A_Matrix[second_row][second_Line] * Solution[third_Line]);

	x = The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_first_column_of_the_matrix_A / det_A_Matrix;
	printf("%d\n", x);
	printf("x = %d", x);

}