/* 
 *  https://github.com/olback/code-snippets/tree/master/c/pi
 *  2018 © olback
 */

#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

u_int64_t rounds = 1000000000;
float result = 0;
bool negative = false;

int main(int argc, char *argv[])
{

    if (argc == 2)
    {
        rounds = strtoll(argv[1], NULL, 10);
        if (rounds == 0)
        {
            printf("'%s' is not a valid integer\n", argv[1]);
            exit(-1);
        }
    }

    for (u_int64_t i = 1; i < rounds; i += 2)
    {
        if (negative)
        {
            result += (-4 / (float)i);
        }
        else
        {
            result += (4 / (float)i);
        }
        negative = !negative;
    }

    printf("PI: %.10f\n", result);
}
