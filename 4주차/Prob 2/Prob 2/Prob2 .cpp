#include <stdio.h>
#include <stdlib.h>

#define MINSIZE 85                                // 85 definition
#define MAXSIZE 95                               // 95 definition
#define ADULTMINSIZE 90                           // 90 definition
#define ADULTMAXSIZE 100                          // 100 definition
#define agelimit 20                               // 20 definition

int main(void)
{
	int age;                                          // age variable settings
	int chest;                                       // chest variable settings
	char chestsize;                                  // chestsize variable settings
	
	printf("input your age and chestsize:\n");       //  input age and chestsize
	scanf_s("%d%d", &age, &chestsize);                

	if (age < agelimit )                             //If you're under 20
	{                                                //// Size is determined according to the chest value under the age of 20
		if (chestsize < MINSIZE)                    
		{
			chestsize = 'S';                        
		}

		else if ((chestsize >= MINSIZE) && (chestsize < MAXSIZE))  
		{
			chestsize = 'M';
		}
		else
		{
			chestsize = 'L';
		}
	}
	else                                                 // If you are older than or equal to 20
	{                                                    // Size is determined according to the value of chest over 20 years old
		if (chestsize < ADULTMINSIZE)
		{
			chestsize = 'S';
		}
		else if ((chestsize >= ADULTMINSIZE) && (chestsize < ADULTMAXSIZE))
		{
			chestsize = 'M';
		}

		else
		{
			chestsize = 'L';
		}
	}

	printf("Your chestsize is %c", chestsize);                  // input chestsize
	system("pause");
	
	return 0;

}
