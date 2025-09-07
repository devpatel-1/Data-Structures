#include <stdio.h>

int step = 0;

void TOH(int n, char a, char b, char c) {
    if (n <= 0) {
        return;
    }
    TOH(n - 1, a, c, b);
    printf("\n%d: %c --> %c", ++step, a, c);
    TOH(n - 1, b, a, c);
}

int main() {
    int n = 4;  // number of disks
    TOH(n, 'A', 'B', 'C');
    return 0;
}