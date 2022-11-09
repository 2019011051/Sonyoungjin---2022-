#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[30];
	char str1[5]= {0};
	
	strcpy_s(str, "ine");

	strcat_s(str, "apple");

	strncpy_s(str1, "pear", 1);
	
	printf("%s%s, %d\n",str1, str, strlen(str1));
	
	return 0;
}