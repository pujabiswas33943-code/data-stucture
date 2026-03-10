#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;

};
struct node *front=NULL;
    struct node *rear=NULL;
    void AddNode()
    {
        int value;
        printf("Enter the value you want to insert:");
        scanf("%d", &value);

        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->next=NULL;
        if(front==NULL){
            front=rear=newnode;
        rear->next=front;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
    printf("%d added to the circular queue.\n",value);

    }


    void deletenode()
    {
        if(front==NULL)
        {
            printf("Queue is empty.\n");
            return;
        }
        struct node *temp=front;
        if(front==rear)
        {
            printf("%d deleted from the queue.\n",front->data);
            front=rear=NULL;
            free(temp);
        }
        else
        {
              printf("%d deleted from the queue.\n",front->data);
              front=front->next;
              rear->next=front;
              free(temp);
        }
    }
    void display()
    {
        if(front==NULL)
        {
            printf("Queue is empty.\n");
            return;
        }
         struct node *temp=front;
         printf("Circular Queue elements are:");
         do
            {
                printf("%d",temp->data);
                temp=temp->next;
            }while(temp!=front);
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
        printf("The program is sucessfully exited.\n");
        break;
    default:
        printf("Invalid choice! TRy again.\n");
    }
    }
    return 0;
}

