#include <stdio.h>
#include <stdlib.h>

typedef struct train Train;    //Overriding the sentence

struct train           //Declaration of Structure
{
	int seats;
	Train* next;               //Can be used as a train because you have overridden the structure train first
};

int main(void)
{
	Train* head = NULL, * tail = NULL;      //Head Pointer Initialization
	int i;
	for (i = 0; i < 5; i++)                     
	{
		if (head == NULL)
		{
			head = tail = (Train*)malloc(sizeof(Train));    //After connecting the new structural variables,
		}
		else
		{
			tail -> next = (Train*)malloc(sizeof(Train));      //The tail pointer always remembers the last position in the association list
			tail = tail -> next;               //Change the value of tail to the last position.
		}
	}
	return 0;
}