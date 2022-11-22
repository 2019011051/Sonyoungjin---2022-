#include <stdio.h>
#include <string.h>

struct cracker                  // Declaration of Structure
{

	//variable declaration
	int price;                
	int calories;
};

int main(void)
{
	struct cracker crunchy;     //Declare structural variables
	printf("Enter the price and heat of the crunch :\n ");
	scanf_s("%d%d", &(crunchy.price), &(crunchy.calories));   //Enter a value in a member

	printf(" the price of crunch: %d\n", crunchy.price);       //Output input value
	printf(" the amount of calories that are crunchy : %dkcal", crunchy.calories);

	return 0;

}