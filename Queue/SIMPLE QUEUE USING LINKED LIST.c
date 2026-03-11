#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Front and Rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue operation
void enqueue() {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted successfully.\n", value);
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("Queue is Empty!\n");
    } else {
        struct Node* temp = front;
        printf("%d deleted from queue.\n", temp->data);
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        free(temp);
    }
}

// Display operation
void display() {
    if (front == NULL) {
        printf("Queue is Empty!\n");
    } else {
        struct Node* temp = front;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n--- Queue using Linked List ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
