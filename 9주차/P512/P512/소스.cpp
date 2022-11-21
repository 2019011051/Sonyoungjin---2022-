#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student 
{
    int id;
    char name[20];
    int kor;
    int eng;
    int mat;
    int tot;
    double avg;
    char grade;
};

void input_data(Student* info);
void calculation_data(Student* info);
void print_data(Student* info);
void sort_data(Student* info);
int main(void)
{
    Student info[5];
    
    input_data(info);
    calculation_data(info);
    
    printf("#Data Before Sort...\n");
    print_data(info);
    sort_data(info);
    printf("#Data After Sort...\n");
    print_data(info);

    return 0;
}

void input_data(Student* info)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("id : ");
        scanf_s("%d", &info->id);

        printf("name: ");
        scanf("%s", info->name);

        printf("Kor, Eng, Mat : ");
        scanf_s("%d%d%d", &info->kor, &info->eng, &info->mat);
        info++;
    }
}
void calculation_data(Student* info)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        info->tot = info->kor + info->eng + info->mat;
        info->avg = info->tot / 3.0;
        if (info->avg >= 90.0)
        {
            info->grade = 'A';
        }
        else if (info->avg >= 80.0)
        {
            info->grade = 'B';
        }
        else if (info->avg >= 70.0)
        {
            info->grade = 'C';
        }
        else
        {
            info->grade = 'F';
        }
        info++;
    }
}
void print_data(Student* info)
{
    int i;
    
    for (i = 0; i < 5; i++)
    {
        printf("%5d%5s%5d%5d%5d%5d%5.1If%5c\n", info->id, info->name, info->kor, info->eng, info->mat, info->tot, info->avg, info->grade);
        info++;
    }
}
void sort_data(Student* info)
{
    Student temp;
    int i, j, k;

    for (i = 0; i < 4; i++)
    {
        k = i;
        for (j = i + 1; j < 5; j++)
        {
            if (info[k].tot < info[j].tot)
            {
                k = j;
            }
        }
        if (k != i)
        {
            temp = info[k];
            info[k] = info[i];
            info[i] = temp;
        }
    }
}