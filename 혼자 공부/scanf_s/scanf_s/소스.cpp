#include <stdio.h>

int main(void)
{
	int age;
	double height;

	printf("Input your age, height : ");
	scanf_s("%d%if", &age, &height);
	printf("age is %d, height is %if\n", age, height);
	
	return 0;
}