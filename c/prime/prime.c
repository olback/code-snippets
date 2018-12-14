// Primes from 0-100k in 4.15 seconds on an Intel i7-6700 (8) @ 4.000GHz

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool isPrime(uint64_t n) {

    if (n == 1 || n == 2) {
        return true;
    }

    for (uint64_t i = 3; i < n; i++) {

        if (n % i == 0) {
            return false;
        }

    }

    return true;

}

int main() {

    const uint32_t upto = 100000;

    for (uint64_t i = 1; i <= upto; i++) {

        if (isPrime(i)) {

            printf("%d\n", i);

        }

    }

    return 0;

}
