#include <stdio.h>

void Input(int integer, double real_number, char character, char string[80])
{

}

void fInput(FILE* fp, int integer, double real_number, char character, char string[80])
{
    fprintf(fp, "Integer: %d\n", integer);
    fprintf(fp, "Real number: %f\n", real_number);
    fprintf(fp, "Character: %c\n", character);
    fprintf(fp, "String: %s\n", string);
}

void fPrint(FILE* fp)
{
    int ch;
    printf("\nFile Contents: \n");

    fopen_s(&fp, "new.txt", "r");

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
}

int main()
{
    FILE* fp;
    int integer = 0;
    float real_number = 0;
    char character = 0;
    char string[100] = { NULL, };
    char* pstring = string;

    fopen_s(&fp, "new.txt", "w");

    if (fp == NULL)
    {
        printf("Failed to create file.\n");
        return 1;
    }

    printf("Input integer: ");
    scanf_s("%d", &integer);
    printf("Input real number: ");
    scanf_s("%f", &real_number);
    printf("Input character: ");
    scanf_s(" %c", &character);
    printf("Input string: ");
    scanf_s("%s", string, 100);

    fInput(fp, integer, real_number, character, pstring);
    fclose(fp);

    fPrint(fp);
    fclose(fp);

    return 0;
}