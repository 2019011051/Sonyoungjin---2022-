#include <stdio.h>

int main(void)
{
	int a = 5;
	int b = 5;
	int pre;
	int post;

	pre = (++a) * 3;
	post = (b++) * 3;

	printf("�ʱⰪ a = %d, b = %d\n", a, b);
	printf("������ : (++a) *3 = %d, ������ : (b++)*3= %d", pre, post);
	return 0;

}