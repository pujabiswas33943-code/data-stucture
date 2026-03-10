//for loop diye korbo

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

struct node *delfirst(struct node *start)
{
    if(start==NULL)
    {
        printf("List is empty,nothing to delete.");
        return NULL;
    }
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
    ptr = ptr->next;
    }
    ptr->next = start->next;
    free(start);
    start=ptr->next;
    return start;
}
struct node *delend(struct node *start)
{
    if(start==NULL)
    {
        printf("List is empty,nothing to delete.");
        return NULL;
    }
    struct node *ptr,*preptr;
    ptr=start;
    while(ptr->next!=start){
            preptr=ptr;
    ptr = ptr->next;
    }
    preptr->next = start;
    free(ptr);

    return start;
}
struct node *delintermediate(struct node *start)
{
    struct node *preptr,*ptr;
    int value,i;
    printf("Enter the value you want to delete: ");
    scanf("%d", &value);
    if(start==NULL)
    {
        printf("There is no value to delate.\n");
        return NULL;
    }
    preptr=start;
    ptr=start->next;
    while(ptr!=start && ptr->data!=value)
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
      //start=delfirst(start);
      //display(start);
      //start=delend(start);
      //display(start);

      start=delintermediate(start);
      printf("After deleting node:");
      display(start);

      return 0;
  }
