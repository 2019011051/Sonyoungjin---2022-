#include <stdio.h>
#include <string.h>

#define PIN "7042"     // Defined by PIN number 7042
#define Array_size 10  // Defined by Array Size 10

int PIN_Program(void);    // Declaration of functions

int main(void)
{
    PIN_Program();             // Call a function
    return 0;
}

int PIN_Program(void)
{
    char C_Password[Array_size] = { PIN };   // Array C_Password array 10 and defined PIN 70 42 followed by you.
    char M_Password[Array_size] = "";  // M_Password initializes to null


    while (1)    //Start of infinite repetition
    {
        printf("Input your Password : ");    // Input your Password
        scanf_s("%s", M_Password, Array_size);       
        
        if (strcmp(C_Password, M_Password) == 0)break;  //If C_Password and M_Password are the same, escape the repeat door

        else                                      // if not the same
        {
            printf("not matched, retry...");     // not matched,retry.. Output
        }

    }
    printf("normal termination");           //normal termination Output
    return 0;
}