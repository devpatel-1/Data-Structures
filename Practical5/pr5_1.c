#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;


int isEmpty(){
    if (front == -1 || front > rear)
        return 1;
    return 0;
}


int isFull() {
    if (rear == MAX - 1)
        return 1;
    return 0;
}


void enqueue(int value) {
    if (isFull()) {
        printf("Queue is FULL!\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted %d into queue.\n", value);
    }
}


void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Deleted %d from queue.\n", queue[front]);
        front++;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}


int main() {
    int choice, value;

    while (1) {
        printf("\n------ Queue Menu -----\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Check Empty\n5. Check Full\n6. Exit\n");
        printf("Enter youe choice: ");
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
                    printf("Queue is FULL!");
                else
                    printf("Queue is NOT full.\n");
                break;
            
            case 6:
                exit(0);
            
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}