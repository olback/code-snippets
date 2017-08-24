/*
 *	age.js
 */

// Vars
var year = 2000;                        // The year you were born.
var month = 09;                         // The month you were born.
var day = 10;                           // The day you were born.
var month = month - 1;                  // JS starts counting from 0. January = 0, December = 11.
var nDate = new Date();                 // Store new Date ()
var cYear = nDate.getFullYear();        // Get current year
var cMonth = nDate.getMonth();          // Get current month
var cDay = nDate.getDate();             // Get current day of the month


// Example 1
// This example is 100% accurate, but it's quite complex compared to example 2.
if(cMonth >= bMonth && cDay >= bDay){
  age = cYear - bYear;
} else {
  age = cYear - bYear - 1;
}

console.log('Example 1: '+age);


// Example 2
// This is nice and short, but it's not as accurate as example 1.
var agelnMs = nDate.getTime() - (new Date(year, month, day));
var age2 = Math.floor(agelnMs / 1000 / 3600 / 24 / 365.25);

console.log('Example 2: '+age2);
