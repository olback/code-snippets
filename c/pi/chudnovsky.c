/* 
 *  Implementation of the Chudnovsky algorithm.
 *  Since this is C, we only have 11 bits of floating point precision.
 *  https://github.com/olback/code-snippets/tree/master/c/pi
 *  2018 © olback
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0

double chudnovsky(int maxK) {

     // K, M, L, X, S = 6, 1, 13591409, 1, 13591409
     long long int K = 6;
     double M = 1;
     double L = 13591409;
     double X = 1;
     double S = 13591409;

    for(int i = 1; i < maxK+1; i++) {
        M = (K * 3 - (K<<4)) * M / i * 3;
        L += 545140134;
        X *= -262537412640768000;
        S += (M * L) / X;
        K += 12;
    }

    double pi = (426880 * sqrt(10005)) / S;

    return pi;
}

int main(int argc, char *argv[])
{
    printf("PI calculated with the Chudnovsky algorithm!\n");
    printf("PI: %.11f\n", chudnovsky(10));
    printf("Last digit is rounded.\n");
}
