#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{

	FILE* file;

	int integer = 1;
	double real_number = 1.2;
	char character = 'a';
	char string[20] = { "Hi" };
	
	fopen_s(&file, "b.txt", "w");

	if (file == NULL)
	{
		printf("File did not open/\n ");
		return 1;
	}

	fprintf(file, "%d %If %c %s", integer, real_number, character, string);

	
	
	fclose(file);

	return 0;
}