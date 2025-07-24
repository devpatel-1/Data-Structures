// c) To find the address of a variable using pointers.

#include <stdio.h>

int main () {

    int x = 10;
    int *p;

    p = &x;

    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", &x);
    printf("Address stored in pointer p: %p\n", p);
    printf("Value pointed by p: %d\n", *p);

    return 0;

}