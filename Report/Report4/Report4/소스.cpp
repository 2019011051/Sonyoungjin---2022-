#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Size 10

int Line_up_Program();

int main(void)
{
	int n,i, j, temp = 0;            //���� ����
	int Number[Size] = { rand() };    //�迭�ȿ� ������ ���� ����
	
	// �迭1~10���� ���
	for (n = 0; n < Size; n++)
	{
		Number[n] = rand() % 100;
		printf("This is %d number : %d\n", n, Number[n]);
	}  

	//�� ���� ���α׷� ȣ��
	Line_up_Program();

	// ������ �迭�� ���������� �����ϱ�
	for (i = 0; i < Size; i++)
	{
		for (j= i+1; j< Size; j++)
		{
			if (*(Number+ i) > *(Number+j))
			{
				temp = *(Number + i);
				* (Number + i) = *(Number + j);
				*(Number + j) = temp;
			}
		}
	}
	// ������ �������� ����ϱ�
	for (i = 0; i < Size; i++)
	{
		printf("�������� %d number : %d\n", i, Number[i]);
	}
	
	// �ٶ��� ���α׷� ȣ��
	Line_up_Program();

	//������ �迭�� ���������� ����
	for (i = 0; i < Size; i++)
	{
		for (j = i + 1; j < Size; j++)
		{
			if (*(Number + i) < *(Number + j))
			{
				temp = *(Number + i);
				*(Number + i) = *(Number + j);
				*(Number + j) = temp;
			}
		}
	}
	//������ ���������� ���
	for (i = 0; i < Size; i++)
	{
		printf("�������� %d number : %d\n", i, Number[i]);
	}
	return 0;
}


// �� ���� �Լ�
int Line_up_Program()
{
	int Line_up = 0;

	for (Line_up = 0; Line_up < 50; Line_up++)
	{
		printf("");
	}
	printf("\n");
	return 0;
}
void GenRandSeed()   // generating the seed number using the time clock information
{

	srand((unsigned int)(time(NULL)));  // generating the random number using the time seed
	return;
}
unsigned int GenRandNum(unsigned int nRange) // generating the random number
{
	unsigned int nRes = 0;
	unsigned int nNum = rand();
	nRes = ((unsigned int)(nNum) % (nRange));
	return nRes;
}
