#include <stdio.h>
#include <sal.h>

void output(FILE* fp);


int main(void)
{
	FILE* fp1;
	FILE* fp2;

	fopen_s(&fp1, "yolo_label_data.txt", "r");
	output(fp1);
	
	fclose(fp1);


	fopen_s(&fp2, "yolo_bbox_data.txt", "r");
	output(fp2);
	
	fclose(fp2);

	return 0;
}

void output(FILE* fp)
{
	int ch = 0;

	if (fp == NULL)
	{
		printf("File did not open\n");

	}
	while (1)
	{
		ch = fgetc(fp);
		putchar(ch);
		if (ch == EOF)
		{
			break;
		}
	}

	fclose(fp);

}