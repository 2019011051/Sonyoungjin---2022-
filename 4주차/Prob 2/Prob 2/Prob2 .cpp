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
	
	printf("input your age and chest:");       //  input age and chestsize
	scanf_s("%d %d", &age, &chest);                

	if (age < agelimit )                             //If you're under 20
	{                                                //// Size is determined according to the chest value under the age of 20
		if (chest < MINSIZE)                    
		{
			chestsize = 'S';                        
		}

		else if ((chest >= MINSIZE) && (chest < MAXSIZE))  
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
		if (chest < ADULTMINSIZE)
		{
			chestsize = 'S';
		}
		else if ((chest >= ADULTMINSIZE) && (chest < ADULTMAXSIZE))
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
