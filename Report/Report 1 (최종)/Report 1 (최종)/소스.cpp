#include <stdio.h>
#include <string.h>

#define PIN "7042"     // PIN넘버 7042로 정의
#define Array_size 10  // 배열크기 10으로 정의

int PIN_Program(void);    // 함수 선언

int main(void)
{
    PIN_Program();             // 함수 호출 
    return 0;
}

int PIN_Program(void)
{
    char C_Password[10] = { PIN };   // 배열C_Password 배열을 10 하고 정의 내린 PIN 7 0 4 2 그뒤로는 널.
    char M_Password[10] = "";  // M_Password 는 널로 초기화


    while (1)    //무한반복문 시작
    {
        printf("Input your Password : ");    // Input your Password
        scanf_s("%s", M_Password, 10);       // 
        
        if (strcmp(C_Password, M_Password) == 0)break;  //만약  C_Password 와 M_Password가 같다면 반복문 탈출

        else                                      // 같지 않다면 
        {
            printf("not matched, retry...");     // not matched,retry.. 출력
        }

    }
    printf("normal termination");           //normal termination 출력
    return 0;
}