#include<stdio.h>
#include<stdlib.h>
#define N 10
int queue[N];

int front=-1;int rear=-1;

void enqueueFront(int value)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[front]=value;
    }
    else if((rear+1)%N==front)
    {
        printf("Queue is Full!\n");
        return;
    }
    else if(front==0)
    {
        front=N-1;
        queue[front]=value;
    }
    else
    {
        front--;
        queue[front]=value;
    }
}

void enqueueRear(int value)
{
    if((rear+1)%N==front){
        printf("Queue is Empty.\n");
        return;
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=-1;
        queue[rear]=value;
    }
    else if(rear==N-1)
    {
        rear=(rear+1)%N;
         queue[rear]=value;
    }
    else
    {
        rear++;
      queue[rear]=value;
    }
}

void display()
{
    int i=front;
    if((front==-1 && rear==-1))
    {
        printf("Queue is empty.\n");

    }
    else{
    while(i!=rear)
    {
        printf("%d ",queue[i]);
        i=(i+1)%N;
    }
    printf("%d ",queue[i]);
    }
    printf("\n");


}

void dequeueFront()
{
  if((front==-1 && rear==-1))
    {
        printf("Queue is empty.\n");

    }
    else if(front==rear)
    {
        printf("Deleted value is : %d",queue[front]);
        front=rear=-1;
    }
        else if(front==N-1)
    {
        printf("Deleted value is : %d",queue[front]);
        front=0;
    }
    else{
         printf("Deleted value is : %d",queue[front]);
         front++;
    }
}
void dequeueRear()
{
  if((front==-1 && rear==-1))
    {
        printf("Queue is empty.\n");

    }
    else if(front==rear)
    {
        printf("Deleted value is : %d",queue[rear]);
        front=rear=-1;
    }
    else if(rear==0){
        printf("Deleted value is : %d",queue[rear]);
        rear=N-1;
    }
    else{
        printf("Deleted value is : %d",queue[rear]);
        rear--;
    }
}
void getrear(){
    if(front== -1 && rear== -1){
        printf("deque is empty\n");
    }
    else{
        printf("rear value is=%d\n",queue[rear]);
    }
}
void getfront(){
    if(front== -1 && rear== -1){
        printf("deque is empty\n");
    }
    else{
        printf("rear value is=%d\n",queue[front]);
    }
}

int main(){
 while (1)
    {
        printf("1.enqueue_front 2.enqueue_rear 3.dequeue_front 4.dequeue_rear 5.getfront 6.getrear 7.display 8.exit\n");
        printf("enter your choice:");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:{
            printf("give the value:");
            int value;
            scanf("%d",&value);
            enqueueFront(value);
            break;
        }
        case 2:{
            printf("give the value:");
            int value;
            scanf("%d",&value);
            enqueueRear(value);
            break;
        }
        case 3:
            dequeueFront();
            break;
        case 4:
            dequeueRear();
            break;
        case 5:
            getfront();
            break;
        case 6:
            getrear();
            break;
        case 7:
            display();
            break;
        case 8:
            return 0;
            break;
        default:
            printf("wrong choice");
            break;
        }
    }


}

