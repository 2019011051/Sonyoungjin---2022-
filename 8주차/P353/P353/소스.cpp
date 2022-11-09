#include <stdio.h>
#include <string.h>

int main(void)
{
	char fruit1[10]= "0";
	char fruit2[10] = "0";
	char fruit3[10]=  "0";
	

	scanf_s("%s\n", fruit1[10]);
	
	printf("단어입력 : %s\n", fruit1);
	if (strlen(fruit1) > 5)
	{
		strncat_s(fruit1, "*", 1);
	}
	printf("입력한 단어 : %s, 생략한 단어 : %s ", fruit1, fruit1);
	
	return 0;

}