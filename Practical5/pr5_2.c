#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Check if queue is full (allowing all MAX elements)
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (rear + 1 == front));
}

// Insert element into circular queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is FULL!\n");
    } else {
        if (front == -1)  // First element
            front = 0;

        if (rear == MAX - 1 && front != 0) // wrap around
            rear = 0;
        else
            rear++;

        queue[rear] = value;
        printf("Inserted %d into queue.\n", value);
    }
}

// Delete element from circular queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Deleted %d from queue.\n", queue[front]);
        if (front == rear) {  // Only one element
            front = rear = -1;
        } else if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
}

// Display queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
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
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Check Empty\n5. Check Full\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            if (isEmpty())
                printf("Queue is EMPTY!\n");
            else
                printf("Queue is NOT empty.\n");
            break;
        case 5:
            if (isFull())
                printf("Queue is FULL!\n");
            else
                printf("Queue is NOT full.\n");
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}