#include <stdio.h>
#include <stdlib.h>

int sum(int x, int y)
{
	int temp;
	temp = x + y;
	return temp;
}

int sub(int x, int y)
{
	int temp;
	temp = x - y;
	return temp;
}

int division(int x, int y)
{
	int temp;
	temp = x / y;
	return temp;
}

int mult(int x, int y)
{
	int temp;
	temp = x * y;
	return temp;
}


int main(void)
{
	int a, b;
	int res;
	char arithmeticoperations;

	printf("Input your nA, arithmetic operations, nB:");       //Input your information
	scanf_s(" %d%c%d", &a, &arithmeticoperations, 1, &b);
	
	switch (arithmeticoperations)                      // Determine what four-point operations are
	{
	case '+':                                  // in the case of + 
	{
		printf("addition:\n");                   //  show +
		int res = sum(a, b);                       //  + caclulation
		printf("%d%c%d = %d\n", a, arithmeticoperations, b, res);    // show the result  
		break;

	}
	case '-':                                    //in the case of -
	{
		printf("subtaction:\n");                    // show -
		int res = sub(a, b);                          // - caculation
		printf("%d%c%d = %d\n", a, arithmeticoperations, b, res);       // show the result
		break;
	}
	case '/':                                  // in the case of /
	{
		printf("division:\n");                     // show division
		int res = division(a, b);                          //   division caculation
		printf("%d%c%d = %d\n", a, arithmeticoperations, b, res);   // show the result
		break;
	}

	default:                                     // in the cas of *
	{
		printf("multipication:\n");                 // show *
		int res = mult(a, b);                          // multipication *
		printf("%d%c%d = %d\n", a, arithmeticoperations, b, res);   // show the result
		break;
	}

	}

	system("pause");
	return 0;
}