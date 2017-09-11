/*
 *  Guess the number
 *  © olback.net
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int r,v,tries;

int main()
{
    srand(time(NULL));
    r = rand() % 100 + 1;
    system("clear");
    printf("\nGuess the number\n   C edition \n\n");

    //printf("\nRandom number is %d\n\n",r);


    while(r != v) {

        printf("Enter a number between 0 and 100: ");
        if (scanf("%d", &v) == 1) {
            tries++;

            if(v > r) {

                printf("Number is lower\n");

            } else if (v < r) {

                printf("Number is higher\n");

            } else if (v == r) {

                if(tries == 1) {
                    printf("\nYou got it on the first try! Awesome!\n");
                } else if (tries >= 15){
                    printf("\nNot so great! You got it in %d tries. :(\n\n",tries);
                } else {
                    printf("\nGreat! You got it in %d tries!\n\n",tries);
                }

            }

        } else {

            printf("Not an integer.\n");
            return -1;

        }

    }

    return 0;
}