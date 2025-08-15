# include <stdio.h>
# include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;


void push();
void pop();
void isEmpty();
void isFull();
void display();
void exitProgram();


int main () {

    int choice;

    while (1) {
        printf("\n----- Stack Menu -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Is Empty\n");
        printf("4. Is Full\n");
        printf("5. Dispaly\n");
        printf("6. Exit\n");
        printf("Enter your choice (1 - 6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                isEmpty();
                break;
            case 4:
                isFull();
                break;
            case 5:
                display();
                break;
            case 6:
                exitProgram();
                break;
            default:
                printf("Enter a vaue between 1 to 6.\n");
        }
    }

    return 0;

}


void push() {
    int value;
    if (top == MAX - 1) {
        printf("Satck is full! Cannot push.\n");
    } else {
        printf("Enter a value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed to stack.\n", value);
    }
}


void pop() {
    if (top == -1) {
        printf("Stack is empty! Cannot pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}



void isEmpty() {
    if (top == -1)
        printf("Stack is empty.\n");
    else
        printf("Stack is not empty.\n");
}


void isFull() {
    if (top == MAX - 1)
        printf("Stack is full.\n");
    else
        printf("Stack is not full.\n");
}



void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}



void exitProgram() {
    printf("Exiting program...\n");
    exit(0);
}