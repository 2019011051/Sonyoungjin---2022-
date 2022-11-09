#include <stdio.h>

void input_data(int* pa, int* pb);  //Declare functions of input data
void swap_data(void);               //Declare a function that changes the data
void print_data(int a, int b);          //Declare data output function

int a, b;           // variation declare

int main(void) 
{ 
	input_data(&a, &b);      //Enter an integer value in a global variable
	swap_data();               //Exchange two variables
	print_data(a, b);             // Output exchanged variable values

	return 0;
}

void input_data(int* pa, int* pb)       
{
	*pa = 10;                       // The value of pointer a is 10
	*pb = 20;                        // The value of pointer b is 20
	printf("두 정수 입력 : %d %d\n", a, b);
}

void swap_data(void)
{
	int temp;                 // temp varation declare
	temp = a;                 // Save value a in temp
	a = b;                     // Save value b in a
	b = temp;                  // Save value temp in b
}

void print_data(int a, int b)
{
	printf("두 정수 출력 : %d %d", a, b);     // Output of variable a,b values
}