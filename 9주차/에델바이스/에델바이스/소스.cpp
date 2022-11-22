#include <stdio.h>
#include <stdlib.h>

void output(FILE* data)
{
	int x = 0l;

	if (data == NULL)
	{
		printf("File did not open\n");
		
	}
	while (1)
	{
		x = fgetc(data);
		putchar(x);
		if (x == EOF)
		{
			break;
		}
	}

	fclose(data);
}

int main(void)
{
	FILE* data1;
	FILE* data2;

	fopen_s(&data1, "yolo_label_data.txt", "r");
	output(data1);
	fclose(data1);
	
	
	fopen_s(&data2, "yolo_bbox_data.txtx", "r");
	output(data2);
	fclose(data2);

	return 0;
}