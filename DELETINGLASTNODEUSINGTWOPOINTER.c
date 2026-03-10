#include<stdio.h>
#include<stdlib.h>
struct node{
      int data;
      struct node *next;

};
struct node *start=NULL;
void createlist()
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

        }
        printf("Enter the value(-1 for end): ");
    scanf("%d", &value);
    }
    printf("NULL\n");
}
void display()
{
    struct node *ptr;
    ptr=start;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
     printf("NULL\n");
}
void dellastnode()#include<stdio.h>
#include<stdlib.h>
struct node{
      int data;
      struct node *next;

};
struct node *start=NULL;
void createlist()
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

        }
        printf("Enter the value(-1 for end): ");
    scanf("%d", &value);
    }
    printf("NULL\n");
}
void display()
{
    struct node *ptr;
    ptr=start;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
     printf("NULL\n");
}
void dellastnode()
{
    struct node *temp,*temp2;
    if(start==NULL)
    {
        printf("List is empty.");
    }
    else if(start->next==NULL)
    {
        free(start);
        start=NULL;
    }
    else{
        temp2=start;
        temp=start;
        while(temp->next != NULL)
        {
            temp2=temp;
            temp=temp->next;
        }
        temp2->next=NULL;
        free(temp);
        temp=NULL;
    }
}
int main()
{
    createlist();
    display();
    dellastnode();
    display();
    return 0;
}
