//7/31/2018
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

// dynamic programming 
int fib2(int n, int result[]) {
    if (n <= 0) return result[0];
    if (n == 1) return result[1];

    if (result[n] == 0) {
        result[n] = result[n-1] + result[n-2];
    }
    return result[n];
}


// iterative
unsigned long long fib3(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    unsigned long long prev = 0;
    unsigned long long curr = 1;

    for (int i = 1; i < n; i++) {
        unsigned long long tmp = prev + curr;
        prev = curr;
        curr = tmp;
    }

    return curr;
}

int main()
{
    const int n = 100;
    for (int i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));    
    }
    printf("\n");

    int result[n] = {0};
    result[1] = 1;
    for (int i = 0; i < n; i++) {
        printf("i:%d\n", i);
        printf("%d ", fib2(i, result));
        printf("%llu \n", fib3(i));
    }
    return 0;
}
