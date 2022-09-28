#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int nA, nB, res;                               // Set three variables
	char arithmeticoperations;                //Set four-factor operation variable

	printf("Input your nA, arithmetic operations, nB:");       //Input your information
	scanf_s(" %d%c%d", &nA, &arithmeticoperations, 1, &nB);     // scan enter A, operation, B

	 
	switch (arithmeticoperations)                      // Determine what four-point operations are
	{
	        case '+':                                  // in the case of + 
	        {	
			 printf("addition:\n");                   //  show +
	         int res = nA + nB;                       //  + caclulation
	         printf("%d%c%d = %d\n", nA, arithmeticoperations, nB, res);    // show the result  
	         break;

	        }
	        case '-':                                    //in the case of -
	        {
		     printf("subtaction:\n");                    // show -
		     int res = nA - nB;                          // - caculation
		     printf("%d%c%d = %d\n", nA, arithmeticoperations, nB, res);       // show the result
		     break;
	        }
	        case '/':                                  // in the case of /
	        {
		     printf("division:\n");                     // show division
		     int res = nA / nB;                          //   division caculation
		     printf("%d%c%d = %d\n", nA, arithmeticoperations, nB, res);   // show the result
			 break;
			}

	        default:                                     // in the cas of *
	        {
		     printf("multipication:\n");                 // show *
		     int res = nA * nB;                          // multipication *
		     printf("%d%c%d = %d\n", nA, arithmeticoperations, nB, res);   // show the result
		     break;
	        }

	}


	system("pause"); 
	return 0;
}

