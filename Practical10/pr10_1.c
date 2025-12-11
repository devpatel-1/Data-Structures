#include <stdio.h>
#include <stdlib.h>

#define SIZE 10 // size of hash table

int hashTable[SIZE];

// Initialize hash table
void initialize() {
    for(int i = 0; i < SIZE; i++)
        hashTable[i] = -1; // -1 means empty
}

// Simple hash function
int hash(int key) {
    return key % SIZE;
}

// Insert key into hash table
void insert(int key) {
    int index = hash(key);
    int i = 0;

    while(hashTable[(index + i) % SIZE] != -1) {
        i++;
        if(i == SIZE) {
            printf("Hash table full!\n");
            return;
        }
    }
    hashTable[(index + i) % SIZE] = key;
    printf("Inserted %d at index %d\n", key, (index + i) % SIZE);
}

// Search key in hash table
int search(int key) {
    int index = hash(key);
    int i = 0;

    while(hashTable[(index + i) % SIZE] != -1) {
        if(hashTable[(index + i) % SIZE] == key)
            return (index + i) % SIZE;
        i++;
        if(i == SIZE) return -1;
    }
    return -1;
}

// Display hash table
void display() {
    printf("\nHash Table:\n");
    for(int i = 0; i < SIZE; i++) {
        if(hashTable[i] != -1)
            printf("Index %d : %d\n", i, hashTable[i]);
        else
            printf("Index %d : EMPTY\n", i);
    }
}

int main() {
    int choice, key, result;
    initialize();

    while(1) {
        printf("\n--- Hashing Menu ---\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                result = search(key);
                if(result != -1)
                    printf("%d found at index %d\n", key, result);
                else
                    printf("%d not found in hash table\n", key);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}