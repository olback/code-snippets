/*
 *  Guess the number by olback
 *  olback.net
 *  Spaghetti code at it's best!
 */

console.log("%c\nGuess the number by olback\n\n","font-size: 18pt;");

const input = document.getElementById("input");
const check = document.getElementById("check");
const output = document.getElementById("output");
const restart = document.getElementById("restart");
const log = false;
var rNumber = Math.floor(Math.random() * 100);
var round = 0;
var tries = [];
            
if(log){console.log("The number is: " + rNumber);}

function compare() {

    tries.push(input.value);

    if (input.value == rNumber) {

        if (tries.length == 1) {
            output.innerHTML = "You're Lucky. You got it on the first try!";
        } else {
            output.innerHTML = "Correct! You got it in " + tries.length + " tries!";
        }
                    
        input.disabled = true;
        check.disabled = true;
        restart.hidden = false;

        console.log("%cYour guesses:", "font-size: 10pt;")
        tries.forEach(function(element){console.log("%c" + element,"font-size: 10pt;")});
        console.groupEnd();

    } else if (input.value > rNumber) {

        output.innerHTML = "Number you enterd is too big";

    } else if (input.value < rNumber) {

        output.innerHTML = "Number you enterd is too small";

    }

}

function restartGuess() {

    round = round + 1
    tries = [];
    input.disabled = false;
    input.value = "";
    check.disabled = false;
    restart.hidden = true;
    output.innerHTML = "";
    rNumber = Math.floor(Math.random() * 100);
    console.group("%c\nRound nr: "+ round +"\n\n", "font-size: 12pt;");

}

document.querySelector('#input').addEventListener('keypress', function(e) {
    var key = e.which || e.keyCode;
    if (key === 13) { // 13 is enter
        compare();
    }
});

restartGuess();