#include <stdio.h>

int main(void)
{
	char grade;
	char name[20];

	printf("Input your grade : ");
	scanf_s("%c", &grade);
	printf("Input your name : ");
	scanf_s("%s", name);
	printf("%s grade is %c\n", name, grade);


	
	return 0;

}