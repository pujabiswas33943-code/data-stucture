#define MAX 5
int queue[MAX];
int front=-1,rear=-1;

void joinLine(int personID){
   if((rear+1)%MAX==front){

    printf("Line Full! Ar manush newa jabe na.\n");
   }
   else{
    if(front==-1)
        front=0;
    rear=(rear+1)%MAX;
    queue[rear]=personID;
    printf("Person %d line e daralo.\n",personID);

   }

}

void giveTicket(){
 if(front==-1){
    printf("Line khali!kono manush nei.\n");

 }
 else{
    printf("Person %d ticket peye ber hoye gelo.\n",queue[front]);
  if(front==rear){
    front=rear=-1;
  }
  else{
    front=(front+1)%MAX;
  }
 }
}

void showLine(){
if(front==-1|| front>rear)
{
    printf("Line ekhon khali.\n");

}
else{
    printf("Ekhon line e achen: ");
    for(int i=front;i<=rear;i++)
    {

        printf("%d ",queue[i]);
    }
    printf("\n");
}
}
int main()
{
    joinLine(101);
     joinLine(102);
      joinLine(103);
       joinLine(104);

       showLine();
       giveTicket();
       showLine();

       return 0;
}
