#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* link;
};
struct node* front=NULL;
    struct node* rear=NULL;
    void enqueue(int value)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->link=NULL;
        if(front==NULL)
        {
            rear=newnode;
            front=newnode;
            rear->link=front;
        }
        else{
            rear->link=newnode;
            rear=newnode;
            rear->link=front;
        }
    }
    void dequeue(){
    struct node* temp=front;
    if(front==NULL)
    {
        printf("Queue is empty.\n");
    }
    else if(front==rear)
    {
        printf("Deleted element: %d",temp->data);
        front=rear=NULL;
        free(temp);
    }
    else{
        printf("Deleted element: %d",temp->data);
        front=front->link;
        rear->link=front;
        free(temp);
    }

    }
    void display()
    {
    struct node* temp=front;
    if(front==NULL)
    {
        printf("Queue is empty.\n");
    }
    else{
        while(temp->link!=front) //last node porjonto jabo
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }
           printf("%d ",temp->data);//last node print korar jonno
    }
    printf("\n");
    }
    void peek()
    {
        if(front==NULL)
        {
            printf("Queue is empty.\n");
        }
        else{
            printf("peek value=%d",front->data);

        }
    }

    int main()
    {
       while(1)
       {
           printf("1.Enqueue  2.Dequeue   3.Display  4.Exit\n");
           int choice;
           printf("Enter your choice:");
           scanf("%d",&choice);
           switch(choice)
           {
               case 1:{
                   int value;
               printf("Enter the value: ");
               scanf("%d",&value);
               enqueue(value);
               break;
               }
               case 2:dequeue();break;
               case 3:display();break;
               case 4:peek();break;
               case 5:return 0;
           default:printf("Wrong choice.");
           }
       }
        return 0;
    }
