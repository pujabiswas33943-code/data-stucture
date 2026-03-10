#include<stdio.h>
#include<stdlib.h>
#define MAX 5;
struct node {
    int data;
    struct node *link;
};
//int stack_arr[MAX];
struct node *top=NULL;
void push(int data){
    struct node *newnode;
  newnode = malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Stack Overflow");
        exit(1);
    }
    newnode->data=data;

    newnode->link=top;
    top=newnode;

}
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }



    struct node *temp;
    temp=top;
    int val=temp->data;
    top=top->link;
    free(temp);
    temp=NULL;
    return val;
}
int peek()
{
    if(top==NULL)
    {
        printf("Stack underflow.");
        exit(1);
    }
    return top->data;
}
void print()
{

    struct node *temp;
    temp=top;
    printf("The stack elements are:");
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int main(){
int choice,data;
while(1)
{
    printf("1.Push\n");
     printf("2.Pop\n");
      printf("3.Print\n");
       printf("4.Peek\n");

       printf("5.Exit\n");
       printf("Enter your choice: ");
       scanf("%d",&choice);
       switch(choice){
   case 1:
    printf("Enter the element to be pushesd: ");
       scanf("%d",&data);
       push(data);
       break;

       case 2:
           data=pop();
    printf("Enter the element to be delete: ");
       scanf("%d",&data);

       break;

       case 3:
        print();
        break;
        case 4:

    if (top != NULL) {
        data = peek();
        printf("The top element is: %d\n", data);
    } else {
        peek();
    }
    break;
        case 5: exit(1);
        default: printf("Wrong choice\n");
        break;
       }

}
return 0;

}
