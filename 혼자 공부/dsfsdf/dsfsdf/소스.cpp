#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Books
{
	char title[100];
	char author[100];
	int page;
	int price;
};

int main(void)
{
	struct Books Book_information[3];
	int i;

	for (i = 0; i < 3; i++)
	{
		printf("Enter book %d information: ", i);
		scanf_s("%s%s%d%d\n", (Book_information[i].title), (Book_information[i].author), &(Book_information[i].page), &(Book_information[i].price));
	}
	
	for (i = 0; i < 3; i++)
	{
		printf("Book's title : %s\n", Book_information[i].title);
		printf("Book's author : %s\n", Book_information[i].author);
		printf("Book's page : %d\n", Book_information[i].page);
		printf("Book's price : %d", Book_information[i].price);
	}

	return 0;
}
