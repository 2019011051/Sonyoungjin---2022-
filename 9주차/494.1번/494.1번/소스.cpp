#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Book
{
	char title[50];
	char author[50];
	int page;
	int price;
};

int main(void)
{
	struct Book hongongC;

	strcpy_s(hongongC.title, "hongong");
	strcpy_s(hongongC.author, "seo hyunwoo");
	hongongC.page = 664;
	hongongC.price = 24000;

	printf("title  : %s\n", hongongC.title);
	printf("author : %s\n", hongongC.author);
	printf("page  : %d\n", hongongC.page);
	printf("price  : %d\n", hongongC.price);


	return 0;
}