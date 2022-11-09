#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[20] = { 0 };
	char str1[20] = { 0 };
	char str2[20] = { 0 };
	char temp[20] = { 0 };

	printf(" 세 단어 입력 : ");
	scanf("%s%s%s", str, str1, str2);

	if (strcmp(str, str1) > 0)
	{
		strcpy(temp, str);
		strcpy(str, str1);
		strcpy(str1, temp);
	}
	else if (strcmp(str, str2) > 0)
	{
		strcpy(temp, str);
		strcpy(str, str2);
		strcpy(str2, temp);
	}
	else if (strcmp(str1, str2) > 0)
	{
		strcpy(temp, str1);
		strcpy(str1, str2);
		strcpy(str2, temp);
	}

	printf("%s, %s, %s", str, str1, str2);

	return 0;
}