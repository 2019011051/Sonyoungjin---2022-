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
	int A_Matrix[Number_of_arrays_in_rows][Number_of_arrays_in_Line] = { 0 };        // 2�����迭 ���� ����
	int Solution[Number_of_arrays_in_Line] = { 0 };           // 1�����迭 ���� ����
	int Solution_N;    
	int x, y, z = 0;         // 3�� �����ĵ��� ���� x,y,z����
	int Row_Number, Line_Number;
	int det_A_Matrix = 0;              // 2�����迭�� ��Ľ� �� ���� ����
	int det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_first_column_of_the_matrix_A;  //x���� ũ���Ӱ����� ������ ������ ��Ľİ��� ���� ����
	int det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_second_column_of_the_matrix_A;   // y���� ũ���Ӱ����� ������ ������ ��Ľİ��� ���� ����
	int det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_third_column_of_the_matrix_A;     // z���� ũ���Ӱ����� ������ ������ ��Ľİ��� ���� ����


	printf("Input your equation Number");
	
	//������ ���� 3���� �����ĵ��� ���ڵ��� 3x3��ķ� ������ִ°�

	for (Row_Number = 0; Row_Number < Number_of_arrays_in_rows; Row_Number++)
	{

		for (Line_Number = 0; Line_Number < Number_of_arrays_in_Line; Line_Number++)
		{
			scanf_s("%d", &A_Matrix[Row_Number][Line_Number]);
		}
	}
	printf("Input your solution of equations");

	// �� �����ĵ��� �ص��� 1x3��ķ� �����

	for (Solution_N = 0; Solution_N < Number_of_arrays_in_Line; Solution_N++)
	{

		scanf_s("%d", &Solution[Solution_N]);
	}
	
	// ������ ������ ����� ����ϱ�
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

	//�������� �ص��� ������ ����� ����ϱ�
	printf("the solution of each equation\n");
	printf("{");
	for (Solution_N = 0; Solution_N < Number_of_arrays_in_Line; Solution_N++)
	{
		printf("%5d", Solution[Solution_N]);
	}
	printf("}\n");
	
	//���� ��Ľ� �� ���ϴ� ����
	det_A_Matrix =
		A_Matrix[first_row][first_Line] * (A_Matrix[second_row][second_Line] * A_Matrix[third_row][third_Line] - A_Matrix[second_row][third_Line] * A_Matrix[third_row][second_Line])
		- A_Matrix[first_row][second_Line] * (A_Matrix[second_row][first_Line] * A_Matrix[third_row][third_Line] - A_Matrix[second_row][third_Line] * A_Matrix[third_row][first_Line])
		+ A_Matrix[first_row][third_Line] * (A_Matrix[second_row][first_Line] * A_Matrix[third_row][second_Line] - A_Matrix[second_row][second_Line] * A_Matrix[third_row][first_Line]);
	printf("Det Matrix : %d\n ", det_A_Matrix);

	// x���� ũ���Ӱ����� ������ ������ ��Ľİ��� ���ϴ� ����
	det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_first_column_of_the_matrix_A =
		Solution[first_Line] * (A_Matrix[second_row][second_Line] * A_Matrix[third_row][third_Line] - A_Matrix[second_row][third_Line] * A_Matrix[third_row][second_Line])
		- A_Matrix[first_row][second_Line] * (Solution[second_Line] * A_Matrix[third_row][third_Line] - A_Matrix[second_row][third_Line] * Solution[third_Line])
		+ A_Matrix[first_row][third_Line] * (Solution[second_Line] * A_Matrix[third_row][second_Line] - A_Matrix[second_row][second_Line] * Solution[third_Line]);

	// ���� x���� ���ϴ� ����
	x = det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_first_column_of_the_matrix_A / det_A_Matrix;

	// x�� ���
	printf("x = %d\n", x);

	// y���� ũ���Ӱ����� ������ ������ ��Ľİ��� ���ϴ� ����
	det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_second_column_of_the_matrix_A =
		A_Matrix[first_row][first_Line] * (Solution[second_Line] * A_Matrix[third_row][third_Line] - A_Matrix[second_row][third_Line] * Solution[third_Line])
		- Solution[first_Line] * (A_Matrix[second_row][first_Line] * A_Matrix[third_row][third_Line] - A_Matrix[second_row][third_Line] * A_Matrix[third_row][first_Line])
		+ A_Matrix[first_row][third_Line] * (A_Matrix[second_row][first_Line] * Solution[third_Line] - Solution[second_Line] * A_Matrix[third_row][first_Line]);
	
	// ���� y���� ���ϴ� ����
	y = det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_second_column_of_the_matrix_A / det_A_Matrix;

	// y�� ���
	printf("y = %d\n", y);
	
	// z���� ũ���Ӱ����� ������ ������ ��Ľİ��� ���ϴ� ����
	det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_third_column_of_the_matrix_A =
		A_Matrix[first_row][first_Line] * (A_Matrix[second_row][second_Line] * Solution[third_Line] - A_Matrix[third_row][second_Line] * Solution[second_Line])
		- A_Matrix[first_row][second_Line] * (A_Matrix[second_row][first_Line] * Solution[third_Line] - A_Matrix[third_row][first_Line] * Solution[second_Line])
		+ Solution[first_Line] * (A_Matrix[second_row][first_Line] * A_Matrix[third_Line][second_Line] - A_Matrix[second_row][second_Line] * A_Matrix[third_row][first_Line]);

	// ���� z���� ���ϴ� ����
	z = det_The_value_of_the_matrix_of_the_solutions_of_each_equation_substituted_in_the_third_column_of_the_matrix_A / det_A_Matrix;

	// z�� ���
	printf("z = %d", z);

	return 0;
}