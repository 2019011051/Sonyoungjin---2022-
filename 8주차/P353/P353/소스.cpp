#include <stdio.h>
#include <string.h>

int main(void)
{
	char fruit1[10]= "0";
	char fruit2[10] = "0";
	char fruit3[10]=  "0";
	

	scanf_s("%s\n", fruit1[10]);
	
	printf("�ܾ��Է� : %s\n", fruit1);
	if (strlen(fruit1) > 5)
	{
		strncat_s(fruit1, "*", 1);
	}
	printf("�Է��� �ܾ� : %s, ������ �ܾ� : %s ", fruit1, fruit1);
	
	return 0;

}