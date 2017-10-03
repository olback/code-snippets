/*
 *	age.js
 */

// Vars
const year = 2000;                       // The year you were born.
const bMonth = 9;                        // The month you were born.
const day = 10;                          // The day you were born.
const date = new Date();                 // Store new Date ()
const cYear = date.getFullYear();        // Get current year
const cMonth = date.getMonth();          // Get current month
const cDay = date.getDate();             // Get current day of the month
const month = bMonth - 1;                // JS starts counting from 0. January = 0, December = 11.
let age;

// Example 1
// This example is 100% accurate, but it's quite complex compared to example 2.
if(cMonth >= month && cDay >= day){
  age = cYear - year;
} else if(cMonth > month) {
  age = cYear - year;
} else {
  age = cYear - year - 1
}

console.log('Example 1: ' + age);


// Example 2
// This is nice and short, but it's not as accurate as example 1.
var agelnMs = date.getTime() - (new Date(year, month, day));
var age2 = Math.floor(agelnMs / 1000 / 3600 / 24 / 365.25);

console.log('Example 2: ' + age2);
