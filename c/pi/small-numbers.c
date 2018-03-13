/* 
 *  https://github.com/olback/code-snippets/tree/master/c/pi
 *  2018 © olback
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double r()
{
    return (double)rand() / (double)RAND_MAX;
}

u_int64_t inCircle = 0;
u_int64_t totalThrows = 0;
u_int64_t rounds = 100000000;

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

    srand(time(NULL));

    for (int i = 0; i < rounds; i++)
    {
        const double x = r();
        const double y = r();

        const float n = x * x + y * y;

        if (n < 1)
        {
            inCircle++;
        }

        totalThrows++;
    }

    printf("PI: %.10f\n", (inCircle / (float)totalThrows) * 4);

    return 0;
}
