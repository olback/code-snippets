
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char version[] = "0.0.1";

typedef int bool;
#define true 1
#define false 0

void showHelp(bool verbose)
{
    if (verbose)
    {
        printf("  Author: olback\n");
        printf("  Project url: https://github.com/olback/code-snippets/tree/master/c/cCipher\n");
        printf("  License: MIT\n\n");

        printf("  Usage:\n");
        printf("    -h --help show help\n");
        printf("    -e --encrypt \"string\" (int)shift\n");
        printf("    -d --decrypt \"string\" (int)shift\n\n");

        printf("  Examples:\n");
        printf("    Encrypt: ./cCipher.out -e \"THE QUICK BROWN FOX\" 10\n");
        printf("    Decrypt: ./cCipher.out -d \"DRO AESMU LBYGX PYH\" 10\n\n");
    }
    else
    {
        printf("Incorrect usage. Use -h for help.\n");
    }
}

void encrypt(char *str, int len)
{
    if (len > 26 || len < 0)
    {
        printf("Shift may only be 0-26\n");
        return;
    }

    char output[strlen(str)];
    sprintf(output, "%s", str);
    for (int i = 0; i < strlen(output); i++)
    {
        /* make sure all characters are uppercase */
        if (output[i] > 96)
        {
            output[i] -= 32;
        }

        if (output[i] != ' ')
        {
            output[i] = ((output[i] - 65 + len) % 26) + 65;
        }
    }

    printf("Output: \"%s\"\n", output);
}

void decrypt(char *str, int len)
{
    if (len > 26 || len < 0)
    {
        printf("Shift may only be 0-26\n");
        return;
    }

    char output[strlen(str)];
    sprintf(output, "%s", str);
    for (int i = 0; i < strlen(output); i++)
    {
        /* make sure all characters are uppercase */
        if (output[i] > 96)
        {
            output[i] -= 32;
        }

        if (output[i] != ' ')
        {
            char ch = output[i] - len;
            if (ch < 'A')
            {
                ch = ch + 'Z' - 'A' + 1;
            }
            output[i] = ch;
        }
    }

    printf("Output: \"%s\"\n", output);
}

int main(int argc, char *argv[])
{
    printf("\n  cCipher v%s\n\n", version);

    if (argc > 1 && argc < 5)
    {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            showHelp(true);
        }
        else if (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--decrypt") == 0)
        {
            if (argc == 4)
                decrypt(argv[2], atoi(argv[3]));
            else
                printf("Expected two arguments, got %i.\n", argc - 2);
        }
        else if (strcmp(argv[1], "-e") == 0 || strcmp(argv[1], "--encrypt") == 0)
        {
            if (argc == 4)
                encrypt(argv[2], atoi(argv[3]));
            else
                printf("Expected two arguments, got %i.\n", argc - 2);
        }
        else
        {
            showHelp(false);
        }
    }
    else
    {
        showHelp(false);
    }

    return 0;
}
