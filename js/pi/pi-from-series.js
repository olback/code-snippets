/*
 *	Calculate PI with with a series
 * 	https://github.com/olback/code-snippets/tree/master/js/pi
 * 	olback © 2018
 */

let negative = false;
let result = 0;

for(let i = 1; i < 100000000; i+= 2) {

    if(negative) {
        // console.log(-1 / (i * 2 +1));
        result += (-1 / i);
    } else {
        // console.log(1 / (i * 2 +1));
        result += (1 / i);
    }

    negative = !negative;
    console.log(result * 4);

}

console.log(result * 4);
