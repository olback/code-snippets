/*
 *	Calculate PI with with a series
 * 	https://github.com/olback/code-snippets/tree/master/js/pi
 * 	olback © 2018
 */

let negative = false;
let result = 0;

for(let i = 0; i < 100000000; i++) {

    if(negative) {
        // console.log(-1 / (i * 2 +1));
        result += (-1 / (i * 2 +1));
    } else {
        // console.log(1 / (i * 2 +1));
        result += (1 / (i * 2 +1));
    }

    negative = !negative;
    console.log(result * 4);

}

console.log(result * 4);
