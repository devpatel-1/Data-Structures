#include <stdio.h>
#include <ctype.h>   // for isdigit()

#define MAX 100

int stack[MAX];
int top = -1;

// Push number onto stack
void push(int n) {
    if (top < MAX - 1) {
        stack[++top] = n;
    }
}

// Pop number from stack
int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i, op1, op2, result;

    for (i = 0; exp[i] != '\0'; i++) {
        char symbol = exp[i];

        // If operand (number)
        if (isdigit(symbol)) {
            push(symbol - '0');  // convert char to int
        }
        // If operator
        else {
            op2 = pop();
            op1 = pop();

            switch (symbol) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }
            push(result);
        }
    }
    return pop();  // Final result
}

int main() {
    char exp[MAX];

    printf("Enter postfix expression (single-digit operands): ");
    scanf("%s", exp);

    printf("Result = %d\n", evaluatePostfix(exp));

    return 0;
}