/*
 *	Get the median of any amount of numbers
 * 	https://github.com/olback/code-snippets/tree/master/js/median
 * 	olback © 2018
 */

const DELIMITER = ' '; // What seperates the numbers? Default: '<space>'
let input = '1 2 3 4 5 6 7 8 9'; // Expected output = 5

if (typeof prompt === 'function') {
	input = prompt();
}

/*	
 *	0. Javascript array method-chaning is beatuful!
 *	1. Split the string into an array, seperated by the defined delimiter.
 *	2. Convert everything in the array to numbers.
 *	3. Filter out the values that are NaN by comparing it with itself, because in Javascript, NaN !== NaN.
 * 	4. Finaly sort the array, starting with the smallest number.
 */
const arr = input.split(DELIMITER).map(x => Number(x)).filter(val => val === val).sort((a, b) => a - b);

/* 
 *  If there are an even amount of numbers, print the avrige of the two in the middle,
 *	else print the median.
 */
if (arr.length % 2 === 0) {
	console.log((arr[(arr.length / 2) - 1] + arr[(arr.length / 2)]) / 2);
} else {
	console.log(arr[Math.floor(arr.length / 2)]);
}
