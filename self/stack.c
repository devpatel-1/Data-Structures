#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;


void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
        printf("%d pushed\n", item);
    }
}


void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped\n", stack[top--]);
    }
}


void peep(int pos) {
    int index = top - pos + 1;
    if (index < 0) {
        printf("Invalid Position\n");
    } else {
        printf("Element at position %d is %d\n", pos, stack[index]);
    }
}


void change(int pos, int value) {
    int index = top - pos + 1;
    if (index < 0) {
        printf("Invalid Position\n");
    } else {
        stack[index] = value;
        printf("Element at position %d changed to %d\n", pos, value);
    }
}


int main() {
    push(10);
    push(20);
    push(30);
    peep(2);     // Should show 20
    change(1, 99);    // Change top element (30 --> 99)
    pop();   // pops 99
    pop();   // pops 20
    pop();   // pops 10
    pop();   // Underflow
    return 0;
}




// Initial stage of stack is ... TOP = -1
//                               Stack = [empty]

//                               TOP = 0
//                               Stack:
//                               | 10 |   <- TOP

// TOP = 1
// Stack:
// | 20 |   <- TOP
// | 10 |



// TOP = 2
// Stack:
// | 30 |   <- TOP
// | 20 |
// | 10 |


// Step 4 → peep(2);
// 	•	Position 2 means: stack[top - 2 + 1] = stack[1] = 20
// Output: Element at position 2 is 20


// Stack (unchanged):
// | 30 |   <- TOP
// | 20 |
// | 10 |



// Step 5 → change(1, 99);
// 	•	Position 1 means top element → change 30 to 99.
// Output: Element at position 1 changed to 99


// TOP = 2
// Stack:
// | 99 |   <- TOP
// | 20 |
// | 10 |



// Step 6 → pop();
// 	•	Removes 99 (top element).
// Output: 99 popped


// TOP = 1
// Stack:
// | 20 |   <- TOP
// | 10 |


// Step 7 → pop();
// 	•	Removes 20.
// Output: 20 popped

// TOP = 0
// Stack:
// | 10 |   <- TOP



// Step 8 → pop();
// 	•	Removes 10.
// Output: 10 popped

// TOP = -1
// Stack = [empty]



// Step 9 → pop();
// 	•	Nothing left → Underflow.
// Output: Stack Underflow


// Stack = [empty]




// 10 pushed
// 20 pushed
// 30 pushed
// Element at position 2 is 20
// Element at position 1 changed to 99
// 99 popped
// 20 popped
// 10 popped
// Stack Underflow