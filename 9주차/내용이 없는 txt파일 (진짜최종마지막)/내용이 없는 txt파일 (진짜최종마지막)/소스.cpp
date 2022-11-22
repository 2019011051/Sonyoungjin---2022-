#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

	FILE* file;       //File Pointer Declaration

	//Declare variation
	int integer = 1;     
	double real_number = 1.2;
	char character = 'a';
	char string[20] = { "Hi" };

	fopen_s(&file, "b.txt", "w");       //The code that generates the file

	if (file == NULL)                 //Check if it is open
	{
		printf("File did not open/\n ");
		return 1;
	}
	
	printf("%d\n%.1If\n %c\n %s", integer, real_number, character, string);        //Output to Console
	fprintf(file, "%d\n%.1If\n %c\n %s", integer, real_number, character, string);   //Output to the file you created


	fclose(file);       //Close File

	return 0;
}