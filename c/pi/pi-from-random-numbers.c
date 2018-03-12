/*
 *  Compile with 'gcc pi-from-random-numbers.c -m64 -lm'
 * 
 *  Video by Matt Parker https://www.youtube.com/watch?v=RZBhSi_PwHU
 *  https://github.com/olback/code-snippets/tree/master/c/pi
 *  2018 © olback
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0

u_int64_t rounds = 10000000;
u_int64_t coprimeCount;

char *formatTime(float seconds) {
    char *str = (char *) malloc(sizeof(char) * 128);

    float hour = seconds / (60 * 60);
    float min = seconds / 60;
    float sec = (int)seconds % 60;

    if(hour >= 1) {
        min = min - ((int)hour * 60);
        sprintf(str, "%.0f hours, %.0f minutes and %.2f seconds", hour, min, sec);
    } else if(min >= 1) {
        sprintf(str, "%.0f minutes and %.2f seconds", min, sec);
    } else {
        sprintf(str, "%.5f seconds", seconds);
    }

    return str;

}

int gcd(u_int64_t a, u_int64_t b)
{
    while (b != 0)
    {
        u_int64_t t = a % b;
        a = b;
        b = t;
    }

    return a;
}

int coprime(u_int64_t a, u_int64_t b)
{
    if (((a | b) & 1) != 1)
        return false;

    return gcd(a, b) == 1;
}

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
    
    /* Print how many times we genereate 2 new numbers */
    printf("Running %lli times. ", rounds);

    /* If rounds >= 10000000, print a warning */
    if (rounds >= 10000000)
        printf("This might take a while...");

    /* Print a newline since we don't do that in the printf statements above */
    printf("\n");

    /* Generate a random seed from the time */
    srand(time(NULL));

    /* Start timer */
    clock_t start = clock();

    /* Generate random numbers, if a pair is coprime increment the counter */
    for (u_int64_t i = 0; i < rounds; i++)
    {
        int r1 = rand();
        int r2 = rand();

        if (coprime(r1, r2))
        {
            coprimeCount++;
        }
    }

    /* Stop the timer */
    clock_t end = clock();

    /* Calculate PI */
    double percentCoprime = coprimeCount / (double)rounds;
    float calculatedPi = sqrtf(6.0 / percentCoprime);

    /* Calculate total time */
    float totalTime = (float)(end - start) / CLOCKS_PER_SEC;

    /* Print the result */
    printf("Calculated value of PI is %1.10f...\n", calculatedPi);
    printf("Calculation took %s.\n", formatTime(totalTime));

    return 0;
}
