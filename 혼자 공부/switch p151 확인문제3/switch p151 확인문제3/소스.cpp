#include <stdio.h>
#include <stdlib.h>

#define LIMITAGE 20
#define MINISIZE 85
#define MAXSIZE 95
#define ADULTMINI 90
#define ADULTMAX 100

int main(void)
{
	int age, chest;
	char chestsize;

	printf("Input your age and chest :");
	scanf_s("%d %d", &age, &chest);

	  if (age < LIMITAGE)
	  {
		if (chest < MINISIZE)
		{
			chestsize = 'S';

		}
		else if ((chest >= MINISIZE) && (MAXSIZE > chest))
		{
			chestsize = 'M';
		}
		else
		{
			chestsize = 'L';
		}
	  }
	  else
	  {
		 if (chest < ADULTMINI)
		 {
			chestsize = 'S';
		 }
		
		 else if ((chest >= ADULTMINI) && (ADULTMAX > chest))
		 {
			chestsize = 'M';
		 }
		
		 else
		 {
			chestsize = 'L';
		 }
		
	  }
	  printf("Your chestsize is %c.", chestsize);
	  system("pause");
	  return 0;
    
}