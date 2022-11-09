#include <stdio.h>
#include <string.h>

// Add-in function by pointer
void add_by_pointer(int* pa, int* pb, int* pr)
{
	*pr = *pa + *pb;
}

int main(void)
{
	int a = 10;  //variation declartion
	int b = 20;
	int res = 0;
	
	add_by_pointer(&a, &b, &res); //Give the addresses of a, b, and res as arguments for the function.
	printf("%d", res);            //output of res value
	return 0;
}