#include <stdio.h>
#include <stdlib.h>

#define first_row 0                    
#define second_row 1 
#define third_row 2
#define first_Line 0
#define second_Line 1
#define third_Line 2
#define Number_of_arrays_in_rows 3
#define Number_of_arrays_in_Line 3


int main(void)
{
	int A_Matrix[Number_of_arrays_in_rows][Number_of_arrays_in_Line] = { 0 };        // 2차원배열 변수 선언
	int Solution[Number_of_arrays_in_Line] = { 0 };           // 1차원배열 변수 선언
	int Solution_N;    
	int x, y, z = 0;         // 3차 방정식들의 변수 x,y,z선언
	int Row_Number, Line_Number;
	int det_A_Matrix = 0;              // 2차원배열의 행렬식 값 변수 선언
	int det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_first_column_of_the_matrix_A;  //x값의 크래머공식을 적용한 분자의 행렬식값의 변수 선언
	int det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_second_column_of_the_matrix_A;   // y값의 크래머공식을 적용한 분자의 행렬식값의 변수 선언
	int det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_third_column_of_the_matrix_A;     // z값의 크래머공식을 적용한 분자의 행렬식값의 변수 선언


	printf("Input your equation Number");
	
	//문제에 나온 3개의 방정식들의 숫자들을 3x3행렬로 만들어주는것

	for (Row_Number = 0; Row_Number < Number_of_arrays_in_rows; Row_Number++)
	{

		for (Line_Number = 0; Line_Number < Number_of_arrays_in_Line; Line_Number++)
		{
			scanf_s("%d", &A_Matrix[Row_Number][Line_Number]);
		}
	}
	printf("Input your solution of equations");

	// 각 방정식들의 해들을 1x3행렬로 만들기

	for (Solution_N = 0; Solution_N < Number_of_arrays_in_Line; Solution_N++)
	{

		scanf_s("%d", &Solution[Solution_N]);
	}
	
	// 대입한 값들의 행렬을 출력하기
	printf("Expressing a quadratic equation as a matrix\n");
	for (Row_Number = 0; Row_Number < Number_of_arrays_in_rows; Row_Number++)
	{
		printf("{");
		for (Line_Number = 0; Line_Number < Number_of_arrays_in_Line; Line_Number++)
		{
			printf("%5d\t", A_Matrix[Row_Number][Line_Number]);
		}
		printf("}\n");
	}

	//방정식의 해들을 대입한 행렬을 출력하기
	printf("the solution of each equation\n");
	printf("{");
	for (Solution_N = 0; Solution_N < Number_of_arrays_in_Line; Solution_N++)
	{
		printf("%5d", Solution[Solution_N]);
	}
	printf("}\n");
	
	//구한 행렬식 값 구하는 공식
	det_A_Matrix =
		A_Matrix[first_row][first_Line] * (A_Matrix[second_row][second_Line] * A_Matrix[third_row][third_Line] - A_Matrix[second_row][third_Line] * A_Matrix[third_row][second_Line])
		- A_Matrix[first_row][second_Line] * (A_Matrix[second_row][first_Line] * A_Matrix[third_row][third_Line] - A_Matrix[second_row][third_Line] * A_Matrix[third_row][first_Line])
		+ A_Matrix[first_row][third_Line] * (A_Matrix[second_row][first_Line] * A_Matrix[third_row][second_Line] - A_Matrix[second_row][second_Line] * A_Matrix[third_row][first_Line]);
	printf("Det Matrix : %d\n ", det_A_Matrix);

	// x값의 크래머공식을 적용한 분자의 행렬식값을 구하는 공식
	det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_first_column_of_the_matrix_A =
		Solution[first_Line] * (A_Matrix[second_row][second_Line] * A_Matrix[third_row][third_Line] - A_Matrix[second_row][third_Line] * A_Matrix[third_row][second_Line])
		- A_Matrix[first_row][second_Line] * (Solution[second_Line] * A_Matrix[third_row][third_Line] - A_Matrix[second_row][third_Line] * Solution[third_Line])
		+ A_Matrix[first_row][third_Line] * (Solution[second_Line] * A_Matrix[third_row][second_Line] - A_Matrix[second_row][second_Line] * Solution[third_Line]);

	// 변수 x값을 구하는 공식
	x = det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_first_column_of_the_matrix_A / det_A_Matrix;

	// x값 출력
	printf("x = %d\n", x);

	// y값의 크래머공식을 적용한 분자의 행렬식값을 구하는 공식
	det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_second_column_of_the_matrix_A =
		A_Matrix[first_row][first_Line] * (Solution[second_Line] * A_Matrix[third_row][third_Line] - A_Matrix[second_row][third_Line] * Solution[third_Line])
		- Solution[first_Line] * (A_Matrix[second_row][first_Line] * A_Matrix[third_row][third_Line] - A_Matrix[second_row][third_Line] * A_Matrix[third_row][first_Line])
		+ A_Matrix[first_row][third_Line] * (A_Matrix[second_row][first_Line] * Solution[third_Line] - Solution[second_Line] * A_Matrix[third_row][first_Line]);
	
	// 변수 y값을 구하는 공식
	y = det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_second_column_of_the_matrix_A / det_A_Matrix;

	// y값 출력
	printf("y = %d\n", y);
	
	// z값의 크래머공식을 적용한 분자의 행렬식값을 구하는 공식
	det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_third_column_of_the_matrix_A =
		A_Matrix[first_row][first_Line] * (A_Matrix[second_row][second_Line] * Solution[third_Line] - A_Matrix[third_row][second_Line] * Solution[second_Line])
		- A_Matrix[first_row][second_Line] * (A_Matrix[second_row][first_Line] * Solution[third_Line] - A_Matrix[third_row][first_Line] * Solution[second_Line])
		+ Solution[first_Line] * (A_Matrix[second_row][first_Line] * A_Matrix[third_Line][second_Line] - A_Matrix[second_row][second_Line] * A_Matrix[third_row][first_Line]);

	// 변수 z값을 구하는 공식
	z = det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_third_column_of_the_matrix_A / det_A_Matrix;

	// z값 출력
	printf("z = %d", z);

	return 0;
}