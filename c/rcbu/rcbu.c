#include <stdio.h>
#include <string.h>

char string[] = "/this/is/a/path/remove_the_last_slash_and_everything_after_it";
const int asciiChar = 47; // 47 is '/' in ascii.

int main() {
    int strLenBefore = strlen(string);

    for(int i = strLenBefore; i >= 0; i--) {
        if(string[i] == asciiChar) {
            int strLenAfter = strLenBefore - i;
            string[strLenBefore-strLenAfter] = '\0';
            //string[strLenBefore-strLenAfter+1] = '\0'; // This keeps the last slash.
            break;
        }
    }

    printf("String: %s\n", string);
    printf("Length: %d\n", strlen(string));
    return 0;
}
