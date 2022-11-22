#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{

	FILE* file = fopen("a.txt", "w");;
	fprintf(file, "%s\n", "Hello world");
	fclose(file);

	return 0;
}