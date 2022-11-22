#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{

	FILE* oufile;

	int integer;
	double real_number;
	char character;
	char string[20];
	int res;
	
	
	output_file = fopen("b.txt", "w");
	if (output_file == NULL)
	{
		printf("File did not open/\n ");
		return 1;
	}

	while (1)
	{
		res = fscanf(output_file, "%5d %7.If %5c %5s", &integer, &real_number, &character, string);
		if (res == EOF)
		{
			break;
		}
		fprintf(output_file, "%5d %7.If %5c %5s", integer, real_number, character, string);
	}
	
	
	fclose(output_file);

	return 0;
}