#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
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
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=value;
           newnode->prev=NULL;
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
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
void searchvalue(struct node *start)
{
    struct node *temp;
    int pos=1;
    int value;
    int found=0;
    printf("Enter the searching value:");
    scanf("%d", &value);
    //printf("Enter the position: ");
   // scanf("%d", &pos);
    temp=start;
    while( temp != NULL)
    {
        if(temp->data==value)
            {
                printf("value %d found at position %d\n ",value,pos);
                found=1;
                break;
            }
            temp=temp->next;
            pos++;
            return start;
    }
    if(found!=1){
    printf("the value is not found.");
    }
}
int main()
{
    start=createlist(start);
    display(start);
searchvalue(start);
   return 0;

}
