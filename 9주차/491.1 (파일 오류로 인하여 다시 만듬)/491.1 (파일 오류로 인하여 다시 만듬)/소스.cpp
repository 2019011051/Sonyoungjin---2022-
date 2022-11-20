#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Limit 50
#define Array_Limit 3
#define Zero 0

void Remove_Buffer(void);


//Structure for storing information in books
typedef struct book_information
{
	char title[Limit];
	char author[Limit];
	int page;
	int price;
};


int main(void)
{
	book_information book[Array_Limit];       //Declare structures as arrays
	int i;     //variable declaration
	
	printf("input your book information\n");


	//Enter the information of the three books I have obtained and save them in an array of structures
	for (i = Zero; i < Array_Limit; i++)
	{
		putchar('\n');

		fputs("title : ", stdout);                            //Use the fgets function to store spaces in a string
		fgets(book[i].title, sizeof(book[i].title), stdin);    //Use fgets function to output string
		
		fputs("author : ", stdout);
		fgets(book[i].author, sizeof(book[i].author), stdin);
		
		fputs("page : ", stdout);
		scanf_s("%d", &book[i].page);
		
		fputs("price : ", stdout);
		scanf_s("%d", &book[i].price);

		Remove_Buffer();           //Call clearBuffer to remove the remaining entries in the input buffer
	}

	printf("output your book information\n");


	//
	for (i = Zero; i < Array_Limit; i++)
	{
		putchar('\n');


		//When the user enters fputs, the enter is included in the string You don't have to change the line

		printf("\nbook%d\n", i+1);

		printf("Book's title : %s", book[i].title);
		printf("Book's author : %s", book[i].author);
		printf("Book's page : %d\n", book[i].page);     //Line replacement is required when a string ends and outputs another integer
		printf("Book's price : %d", book[i].price);
	}


	return 0;
}

void Remove_Buffer(void)
{
	while (getchar() != '\n');         //Take advantage of the principle that simply uses it and becomes empty if you don't save it
}