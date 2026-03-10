#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *prev;
struct node *next;

};

int main()
{
    struct node *head=NULL,*tail=NULL,*newnode;
    int i,value;
    for(i=1;i<=5;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d:",i);
        scanf("%d", &value);
        newnode->data=value;
        newnode->prev=NULL;
            newnode->next=NULL;
            if(head==NULL)
            {
                head=tail=newnode;
            }
            else{
                tail->next=newnode;
                newnode->prev=tail;
               tail= newnode;
            }
    }
    printf("\n Data in input order:\n");
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
    temp=temp->next;
}
    printf("\n Data in reverse order:\n");
    temp=tail;
    while(temp!=NULL){
        printf("%d ",temp->data);
    temp=temp->prev;
}
//REVERSE THE DOUBLY LINKED LIST
    struct node *current=head;
    while(current!=NULL)
    {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    if(temp!=NULL)
        head=temp->prev;   //now temp=4,,,head=5,,cz 4 er prev e 5 ache.

    printf("\nReversed Doubly Linked List:\n");
    current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    return 0;
}
