/*
 *  FizzBuzz by olback
 */

#include <stdio.h>

int main()
{
    // printf("FizzBuzz!\n");

    int n = 10000000;
    int i;

    for (i = 0; i < n; i++) {

        if (i % 3 == 0) { printf("Fizz"); }
        if (i % 5 == 0) { printf("Buzz"); }

        if(i % 5 != 0 && i % 3 != 0){
            printf("%d",i);
        }

        printf("\n");

    }

}
