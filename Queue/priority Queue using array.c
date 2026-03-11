#include<stdio.h>
#define MAX 100
int data[MAX];
int priority[MAX];
int size=0;
void enqueue(int value,int pr)
{
    if(size==MAX)
    {
        printf("Priority Queue is full!\n");
        return;
    }
    data[size]=value;
    priority[size]=pr;
    size++;
    printf("Inserted:%d (priority %d)\n",value,pr);

}

int getHighestPriorityIndex(){
int i,highest=0;
for(i=1;i<size;i++){
    if(priority[i]>priority[highest]){
        highest =i;
    }
}
return highest;

}

void dequeue(){
if(size==0){
    printf("Priority Queue is empty!\n");
    return;
}
int index=getHighestPriorityIndex();
printf("Deleted element: %d(priority %d)\n",data[index],priority[index]);
for(int i=index;i<size-1;i++)
{
    data[i]=data[i+1];
    priority[i]= priority[i+1];

}
size--;
}

void display()
{
    if(size==0){

        printf("Priority Queue is empty!\n");
        return;
    }
    printf("\n Value\tPriority\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t%d\n",data[i],priority[i]);

    }
}

int main() {
    int choice, value, pr;

    while (1) {
        printf("\n===== Priority Queue Menu =====\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter priority: ");
            scanf("%d", &pr);
            enqueue(value, pr);
        }
        else if (choice == 2) {
            dequeue();
        }
        else if (choice == 3) {
            display();
        }
        else if (choice == 4) {
            printf("Exiting program...\n");
            break;
        }
        else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
