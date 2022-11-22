#include <stdio.h>

#define Size 100

void fPrint(FILE* fp)
{
    int ch = 0;

    if (fp == NULL)
    {
        printf("The file will not open.\n");
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

int main()
{
    FILE* fp1;
    FILE* fp2;

    printf("yolo_label_data.txt: \n");
    fopen_s(&fp1, "yolo_label_data.txt", "r");
    fPrint(fp1);

    fclose(fp1);

    printf("\nyolo_bbox_data.txt: \n");
    fopen_s(&fp2, "yolo_bbox_data.txt", "r");
    fPrint(fp2);

    fclose(fp2);

    return 0;
}