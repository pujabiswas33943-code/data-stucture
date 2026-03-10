#include<stdio.h>
#include<stdlib.h>
struct node{
     int data;
     struct node *next;

};
struct node *start=NULL;
    struct node *createlist(struct node *start)
    {
        struct node *newnode,*ptr;
        int value;
        printf("Enter the value(-1 for end): ");
        scanf("%d", &value);
        while(value != -1)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=value;
            newnode->next=NULL;
                if(start==NULL)
                {
                    start=newnode;
                }
                else
                {
                    ptr=start;
                    while(ptr->next != NULL)
                        ptr=ptr->next;
                    ptr->next=newnode;

                }
                 printf("Enter the value(-1 for end): ");
        scanf("%d", &value);
        }
        return start;
    }

void display(struct node *start)
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        ptr=start;
        while(ptr != NULL){
            printf("%d ", ptr->data);
        ptr=ptr->next;}
    }
}
struct node *insertend(struct node *start)
{
     struct node *newnode,*ptr;
        int value;
        printf("Enter the value insert at end: ");
        scanf("%d", &value);
        ptr=start;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->next=NULL;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        return start;
}
struct node *insertafter(struct node *start){
  struct node *newnode,*ptr;
        int value,i,pos;
        printf("\nEnter the value to insert: ");
        scanf("%d", &value);
        printf("\nEnter the position to insert after this: ");
        scanf("%d", &pos);

        ptr=start;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->next=NULL;
        for(i=1 ; i<pos-1 && ptr!=NULL ; i++)
        {
            ptr=ptr->next;

        }

        newnode->next=ptr->next;
         ptr->next=newnode;
        return start;
}
struct node *delintermediate(struct node *start)
{
    struct node *temp,*temp2;
    int pos,i=1;
    printf("Enter the position you wnat to del:");
    scanf("%d",&pos);
    temp=start;
    temp2=start;


   while(i<pos-1 && temp != NULL)
   {
       temp2=temp;
       temp=temp->next;
       i++;

   }
   temp2->next = temp->next;
    printf("\nDeleted %d\n",temp->data);
    free(temp);
    return start;

}
struct node *delentire(struct node *start){
    struct node *temp=start;
    while(temp != NULL)
    {
        temp=temp->next;
        free(start);
        start=temp;
    }
    return start;

}
struct node *reverse(struct node *start)
{
    struct node *prev=NULL;
     struct node *next=NULL;
     while(start != NULL)
     {
         next=start->next;
         start->next=prev;
         prev=start;
         start=next;
     }
    start=prev;
    printf("\n");
    return start;

}
int main()
{
    start=createlist(start);
    display(start);
     //start=insertend(start);
   // display(start);
    //start=insertafter(start);
    //display(start);
//start=delintermediate(start);
    //display(start);
    //start=delentire(start);
    //display(start);
    //printf("Linked list succesfully deleted.");
    start=reverse(start);
    display(start);
}
