#include<stdio.h>
#include<stdlib.h>

struct node{

int data;
int priority;
struct node* next;
};
struct node* front=NULL;

struct node* newnode(int d,int p)
{
    struct node* temp=(struct node* )malloc(sizeof(struct node));
    temp->data=d;
    temp->priority=p;
    temp->next=NULL;
    return temp;
}
// Function to insert node according to priority
void enqueue(int d,int p){
  struct node* temp=newnode(d,p);
  if(front==NULL || p>front->priority){

    temp->next=front;
    front=temp;
  }
  else{
     struct node* start=front;

     while(start->next != NULL && start->next->priority>=p)
        start=start->next;
     temp->next=start->next;
     start->next=temp;
  }
  printf("Inserted: %d(priority %d)\n",d,p);
}

void dequeue()
{
    if(front==NULL)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    struct node* temp = front;
    printf("Deleted element: %d (Priority %d)\n", temp->data, temp->priority);
    front = front->next;
    free(temp);

}

void display()
{
    if(front==NULL)
    {
        printf("Priority Queue is empty!\n");
        return;
    }

    struct node* temp = front;
    printf("\nValue\tPriority\n");
    while(temp!=NULL)
    {
        printf("%d\t%d\n",temp->data,temp->priority);
        temp=temp->next;
    }

}

int main() {
    int choice, value, pr;

    while (1) {
        printf("\n===== Priority Queue (Linked List) Menu =====\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter priority: ");
            scanf("%d", &pr);
            enqueue(value, pr);
        }
        else if (choice == 2) {
            dequeue();
        }
        else if (choice == 3) {
            display();
        }
        else if (choice == 4) {
            printf("Exiting program...\n");
            break;
        }
        else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
