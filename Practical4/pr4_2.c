#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char expr[MAX], stack[MAX];
    int top = -1, i;
    int valid = 1;  // Assume expression is valid at start

    printf("Enter an expression: ");
    scanf("%[^\n]", expr);

    for (i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        // Push opening brackets
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        }
        // Check closing brackets
        else if (c == ')' || c == '}' || c == ']') {
            if (top == -1) {  // Stack empty → invalid
                valid = 0;
                break;
            }
            char last = stack[top--]; // Pop

            if ((c == ')' && last != '(') ||
                (c == '}' && last != '{') ||
                (c == ']' && last != '[')) {
                valid = 0;
                break;
            }
        }
    }

    // If still opening brackets left → invalid
    if (top != -1) {
        valid = 0;
    }

    if (valid)
        printf("The expression is VALID.\n");
    else
        printf("The expression is INVALID.\n");

    return 0;
}