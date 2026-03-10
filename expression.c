#include<stdio.h>
 #include<string.h>
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
int match_char(char a,char b){
    if(a=='[' && b==']')
        return 1;
         if(a=='{' && b=='}')
        return 1;
         if(a=='(' && b==')')
        return 1;
        else
            return 0;
}

int check_balanced(char *s)
{
    char temp;
    int i;
    for(i=0; i<strlen(s); i++)
    {
        if(s[i]=='[' || s[i]=='{' || s[i]=='(' )
            push(s[i]);
        if(s[i]==']' || s[i]=='}' || s[i]==')' )
        {
            if(isEmpty())
            {
                printf("Right brackets are more than left brackets.");
                return 0;
            }
            else{
                temp=pop();
                if(!match_char(temp,s[i])){
                    printf("Mismatched bracket.\n");
                    return 0;
                }
            }
        }
    }
    if(isEmpty())
    {
        printf("Brackets are well balanced.\n");
        return 1;
    }
    else{
         printf("Left brackets are more than Right brackets.");
                return 0;
    }
}
int main()
{
    char exp[MAX];
    int balanced;
    printf("Enter the expression: ");
    gets(exp);
    balanced=check_balanced(exp);
    if(balanced==1)
        printf("The expression is valid.");
    else
    printf("The expression is not valid.");
    return 0;
}
