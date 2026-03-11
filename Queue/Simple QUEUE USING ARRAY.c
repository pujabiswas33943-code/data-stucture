#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Function to add a new node (Enqueue)
void addNode() {
    int value;
    if (rear == SIZE - 1) {
        printf("Queue is Full!\n");
    } else {
        printf("Enter value to insert: ");
        scanf("%d", &value);

        if (front == -1)  // first element
            front = 0;

        rear++;
        queue[rear] = value;
        printf("%d added to the queue.\n", value);
    }
}

// Function to delete a node (Dequeue)
void deleteNode() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!\n");
    } else {
        printf("%d deleted from the queue.\n", queue[front]);
        front++;

        // Reset when queue becomes empty
        if (front > rear)
            front = rear = -1;
    }
}

// Function to display the queue
void displayQueue() {
    if (front == -1) {
        printf("Queue is Empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function with switch-case
int main() {
    int choice;

    do {
        printf("\n--- Array Queue Operations ---\n");
        printf("1. Add Node (Enqueue)\n");
        printf("2. Delete Node (Dequeue)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNode();
                break;
            case 2:
                deleteNode();
                break;
            case 3:
                displayQueue();
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
