#include <stdio.h>
#include <stdlib.h>

typedef enum { CYAN, MAGENTA, YELLOW = 5, BLACK} COLOR;   // Enumeration Declaration
typedef enum { UP, DOWN, LEFT, RIGHT} ARROW;             //Enumeration Declaration

int main(void)
{

	// variable declaration
	int c;   
	int direction = UP;

	COLOR my_color = YELLOW;       //Enumeration variable declaration
	
	

	for (c = CYAN; c <= BLACK; c++)    //Repeat 7 times from 0 to 6
	{
		direction++;                 //direction 1 increase
		direction = direction % 4;     //The direction is rotated to 1,2,3,0,1,2,3
		if (c == my_color)break;         //End repeat at 5 because my_color is yellow
	}
	
	switch (direction)   //Determining Enumeration Members
	{
	case UP: printf("Current direction: Above"); break;     //"Current direction: Above" output when up
	case DOWN: printf("Current Direction: Down"); break;     //"Current direction: Down" output when down
	case LEFT: printf("Current Direction: left"); break;      //"Current direction: left" output when left
	case RIGHT: printf("Current Direction: right"); break;    //"Current direction: right" output when right
	}
	
	return 0;
}