#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[80];
	strcpy_s(str, "wine");
	strcat_s(str, "apple");
	strncpy_s(str, "pear", 1);
	printf("%s, %d\n", str, strlen(str));
	
	return 0;
}