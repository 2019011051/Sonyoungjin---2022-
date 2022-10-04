#include <stdio.h>

int main(void)
{ 
	int kor = 3;
	int eng = 5;
	int math = 4;

	double kscore = 3.8;
	double escore = 4.4;
	double mscore = 3.9;

	int total = (kor, eng, math);
	double average = ((kor * kscore) + (eng * escore) + (math * mscore)) / (total);


	total = (kor + eng + math);
	average = ((kor * kscore) + (eng * escore) + (math * mscore)) / (total);

	int res = (total >= 10) && (average > 4);
	printf("%d", res);

	return 0;


}