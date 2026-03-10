#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL, *tail = NULL;

void createlist() {
    int value;
    struct node *newnode;
    printf("Enter the value (-1 for end): ");
    scanf("%d", &value);

    while (value != -1) {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;
        newnode->prev = NULL;

        if (start == NULL) {
            start = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        printf("Enter the value (-1 for end): ");
        scanf("%d", &value);
    }
}

void display() {
    struct node *ptr = start;
    if (ptr == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void reverse() {
    struct node *ptr = tail;
    if (ptr == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->prev; // Important: prev pointer use korte hobe
    }
    printf("\n");
}

void delintermediate() {
    struct node *temp;
    struct node *temp2;
    int pos, i = 1;
    if (start == NULL) {
        printf("List empty.\n");
        return;
    }
    printf("Enter the position you want to del: ");
    scanf("%d", &pos);

    temp = start;
    // Position-e pouchhano
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position not found.\n");
        return;
    }

    // Node-ti jodi shuru-te hoy
    if (temp == start) {
        start = start->next;
        if (start != NULL) start->prev = NULL;
    }
    // Node-ti jodi shesh-e hoy
    else if (temp == tail) {
        tail = tail->prev;
        if (tail != NULL) tail->next = NULL;
    }
    // Node-ti jodi majhe hoy
    else {
            temp2=temp->prev;
        temp2->next=temp->next;
    temp->next->prev=temp2;
    }

    printf("Deleted %d\n", temp->data);
    free(temp);
}

int main() {
    createlist();

    printf("\nBefore Deletion:\n");
    printf("Normal order: ");
    display();
    printf("Reverse order: ");
    reverse();

    delintermediate();

    printf("\nAfter Deletion:\n");
    printf("Normal order: ");
    display();
    printf("Reverse order: ");
    reverse();

    return 0;
}
