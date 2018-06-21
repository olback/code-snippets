/*
 *  Caesar cipher
 */

const ALPHABET = 'ABCDEFGHIJKLMNOPQRSTUVWXYZÅÄÖ';

function encode(str = '', steps = 0) {

    let arr = [];

    for (let i = 0; i < str.length; i++) {

        if (str[i] === ' ') {
            arr.push(' ');
        } else {
            arr.push(ALPHABET[(ALPHABET.indexOf(str[i].toUpperCase()) + steps) % ALPHABET.length]);
        }
    }

    return arr.join('');

}

// Does not work yet!
function decode(str = '', steps = 0) {

    let arr = [];

    for (let i = 0; i < str.length; i++) {

        if (str[i] === ' ') {

            arr.push(' ');

        } else {

            const spot = ALPHABET.indexOf(str[i].toUpperCase()) - steps;

            if (spot < 0) {
                arr.push(ALPHABET[ALPHABET.length + spot]);
            } else {
                arr.push(ALPHABET[spot]);
            }

        }

    }

    return arr.join('');

}

// Examples
let input = "hello gais åäö";
console.log(input);

let encoded = encode(input, 10);
console.log(encoded);

let decoded = decode(encoded, 10);
console.log(decoded);
