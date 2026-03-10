#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;

};
struct node *start=NULL;
  struct node *createlist(struct node *start)
  {
      struct node *newnode,*ptr;
      int value,n,i;
      printf("Enter the number of nodes: ");
      scanf("%d", &n);
      if(n==0)
        return NULL;
      printf("Enter the value for 1st node:");
      scanf("%d", &value);
      start=(struct node*)malloc(sizeof(struct node));
      start->data=value;
      ptr=start;


      for(i=2; i<=n; i++){
        printf("Enter value for node %d: ",i);
        scanf("%d", &value);
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=value;
        ptr->next=newnode;
        ptr=newnode;
      }
      newnode->next=start;
      return start;

  }


  void display(struct node *start)
  {
      if(start==NULL){
        printf("The list is empty.\n");
      return;
      }
     struct node *p = start;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != start); // Loop until we return to the start node
    printf("\n");
}
struct node *delintermediate(struct node *start)
{
    struct node *preptr,*ptr;
    int pos,i;
    printf("Enter the position after which to delete the node: ");
    scanf("%d", &pos);
    if(start==NULL)
    {
        printf("There is no value to delate.\n");
        return NULL;
    }
    preptr=start;
    ptr=start->next;
    for(i=1;i<pos && ptr->next!=start; i++)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
}
int main()
{
    start=createlist(start);
    display(start);
    start=delintermediate(start);
    display(start);
}
