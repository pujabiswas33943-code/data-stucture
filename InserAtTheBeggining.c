#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;

};
struct node *start=NULL;
    void createlist(){
    struct node *newnode,*ptr;
    int value;
    printf("Enter data(-1 to stop): ");
    scanf("%d",&value);
    while(value != -1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
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
          printf("Enter data(-1 to stop): ");
    scanf("%d",&value);
    }
    printf("NULL\n");
    }
    void display()
    {
        struct node *ptr=start;
        printf("\nLinked List: ");
        while(ptr != NULL)
        {
            printf("%d->",ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
    void insert_begin()
    {
        struct node *newnode;
        int value;
        printf("Enter value to insert at beginning: ");
        scanf("%d",&value);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->next=start;
        start=newnode;


    }
    int main()
    {
        createlist();
        insert_begin();
        display();
        return 0;
    }
