#include<stdio.h>
#include<stdlib.h>
struct node{

   int data;
   struct node *prev;
   struct node *next;
};
struct node *start=NULL;
struct node *insertbeg(struct node *start)
{
    struct node *newnode;
    int value;
    printf("Enter value to insert at beginning:");
    scanf("%d", &value);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=NULL;
   newnode->next=start;
   start->prev=newnode;
   start=newnode;
   return start;
}
struct node *insertend(struct node *start)
{
    struct node *newnode,*ptr;
    int value;
    printf("Enter value to insert at end:");
    scanf("%d", &value);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=NULL;
    ptr=start;
    while(ptr->next != NULL)
        ptr=ptr->next;
    ptr->next=newnode;
    newnode->prev=ptr;
    return start;

}
struct node *createlist(struct node *start)
{
    struct node *newnode,*ptr;
    int n,i,data;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    if(n==0)
    {
        return NULL;
    }
    printf("Enter the elements of the node 1:");
    scanf("%d", &data);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    start = newnode;
    ptr = start;
    for(i=1; i<n; i++)
    {
        printf("Enter the element for the node %d: ",i+1);
        scanf("%d",&data);
      newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->prev = ptr;
        newnode->next = NULL;
        ptr->next = newnode;
        ptr = newnode;
    }
    return start;


}
struct node *insertintermediate(struct node *start)
{
    struct node *newnode,*temp,*temp2;
    int value,pos,i=1;
    printf("Enter value to insert between:");
    scanf("%d",&value);
    printf("Enter the position:");
    scanf("%d", &pos);
     newnode = (struct node *)malloc(sizeof(struct node));
     newnode->data=value;
     newnode->prev=NULL;
     newnode->next=NULL;
     temp=start;
     temp2=NULL;
     if(temp->next==NULL)
     {
         temp->next=newnode;
         newnode->prev=temp;
     }
     else{
        while(i<pos && temp!=NULL)
        {
            temp=temp->next;
            i++;
        }
        temp2=temp->next;
        temp->next=newnode;
        temp2->prev=newnode;
        newnode->prev=temp;
        newnode->next=temp2;
        return start;

     }
}
void display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr != NULL){
        printf("%d ",ptr->data);
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
    start->prev=NULL;
    return start;
}
struct node *delend(struct node *start)
{
    struct node *temp,*temp2;
    temp=start;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    return start;
}
struct node *delintermediate(struct node *start)
{
    struct node *temp,*temp2;
    int pos,i=1;
    printf("Enter the position for delete:");
    scanf("%d", &pos);
    temp=start;
    temp2=NULL;
    while(i<pos && temp!=NULL){
        temp=temp->next;
    i++;
    }
    temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    temp=NULL;


    return start;
}
struct node *reverse(struct node *start)
{
    struct node *ptr1,*ptr2;
    ptr1=start;
    ptr2=NULL;
    while(ptr2 != NULL)
    {
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    start=ptr1;
    return start;

}
int main()
{
    start=createlist(start);
    display(start);
    //start=insertbeg(start);
    //display(start);
    //start=insertend(start);
    //display(start);
    //start=insertintermediate(start);
    //display(start);
    //start=delfirst(start);
    //display(start);
    //start=delend(start);
    //display(start);
start=delintermediate(start);
    display(start);
start=reverse(start);
display(start);

}


