#include <stdio.h>
#include <stdlib.h>


struct marriage
{
	char name[20];
	char sex;
	int age;
	double height;
};

int main(void)
{
	struct marriage m1 = { "Andy", 'm', 22, 187.5};
	struct marriage* mp = &m1;

	printf("name : %s\n", mp->name);
	printf("sex : %c\n", mp->sex);
	printf("age : %d\n", mp->age);
	printf("height : %.1If", mp->height);
}