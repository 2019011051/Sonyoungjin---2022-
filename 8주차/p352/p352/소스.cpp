#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[30];           //str배열 선언
     	
	strcpy(str, "wine");

	strcat(str, "apple");

	strncpy(str, "pear", 1);
	
	printf("%s, %d\n",str, strlen(str));
	
	return 0;
}