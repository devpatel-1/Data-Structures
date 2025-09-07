#include <stdio.h>
#include <ctype.h>   // for isalnum()
#include <string.h>  // for strlen()

#define MAX 100

char stack[MAX];
int top = -1;

// Push element to stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Pop element from stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

// Return precedence of operator
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char symbol;

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        // If operand, add to postfix
        if (isalnum(symbol)) {
            postfix[k++] = symbol;
        }
        // If operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(symbol)) {
                postfix[k++] = pop();
            }
            push(symbol);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';  // End string
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression (without parentheses): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}