#include <stdio.h>
#include <string.h>

int main(void)
{
	char fruit[80]={0};
	char res_fruit[80];
	char star[20] = "*******";
	int len=0;
	
	printf("�ܾ��Է� : ");
	scanf("%s", fruit);
	
	len = strlen(fruit);
	if (len<= 5)
	{
		strcpy(res_fruit, fruit);
	}
	else
	{
		strncpy(res_fruit, fruit, 5);
		res_fruit[5]= '\0';
		strncat(res_fruit, star, len - 5);
	}
	printf("�Է��� �ܾ� : %s, ������ �ܾ� : %s\n", fruit, res_fruit);
	
	return 0;

}