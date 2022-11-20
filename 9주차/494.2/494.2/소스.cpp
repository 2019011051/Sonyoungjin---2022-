#include <stdio.h>
#include <string.h>

struct cracker
{
	int price;
	int calories;
};

int main(void)
{
	struct cracker 바사삭;
	printf("바사삭의 가격과 열랑을 입력하시오 :\n ");
	scanf_s("%d%d", &(바사삭.price), &(바사삭.calories));

	printf(" 바사삭의 가격 : %d\n", 바사삭.price);
	printf(" 바사삭의 열량 : %dkcal", 바사삭.calories);

	return 0;


}