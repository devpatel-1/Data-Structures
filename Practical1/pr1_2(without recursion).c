// Extra =  To calculate Nth term of a Fibonacci series without using recursion.

#include <stdio.h>

int main () {

    int n, i;
    int a = 0, b = 1, fib;

    printf("Enter the term number: ");
    scanf("%d", &n);

    if (n == 0) {
        fib = 0;
    } else if (n == 1) {
        fib = 1;
    } else {
        for (i = 2; i <= n; i++) {
            fib = a + b;
            a = b;
            b = fib;
        }
    }

    printf("The %dth term of the Fibonacci series is: %d\n", n, fib);

    return 0;
}