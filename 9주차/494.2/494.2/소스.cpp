#include <stdio.h>
#include <string.h>

struct cracker
{
	int price;
	int calories;
};

int main(void)
{
	struct cracker �ٻ��;
	printf("�ٻ���� ���ݰ� ������ �Է��Ͻÿ� :\n ");
	scanf_s("%d%d", &(�ٻ��.price), &(�ٻ��.calories));

	printf(" �ٻ���� ���� : %d\n", �ٻ��.price);
	printf(" �ٻ���� ���� : %dkcal", �ٻ��.calories);

	return 0;


}