// Primes from 0-100k in 1.78 seconds on an Intel i7-6700 (8) @ 4.000GHz (node v11.4.0)

function isPrime(n) {

    if (n === 1 || n === 2) {
        return true;
    }

    for (let i = 2; i < n; i++) {

        if (n % i === 0) {
            return false;
        }

    }

    return true;

}

for (let i = 1; i < 100000; i++) {

    if (isPrime(i)) {
        console.log(i);
    }

}
