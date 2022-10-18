#include <stdio.h>
#include <string.h>

int PIN_Program(void);

int main(void)
{
	PIN_Program();
	
	return 0;
}

int PIN_Program(void)
{
	const char C_Password[10]= "7042";
	char M_Password[10]= {0};

	
	while(1)
	{
		printf("Input your Password : ");
		scanf_s("%s", M_Password, 10);
		
		if (strcmp(C_Password, M_Password) == 0)break;
		
		else
		{
			printf("not matched, retry...\n");
		}
		
	}
	printf("normal termination");
 return 0;
}