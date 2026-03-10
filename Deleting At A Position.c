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
void dellastnode()
{
    struct node *current,*previous;
    int pos,i=1;
    if(start==NULL)
    {
        printf("\nList is empty\n");
    }
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    current=start;
    if(pos==1)
    {
        start=current->next;
        printf("\nDeleted: %d\n",current->data);
        free(current);
    }
    while(i<pos && current != NULL)
    {
        previous=current;
        current=current->next;
        i++;
    }
    if(current==NULL){
        printf("Invalid position!\n");
    }
    previous->next=current->next;
    printf("\nDeleted: %d\n",current->data);
    free(current);


}
int main()
{
    createlist();
    display();
    dellastnode();
    display();
    return 0;
}

