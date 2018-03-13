/*
 *	Calculate PI with with a series
 * 	https://github.com/olback/code-snippets/tree/master/js/pi
 * 	olback © 2018
 */

let inCircle = 0;
let totalTrows = 0;

for (let i = 0; i < 1000000000; i++) {

    const x = Math.random();
    const y = Math.random();

    const n = x * x + y * y;

    if (n < 1) {
        inCircle++;
    }

    totalTrows++;

}

console.log((inCircle / totalTrows) * 4);
