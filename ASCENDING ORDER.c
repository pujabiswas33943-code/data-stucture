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
 while(value!=-1)
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
void display(){
struct node *ptr=start;
while(ptr!=NULL)
{
    printf("%d ",ptr->data);
    ptr=ptr->next;
}
printf("NULL\n");
}
void sortlist(){
struct node *i,*j;
int temp;
for(i=start;i!=NULL;i=i->next)
{
    for(j=i->next;j!=NULL;j=j->next){
  if(i->data>j->data){
        temp=i->data;
      i->data=j->data;
      j->data=temp;
      }
  }
}
}

int main()
{

    createlist();
     printf("Before sorting: ");
    display();
    printf("After sorting: ");
    sortlist();
    display();
}
