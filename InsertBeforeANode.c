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
void insertafterposition()
{
    struct node *newnode,*p;
    int value,info;
    printf("Enter value to insert: ");
scanf("%d", &value);
printf("Enter the value you want to insert before: ");
scanf("%d", &info);

newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=value;
p=start;
while(p->next != NULL)
{
    if(p->next->data==info)
        break;
    p=p->next;
}
newnode->next=p->next;
p->next=newnode;
}

int main()
{
    createlist();
    insertafterposition();
    display();
    return 0;
}
