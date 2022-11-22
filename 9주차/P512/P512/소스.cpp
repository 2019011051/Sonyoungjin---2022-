#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student              //Override as Student
{
    //variable declaration
    int id;
    char name[20];
    int kor;
    int eng;
    int mat;
    int tot;
    double avg;
    char grade;
};

void input_data(Student* info);     //Input function
void calculation_data(Student* info);     //Total Score Mean Credit Calculation Function
void print_data(Student* info);        //Output function
void sort_data(Student* info);          //A function to sort
int main(void)
{
    Student info[5];                 //Declare the new datatype as an info array
    
    input_data(info);               //Put info array in input function
    calculation_data(info);          //Calculation info array in input function
    
    printf("#Data Before Sort...\n");
    print_data(info);                  //Put info array in output function
    sort_data(info);                    //Put info array in sort function
    printf("#Data After Sort...\n"); 
    print_data(info);                  //Putting sorted data into the output function

    return 0;
}

void input_data(Student* info)
{
    int i;

    for (i = 0; i < 5; i++)         //For statements that enter variable values stored in the structure in the info array
    {
        printf("id : ");
        scanf_s("%d", &info->id);   

        printf("name: ");
        scanf("%s", info->name);

        printf("Kor, Eng, Mat : ");
        scanf_s("%d%d%d", &info->kor, &info->eng, &info->mat);
        info++;                     //Meaning Moving On to Array
    }
}
void calculation_data(Student* info)
{
    int i;

    for (i = 0; i < 5; i++)
    {
        info->tot = info->kor + info->eng + info->mat;
        info->avg = info->tot / 3.0;
        if (info->avg >= 90.0)               //If it's 90 or higher, A
        {
            info->grade = 'A'; 
        }
        else if (info->avg >= 80.0)           //If it's 80 or higher, B
        {
            info->grade = 'B';
        }
        else if (info->avg >= 70.0)        //If it's 80 or higher, C
        {
            info->grade = 'C';
        } 
        else                             //If it doesn't apply to all of them, F
        {
            info->grade = 'F';
        }
        info++;          //Meaning Moving On to Array
    }
}
void print_data(Student* info)
{
    int i;
     
    for (i = 0; i < 5; i++)          //To print out the information stored in the info
    {
        printf("%5d%5s%5d%5d%5d%5d%5.1If%5c\n", info->id, info->name, info->kor, info->eng, info->mat, info->tot, info->avg, info->grade);
        info++;                 // //Meaning Moving On to Array
    }
}
void sort_data(Student* info)
{
    Student temp;
    int i, j, k;
     
    //Use descending double for statements to align
    for (i = 0; i < 4; i++)
    {
        k = i;
        for (j = i + 1; j < 5; j++)             //Application of descending and ascending programs previously reported
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