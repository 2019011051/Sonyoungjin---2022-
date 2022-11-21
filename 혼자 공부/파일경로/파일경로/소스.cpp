#include <stdio.h>
#include <string.h>


int main(void)
{
	char str1[2000] = "gello nice to meet you";
	char del[100] = " ";
	char* token;
	token = strtok(str1, del);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return 0;

}