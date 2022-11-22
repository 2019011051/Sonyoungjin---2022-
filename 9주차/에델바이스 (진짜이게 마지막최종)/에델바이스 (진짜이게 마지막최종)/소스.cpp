#include <stdio.h>


void fPrint(FILE* fp)       //A function that reads the generated file and outputs it to the screen
{
    int x = 0;
    // Output if file does not exist
    if (fp == NULL)
    {
        printf("The file will not open.\n");
    }
    while (1)
    {
        x = fgetc(fp);
        putchar(x);
        if (x == EOF)
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

   
  
    fopen_s(&fp1, "yolo_label_data.txt", "r");
    fPrint(fp1);     

    fclose(fp1);

    // File 2 Read and output information
 
    fopen_s(&fp2, "yolo_bbox_data.txt", "r");
    fPrint(fp2);

    fclose(fp2);

    return 0;
}