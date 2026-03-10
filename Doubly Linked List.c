#include<stdio.h>
#include<stdlib.h>
struct node{
      int data;
        struct node *prev;
      struct node *next;

};
struct node *start=NULL;
struct node* createlist(struct node*start)
{
    struct node *newnode,*ptr;
    int value;
    printf("Enter the value(-1 for end): ");
    scanf("%d", &value);
    while(value != -1)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->next=NULL;
        if(start==NULL)
        {
            start=newnode;
        }
        else{
            ptr=start;
            while(ptr->next != NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->prev=ptr;

        }
        printf("Enter the value(-1 for end): ");
    scanf("%d", &value);
    }
    return start;

}
void display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
    printf("\n");

}

struct node *insertbeg(struct node *start)
{
      struct node *newnode;
      int value;
    printf("Enter value to insert at beginning: ");
    scanf("%d", &value);
   newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->next=NULL;
         newnode->prev=NULL;
         newnode->next=start;
         start->prev=newnode;
         start=newnode;
         return start;
}
struct node *insertend(struct node *start)
{
      struct node *newnode,*ptr;
      int value;
    printf("Enter value to insert at end: ");
    scanf("%d", &value);
   newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->prev=NULL;
        newnode->next=NULL;

         ptr=start;
         while(ptr->next != NULL)
            {
                ptr=ptr->next;
            }
         ptr->next=newnode;
         newnode->prev=ptr;
         return start;
}

struct node * insertatafterposition(struct node* start){
struct node *newnode,*temp,*temp2;
int value,pos,i=1;
printf("Enter value to insert: ");
scanf("%d", &value);
printf("Enter position: ");
scanf("%d", &pos);
temp=start;
temp2=NULL;
newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=value;
if(temp->next==NULL)
{
    temp->next=newnode;
    newnode->prev=temp;
    return start;
}
else
{
    while(pos!=1)
    {
        temp=temp->next;
        pos--;
    }
    temp2=temp->next;
    temp->next=newnode;
    temp2->prev=temp;
    newnode->prev=temp;
    newnode->next=temp2;
    return start;


}

return start;
}

int main()
{
    start=createlist(start);
    display(start);
    start=insertbeg(start);
    display(start);
    start=insertend(start);
    display(start);
    start=insertatafterposition(start);
    display(start);

    return 0;
}
