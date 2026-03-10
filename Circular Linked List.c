#include<stdio.h>
#include<stdlib.h>
// after a condition i<pos,...
//before er condition i<pos-1...
struct node {
    int data;
    struct node *next;
};

struct node *createlist(struct node *start) {
    struct node *newnode, *ptr;
    int value;

    printf("Enter the value (-1 for end): ");
    scanf("%d", &value);

    while (value != -1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return start;
        }
        newnode->data = value;

        if (start == NULL) {
            start = newnode;
            newnode->next = start; // First node points to itself
        } else {
            ptr = start;
            while (ptr->next != start) { // Traverse until the last node
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->next = start; // New node points to the first node
        }
        printf("Enter the value (-1 for end): ");
        scanf("%d", &value);
    }
    return start;
}

void display(struct node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *p = start;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != start); // Loop until we return to the start node
    printf("\n");
}
struct node *insertbeginnig(struct node *start)
{
    struct node *newnode,*tail;
      int value;
    printf("Enter value to insert at beginning: ");
    scanf("%d", &value);
   newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data=value;
        if(start==NULL)
        {
        newnode->next=newnode;
        start=newnode;
        return start;
        }
        else{
            tail=start;
            while(tail->next!=start){
                tail=tail->next;
            }
            newnode->next=start;
            tail->next=newnode;
            start=newnode;
            return start;
        }
}
struct node *insertend(struct node *start)
{
    struct node *newnode,*tail;
      int value;
    printf("Enter value to insert at end: ");
    scanf("%d", &value);
   newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data=value;
        if(start==NULL)
        {
        newnode->next=newnode;
        start=newnode;
        return start;
        }
        else
        {
            tail=start;
            while(tail->next!=start)
            {
                tail=tail->next;
            }
            tail->next=newnode;
            newnode->next=start;

            return start;
        }
}
struct node *insertafternode(struct node *start)
{
    struct node *newnode,*tail;
      int value,pos,i;
    printf("Enter value to insert : ");
    scanf("%d", &value);
    printf("Enter the position");
    scanf("%d", &pos);
   newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data=value;
        if(start==NULL)
        {
        newnode->next=newnode;
        start=newnode;
        return start;
        }
        else
        {
            tail=start;
            for(i=1; i<pos && tail->next!=start;i++){
                tail=tail->next
            }
            newnode->next=tail->next;
            tail->next=newnode;
            return start;
        }
}
struct node * insertatposition(struct node* start){
struct node *newnode,*p;
int value,pos,i=1;
printf("Enter value to insert: ");
scanf("%d", &value);
printf("Enter position: ");
scanf("%d", &pos);

newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=value;
if(pos==1)
{
    newnode->next=start;
    start=newnode;
    return start;
}
else
{
    p=start;
    while(i<pos-1 && p != NULL)//eta before a node er motoi ..input hisebe pos=3 dile,,pos=2 te jai loop break korbe then pos 2 er pore newnode add kre dibe,,
    {
        p=p->next;
        i++;
    }


}
 newnode->next=p->next;
    p->next=newnode;

return start;
}

int main() {
    struct node *start = NULL;
    start = createlist(start);
    printf("Circular Linked List: ");
    display(start);
    start=insertbeginnig(start);
    printf("Insert Beginning At Circular Linked List: ");
    display(start);
    start=insertend(start);
    printf("Insert End At Circular Linked List: ");
    display(start);
      start=insertafternode(start);
    printf("Insert after a node Circular Linked List: ");
    display(start);
          start=insertatposition(start);
    printf("Insert before a node Circular Linked List: ");
    display(start);

    return 0;
}
