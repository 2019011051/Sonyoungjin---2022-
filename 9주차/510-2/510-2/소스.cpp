#include <stdio.h>
#include <stdlib.h>

typedef struct train Train;    //Overriding the sentence

struct train           //Declaration of Structure
{
	int seats;
	Train* next;
};

int main(void)
{
	Train* head = NULL, * tail = NULL;      //Head Pointer Initialization
	int i;
	for (i = 0; i < 5; i++)                     
	{
		if (head == NULL)
		{
			head = tail = (Train*)malloc(sizeof(Train));  
		}
		else
		{
			tail -> next = (Train*)malloc(sizeof(Train));
			tail = tail -> next;
		}
	}
	return 0;
}