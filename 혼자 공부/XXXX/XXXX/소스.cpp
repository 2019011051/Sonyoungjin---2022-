#include <stdio.h>

#define Size 100
// Function to output file information
void fPrint(FILE* fp)
{
    int ch = 0;
    // Output if file does not exist
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
    // File Pointer Declaration
    FILE* fp1;
    FILE* fp2;

    // File 1 Read and output information
    printf("yolo_label_data.txt: \n");
    fopen_s(&fp1, "yolo_label_data.txt", "r");
    fPrint(fp1);

    fclose(fp1);

    // File 2 Read and output information
    printf("\nyolo_bbox_data.txt: \n");
    fopen_s(&fp2, "yolo_bbox_data.txt", "r");
    fPrint(fp2);

    fclose(fp2);

    return 0;
}