#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Check if queue is full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Insert element at rear
void insertRear(int value) {
    if (isFull()) {
        printf("DEQueue is FULL!\n");
    } else {
        if (front == -1) { // first element
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = value;
        printf("Inserted %d at REAR.\n", value);
    }
}

// Insert element at front
void insertFront(int value) {
    if (isFull()) {
        printf("DEQueue is FULL!\n");
    } else {
        if (front == -1) { // first element
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }
        deque[front] = value;
        printf("Inserted %d at FRONT.\n", value);
    }
}

// Delete element from front
void deleteFront() {
    if (isEmpty()) {
        printf("DEQueue is EMPTY!\n");
    } else {
        printf("Deleted %d from FRONT.\n", deque[front]);
        if (front == rear) { // only one element
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

// Delete element from rear
void deleteRear() {
    if (isEmpty()) {
        printf("DEQueue is EMPTY!\n");
    } else {
        printf("Deleted %d from REAR.\n", deque[rear]);
        if (front == rear) { // only one element
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear--;
        }
    }
}

// Display DEQueue
void display() {
    if (isEmpty()) {
        printf("DEQueue is EMPTY!\n");
    } else {
        printf("DEQueue elements: ");
        int i = front;
        while (1) {
            printf("%d ", deque[i]);
            if (i == rear)
                break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

// Main function with menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- DEQueue Menu ---\n");
        printf("1. Insert at Rear\n");
        printf("2. Insert at Front\n");
        printf("3. Delete from Rear\n");
        printf("4. Delete from Front\n");
        printf("5. Display\n");
        printf("6. Check Empty\n");
        printf("7. Check Full\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertRear(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertFront(value);
            break;
        case 3:
            deleteRear();
            break;
        case 4:
            deleteFront();
            break;
        case 5:
            display();
            break;
        case 6:
            if (isEmpty())
                printf("DEQueue is EMPTY!\n");
            else
                printf("DEQueue is NOT empty.\n");
            break;
        case 7:
            if (isFull())
                printf("DEQueue is FULL!\n");
            else
                printf("DEQueue is NOT full.\n");
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}