/*
 * gcc -Wall -lm main.c && ./a.ou
 */

#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

/*
 *  | 7 | 6 | 5..0 |
 *  7: Sign bit
 *  6: Plus 0.5
 *  5..0: Integer part
 */

void print_byte(uint8_t byte) {
    for (int i = 7; i >= 0; i--) {
        printf("%s", (byte & (1<<i)) ? "1" : "0");
    }
    // printf("\n");
}

uint8_t float_to_byte(float fl_in) {
    float fl = fl_in - 20;
    uint8_t hf = 0;
    // Sign bit
    if (fl < 0) {
        hf |= 1<<7;
    }

    // Decimal bit
    float fa = round(fabs(fl) * 2) / 2;
    if (fa - (int)fa >= 0.5) {
        hf |= 1<<6;
    }

    // Integer part
    hf |= ((uint8_t)fa & 0x3f);

    return hf;
}

float byte_to_float(uint8_t byte) {
    float nf = 0;
    // Add integer part
    nf += (byte & 0x3f);

    // Add decimal
    if (byte & 1<<6) {
        nf += 0.5;
    }

    if (byte & 1<<7) {
        nf = -nf;
    }

    return nf + 20;
}

int main() {

    srand(time(0));

    float f = (rand() / (RAND_MAX / 120.0)) - 40;
    printf("%f", f);
    printf(" -> ");

    uint8_t hf = float_to_byte(f);
    print_byte(hf);
    printf(" -> ");

    float nf = byte_to_float(hf);
    printf("%f\n", nf);

    return 0;
}
