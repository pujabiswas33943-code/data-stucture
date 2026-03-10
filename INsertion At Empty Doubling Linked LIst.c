#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *start=NULL;

void createlist()
{
     struct node *newnode;
    int value;
    printf("Enter data(-1 to stop): ");
    scanf("%d",&value);
    while(value != -1)
    {
      newnode=(struct node*)malloc(sizeof(struct node));
      newnode->data=value;
      newnode->prev=NULL;
      newnode->next=NULL;
      if(start==NULL)
      {
          start=newnode;
      }
      else
      {
          struct node *temp=start;
         while(temp->next != NULL)
            temp=temp->next;
          temp->next=newnode;
          newnode->prev=temp;
      }
       printf("Enter data(-1 to stop): ");
    scanf("%d",&value);

    }
}


void display()
{
    struct node *temp=start;
    if(temp==NULL)
    {
        printf("List is empty.\n");
    }
    printf("Doubly linked list: ");
    while(temp != NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    createlist();
    display();
    return 0;
}
