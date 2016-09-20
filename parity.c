// 09/20/2016
#include <stdio.h>

int parity(unsigned long x)
{
    int n = 0;
    while (x != 0) {
        if (x & 1) ++n;
        x >>= 1;
    }

    return n % 2;
}

int main()
{
    int i;

    printf("sizeof(unsigned long):%d\n", sizeof(unsigned long));
    for (i = 0; i < 10; i++) {
        int p1 = parity(i);
        printf("parity of %d:%d\n", i, p1);
    }

    return 0;
}




