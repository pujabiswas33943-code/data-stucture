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

struct node *delfirst(struct node *start)

{
    struct node *temp;
    temp=start;
    start=start->next;
    free(temp);
    return start;
}

struct node *dellast(struct node *start)

{
    struct node *temp,*temp2;
    temp=start;
    while(temp->next!=NULL)
    {
    temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    return start;
}

    struct node *delatposition(struct node *start)

{
    struct node *temp,*temp2;
    temp=start;
    temp2=NULL;
    int value,pos,i=1;

printf("Enter position to delete: ");
scanf("%d", &pos);
if(pos==1)
{
    start=delfirst(start);
    return start;
}
    while(i<pos && temp!=NULL)
    {
    temp=temp->next;
    i++;
    }
    if(temp==NULL)
    {
        start=dellast(start);
    }
    else
    {

    temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    temp=NULL;
    }
    return start;
}

int main()
{
    start=createlist(start);
    display(start);
    //start=delfirst(start);
    //display(start);
    //start=dellast(start);
    //display(start);
    start=delatposition(start);
    display(start);
}
