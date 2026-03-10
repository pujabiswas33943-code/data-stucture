#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int queue[SIZE];
int front=-1,rear=-1;
void AddNode(){
int value;
if((front==0 && rear==SIZE-1) || (rear+1)%SIZE==front)
{
    printf("Queue is full.");
}
else
{
    printf("Enter the value you want to insert:");
    scanf("%d",&value);

    if(front==-1)
        front=0;
    rear=(rear+1)%SIZE;
    queue[rear]=value;
    printf("%d added to the queue.\n" ,value);
}

}

void deletenode()
{
    if(front==-1)
    {
        printf("Queue is empty.");
    }
    else
    {
        printf("%d deleted from the queue.",queue[front]);
        if(front==rear)
        {
            front=rear=-1;

        }
        else
        {
            front=(front+1)%SIZE;
        }
    }
}

void display()
{
    if(front==-1)
    {
        printf("Queue is empty.\n");
    }
    printf("Queue elements are:");
    for(int i=front; i<=rear; i=(i+1)%SIZE)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int main()
{
    int choice;
    printf("CIRCular queue operations:\n");
    while(1){
    printf("1.AddNode\n");
    printf("2.DeleteNode\n");
    printf("3.DisplayNode\n");
    printf("4.Exit\n");
    printf("Enter your choice.\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        AddNode();
        break;
    case 2:
        deletenode();
        break;
    case 3:
        display();
        break;
    case 4:
        exit(1);
        break;
    default:
        printf("Invalid choice! TRy again.\n");
    }
    }
    return 0;
}

