#include <stdio.h>

int main(void)
{
	FILE* input_file,*output_file ;
	
	int integer;
	double real_number;
	char character;
	char string[20];
	int res;

	input_file = fopen("a.txt", "r");
	if (input_file == NULL)
	{
		printf("File did not open/\n ");
		return 1;
	}
	
	output_file = fopen("b.txt", "w");
	if (input_file == NULL)
	{
		printf("File did not open/\n ");
		return 1;
	}

	while (1)
	{
		res = fscanf(input_file, "%5d %7.If %c %s", &integer, &real_number, &character, string);
		if (res == EOF)
		{
			break;
		}
		fprintf(output_file, "%5d %7.If %c %s\n", integer, real_number, character, string);

	}
	
	fclose(input_file);
	fclose(output_file);

	return 0;
}