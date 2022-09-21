#include <stdio.h>

int main(void)
{
	char ch;                                        // To store character

	printf("Character Input\n");                    // Input Informaation Massage
	scanf_s("%c", &ch);                             // Enter characters in variable ch
	printf("Your Input To The Ascii Code%d\n", ch); // Convert and output
	return 0;

}