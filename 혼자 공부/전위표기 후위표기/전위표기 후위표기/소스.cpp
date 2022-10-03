#include <stdio.h>

int main(void)
{
	int a = 5;
	int b = 5;
	int pre;
	int post;

	pre = (++a) * 3;
	post = (b++) * 3;

	printf("초기값 a = %d, b = %d\n", a, b);
	printf("전위형 : (++a) *3 = %d, 후위형 : (b++)*3= %d", pre, post);
	return 0;

}