#include<stdio.h>
#include<stdlib.h>
struct node{
      int data;
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
struct node * insertatposition(struct node* start){
struct node *newnode,*p;
int value,pos,i=1;
printf("Enter value to insert: ");
scanf("%d", &value);
printf("Enter position: ");
scanf("%d", &pos);

newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=value;
if(pos==1)
{
    newnode->next=start;
    start=newnode;
    return start;
}
else
{
    p=start;
    while(i<pos-1 && p != NULL)
    {
        p=p->next;
        i++;
    }
    

}
 newnode->next=p->next;
    p->next=newnode;

return start;


}
int main()
{
   start= createlist(start);     //সংক্ষেপে, start = লিখে আপনি ফাংশনের ভেতরে যে পরিবর্তনটি হয়েছে, তা গ্লোবাল start ভ্যারিয়েবলে আপডেট করে দেন। এটি না করলে আপনার তৈরি করা লিস্টটি main() ফাংশনটি "হারিয়ে ফেলবে"।








    display(start);
   start= insertatposition(start);
    display(start);
    return 0;
}
