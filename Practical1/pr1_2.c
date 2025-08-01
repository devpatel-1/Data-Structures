// b) To calculate Nth term of a Fibonacci series using recursion.

#include <stdio.h>

int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else 
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main () {

    int n;

    printf("Enter the term number: ");
    scanf("%d", &n);

    printf("The %dth term of the Fibonacci series is: %d\n", n, fibonacci(n));

    return 0;

}