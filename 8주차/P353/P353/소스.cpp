#include <stdio.h>
#include <string.h>

int main(void)
{
	//variation declare
	char fruit[80]={0};        
	char res_fruit[80];
	char star[80] = "*******";
	int len=0;
	
	printf("단어입력 : ");
	scanf("%s", fruit);               // Enter information to enter the fruit array
	
	len = strlen(fruit);             //Store the length value of the fruit array in len

	if (len<= 5)                    // If len is less than or equal to 5,
	{
		strcpy(res_fruit, fruit);          // Save fruit in res_fruit
	}
	else  
	{
		strncpy(res_fruit, fruit, 5);               //Copy only 5 characters from fruit and save to res_fruit
		res_fruit[5]= '\0';                             //res_fruit Save your text in the rest
		strncat(res_fruit, star, len - 5);               //Fill the string with stars as long as the length of a string
	} 
	printf("입력한 단어 : %s, 생략한 단어 : %s\n", fruit, res_fruit);      
	
	return 0;

}