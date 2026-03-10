#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *start = NULL;

struct node* createlist(struct node* start) {
    struct node *newnode, *ptr;
    int value;
    printf("Enter the value(-1 for end): ");
    scanf("%d", &value);
    while(value != -1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->prev = NULL; // নতুন নোডের prev NULL হবে
        newnode->next = NULL;
        if(start == NULL) {
            start = newnode;
        } else {
            ptr = start;
            while(ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->prev = ptr;
        }
        printf("Enter the value(-1 for end): ");
        scanf("%d", &value);
    }
    return start;
}

void display(struct node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return; // Void ফাংশন থেকে শুধুমাত্র return; ব্যবহার করা যায়।
    }
    struct node *ptr;
    ptr = start;
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node* reverse(struct node *start) {
    if (start == NULL) {
        return NULL; // খালি লিস্টের জন্য NULL রিটার্ন করা
    }

    struct node *current = start;
    struct node *temp = NULL;

    // প্রতিটি নোডের next এবং prev পয়েন্টার অদলবদল করা হচ্ছে
    while(current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // পরবর্তী নোডে যাওয়ার জন্য current কে আপডেট করা হচ্ছে
        current = current->prev; // রিভার্স হওয়ার পর, prev এখন নতুন next।
    }

    // লুপ শেষ হওয়ার পর, temp নতুন লিস্টের প্রথম নোড হবে
    // start কে নতুন প্রথম নোডে সেট করা হচ্ছে।
    if (temp != NULL) {
        start = temp->prev; // temp এর prev নতুন start কে নির্দেশ করে।
    }
    return start;
}

int main() {
    start = createlist(start);
    printf("Original list: ");
    display(start);

    start = reverse(start);
    printf("Reversed list: ");
    display(start);

    return 0;
}
