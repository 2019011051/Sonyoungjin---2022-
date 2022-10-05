#include <stdio.h>

int rec_function(int n);

int main(void)
{
	int total;                  // Specify Total Variables
	int a;                      // Specify the variable for rec_function(n+1)
	total = rec_function(1);    // Give 1 as an argument because it is the first time to call.
	printf("%d\n", total);      //Total Output
	return 0;
}
int rec_function(int n)         //Store call count in parameters
{
	if (n == 10) return 10;      // If the number of calls is 10, the recursive call ends
	int a = rec_function(n+1);   // Store a value in variable a that increases the number of calls by 1 when re-calling
	int total = a + n;           //When the number of re-calls reaches 10, the calculation is made and the recursive call is completed.
}
	