#include<stdio.h>
#include<stdlib.h>
struct node{
      int data;
        struct node *prev;
      struct node *next;

};
struct node *start=NULL;
struct node* createlist(struct node*start)
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
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
    printf("\n");

}
struct node * insertbeforeposition(struct node* start){
struct node *newnode,*temp,*temp2;
int value,pos,i=1;
printf("Enter value to insert: ");
scanf("%d", &value);
printf("Enter position: ");
scanf("%d", &pos);
temp=start;
temp2=NULL;
newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=value;
if(pos==1)
{
    newnode->prev=NULL;
     newnode->next=start;
     start->prev=newnode;
     start=newnode;
    return start;
}
else
{
    temp=start;

   while (i < pos - 1 && temp != NULL) {                    //লুপটি pos-1 পর্যন্ত চলবে, যাতে temp পয়েন্টারটি ঠিক সেই নোডের উপর এসে থামে যার পরে নতুন নোডটি যুক্ত হবে।
        temp = temp->next;
        i++;
    }

    temp2=temp->next;
    temp->next=newnode;
    temp2->prev=newnode;
    newnode->next=temp2;
    newnode->prev=temp;
    return start;


}


}

int main()
{
    start=createlist(start);
    display(start);
    start=insertbeforeposition(start);
    display(start);
}
