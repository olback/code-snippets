#include <stdio.h>

int a() {
    static n = 0;
    return ++n;
};

int main()
{

    if(a() == 1 && a() == 2 &&a() == 3) {
        printf("Yup\n");
    }

    return 0;
}

