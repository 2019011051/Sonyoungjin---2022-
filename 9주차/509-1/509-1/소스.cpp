#include <stdio.h>
#include <stdlib.h>


struct marriage     
{

	//variable declaration
	char name[20];
	char sex;
	int age;
	double height;
};

int main(void)
{
	struct marriage m1 = { "Andy", 'm', 22, 187.5};          //Enter information into variables in a structure
	struct marriage* mp = &m1;
	

	// Output entered information
	printf("name : %s\n", mp->name);                 
	printf("sex : %c\n", mp->sex);
	printf("age : %d\n", mp->age);
	printf("height : %.1If", mp->height);
}