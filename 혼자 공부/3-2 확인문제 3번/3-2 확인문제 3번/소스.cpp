#include <stdio.h>

int main(void)
{
	char ch=0; 

	printf("input your char: ");
	scanf_s("%c", &ch);
	printf("%c aski code is %d", ch, ch);
	return 0;

}