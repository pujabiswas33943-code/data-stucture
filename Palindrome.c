#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack_arr[MAX];
int top=-1;
int isEmpty() {
    return (top == -1);
}
int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
void push(char data)
{
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    top=top+1;
    stack_arr[top]=data;
}
int pop()
{
    int value;
    if(isEmpty())
    {
        printf("Stack underflow\n");
        exit(1);
    }
    value=stack_arr[top];
    top=top-1;
    return value;
}
int main()
{
    char s[100];
    printf("Enter the String: ");
    scanf("%s", &s);
    palindrom_check(s);
    return 0;
}
void palindrom_check(char *s){
 int i=0;
 while(s[i] != 'x'){
    push(s[i]);
    i++;
 }
 i++;
 while(s[i])
 {
     if(isEmpty() || s[i] != pop()){
        printf("Not a palindrome.");
        exit(1);
     }
     i++;
 }
if(isEmpty())
{
      printf("palindrome.");
}
else
{
      printf("Not a palindrome.");
}
}

