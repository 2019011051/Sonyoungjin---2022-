#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define max 100
#define zero 0
#define arr 10

int main(void)
{
    srand(time(NULL));
    int i;
    int a[arr];
    int sum = zero;
    double avg, var, std = zero;

    for (i = zero; i < arr; i++)
    {
        a[i] = rand() % max;
    }
    for (i = zero; i < arr; i++)
    {
        printf("%3d", a[i]);
        sum += a[i];
    }
    avg = sum / arr;

    for (i = zero; i < arr; i++)
    {
        sum += (a[i] - avg) * (a[i] - avg);

    }
    var = sum / arr;

    for (i = zero; i < arr; i++)
    {
        sum += sqrt((a[i] - avg) * (a[i] - avg));
    }
    std = sqrt(var);

    printf("\n");
    printf("Average:%.1f\n", avg);
    printf("Variance:%.1f\n", var);
    printf("Standard deviation:%.1f\n", sqrt(var));
    return 0;
}