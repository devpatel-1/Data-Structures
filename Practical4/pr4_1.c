#include <stdio.h>
#include <string.h>

#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0'; // if empty
}

int main() {
    char input[MAX], reversed[MAX];
    printf("Enter a string: ");
    scanf("%s", input);

    int len = strlen(input);

    // Push all characters into stack
    for (int i = 0; i < len; i++) {
        push(input[i]);
    }

    // Pop all to get reversed string
    int i = 0;
    while (top != -1) {
        reversed[i++] = pop();
    }
    reversed[i] = '\0'; // null terminate

    // Compare original and reversed
    if (strcmp(input, reversed) == 0) {
        printf("Valid String: It is belong to L\n");
    } else {
        printf("Invalid String: It is not belong to L\n");
    }

    return 0;
}