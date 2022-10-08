#include <stdio.h>

#define LIMITCM 187.5
#define LIMITKG 80.0


int main(void)
{
	double cm=0;
	double kg=0;

	if ((cm >= LIMITCM) && ( kg < LIMITKG))
	{
		printf("OK\n");
	}
	else
	{
		printf("CANCEL\n");
	}
	return 0;
		
}