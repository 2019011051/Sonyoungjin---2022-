#include <stdio.h>

int main(void)
{
	int a, b;
	int res;
	char symbol;

	printf("Input your four-factor operation :");
	scanf_s("%d %c %d", &a, &symbol, 1, &b);

	switch (symbol)
	{
		case '+' :
		{
			int res = a + b;
			printf(" %d %c %d = %d", a, symbol, b, res);
			break;
		}
		case '-' : 
		{
			int res = a - b;
			printf(" %d %c %d = %d", a, symbol, b, res);
			break;
		}
		case '*':
		{
			int res = a * b;
			printf(" %d %c %d = %d", a, symbol, b, res);
			break;
		}
		default : 
		{
			int res = a / b;
			printf(" %d %c %d = %d", a, symbol, b, res);
			break;
		}
	
		
	}
	return 0;


}