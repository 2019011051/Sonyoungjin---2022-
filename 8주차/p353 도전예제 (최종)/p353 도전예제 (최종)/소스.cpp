#include <stdio.h>
#include <string.h>

#define Max_Limit 20 

int main(void)
{
	//variable declaration
	char str[Max_Limit] = { 0 };
	char str1[Max_Limit] = { 0 };
	char str2[Max_Limit] = { 0 };
	char temp[Max_Limit] = { 0 };

	printf(" 세 단어 입력 : ");
	scanf("%s%s%s", str, str1, str2);           //Enter string in str, str1, str2
	
	
	
	if (strcmp(str, str1) > 0)       //Meaning: If str comes after the dictionary than str1, change the two strings
	{
		strcpy(temp, str);          //Save str to temp
		strcpy(str, str1);          //Save str1 to str
		strcpy(str1, temp);         //Save temp to str1
	}
	else if (strcmp(str, str2) > 0)        //Meaning: If str comes after the dictionary than str2, it replaces the two strings.
	{
		strcpy(temp, str);                  // Save str to temp
	    strcpy(str, str2);                   // Save str2 to str
		strcpy(str2, temp);                   // Save temp to  str1
	}
	else if (strcmp(str1, str2) > 0)          //Meaning: If str1 comes after the dictionary than str2, it replaces the two strings.
	{	
		strcpy(temp, str1);                      //Save str1 to temp
		strcpy(str1, str2);                      //Save str2 to str1
		strcpy(str2, temp);                      //Save temp to str2
	}

	printf("%s, %s, %s", str, str1, str2);        // str, str1, str2 output

	return 0;
}