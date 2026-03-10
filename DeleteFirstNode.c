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
void delFirst()
{
    struct node *temp;
    temp=start;
    if(start==NULL)
    {
        printf("List is already empty.");
    }
    else{
        start=start->next;
        printf("deleted:%d\n",temp->data);
        free(temp);
    }
}
int main()
{
    createlist();
    display();
    delFirst();
    display();
    return 0;
}
