#include <stdio.h>

int main(void)
{
	int Kor = 3;                            // Kor credits
	int Eng = 5;                            // Eng credits
	int Mat = 4;                            // Mat credits
	int Credits = (Kor + Eng + Mat);        // Add all credits



	double Korscore = 3.8;                  // Koresore grade
	double Engscore = 4.4;                  // English grade
	double Matscore = 3.9;                  // Matscore grade
	double grade = (Korscore * 3 + Engscore * 5 + Matscore * 4) / ((double)(Credits));            // Average Calculation of Ratings

	int res = ((Credits) > 10) && (grade > 4);      // If the mean of Add all grade is more than 10 points and If the mean of the rating is greater than 4.0, it is true, so the result is 1, otherwise it is false, and the result is 0
	printf("%d", res);

	return 0;
}