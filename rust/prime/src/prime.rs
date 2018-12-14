// Primes from 0-100k in 3.3 seconds on an Intel i7-6700 (8) @ 4.000GHz

fn is_prime(n: i64) -> bool {

    if n == 1 || n == 2 {
        return true;
    }

    for i in 2..n {

        if n % i == 0 {
            return false;
        }

    }

    return true;

}


fn main() {

    for n in 1..100000 {

        if is_prime(n) {
            println!("{}", n);
        }

    }

}
