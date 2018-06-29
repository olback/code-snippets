/*
 *  olback.net © 2018
 *  https://github.com/olback/code-snippets/tree/master/c/cCipher2
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char al[] = "abcdefghijklmnopqrstuvwxyz";
const char au[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char *to_arr(const char c)
{
    char *arr = (char *)malloc(sizeof(char) * 2);
    arr[0] = c;
    arr[1] = '\0';

    return arr;
}

int valid_char(const char c)
{

    if ((c >= 'A' && 'Z' >= c) || (c >= 'a' && 'z' >= c))
    {
        return 1;
    }

    return 0;
}

void encode(char *str, int shift)
{

    for (int i = 0; i < strlen(str); i++)
    {

        if (valid_char(str[i]))
        {

            if (str[i] >= 'a')
            {
                printf("%c", al[(strcspn(al, to_arr(str[i])) + shift) % strlen(al)]);
            }
            else
            {
                printf("%c", au[(strcspn(au, to_arr(str[i])) + shift) % strlen(au)]);
            }
        }
        else
        {
            printf("%c", str[i]);
        }
    }

    printf("\n");
}

void decode(char *str, int shift)
{

    // Flip the alphabet to decode
    char alb[strlen(al)];
    char aub[strlen(au)];
    for (int i = 0; i < strlen(al); i++)
    {
        alb[i] = al[strlen(al) - i - 1];
        aub[i] = au[strlen(au) - i - 1];
    }
    alb[strlen(al)] = '\0';
    aub[strlen(au)] = '\0';

    for (int i = 0; i < strlen(str); i++)
    {

        if (valid_char(str[i]))
        {

            if (str[i] >= 'a')
            {
                printf("%c", alb[(strcspn(alb, to_arr(str[i])) + shift) % strlen(alb)]);
            }
            else
            {
                printf("%c", aub[(strcspn(aub, to_arr(str[i])) + shift) % strlen(aub)]);
            }
        }
        else
        {
            printf("%c", str[i]);
        }
    }

    printf("\n");
}

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        printf("Caesar Cipher v%s\n", "2.0.0");
        printf("Encode: -e \"string\" (int)shift\n");
        printf("Decode: -d \"string\" (int)shift\n");
        printf("Expected three arguments, got %i.\n", argc - 1);
        return 0;
    }

    if (strcmp(argv[1], "-e") == 0)
    {
        encode(argv[2], atoi(argv[3]));
    }
    else if (strcmp(argv[1], "-d") == 0)
    {
        decode(argv[2], atoi(argv[3]));
    }
    else
    {
        printf("Failed\n");
        return -1;
    }

    return 0;
}
