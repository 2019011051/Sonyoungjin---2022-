#include <stdio.h>
#include <string.h>

#define Limit 30

int main(void)
{
    char str[Limit];           //declaration of str array
     	
	strcpy(str, "wine");          //Copy "wine" to str array

	strcat(str, "apple");          //Attach apple to str

	strncpy(str, "pear", 1);        // Copy only one character from pear
	
	printf("%s, %d\n",str, strlen(str));     
	
	return 0;
}