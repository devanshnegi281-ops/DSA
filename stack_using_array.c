#include <stdio.h>
#include <stdlib.h>
#define max 100

int push(int stack[], int top, int d) {
    if(top == max -1)
    {
        printf("Stack Overflow\n");
        return top;
    }
    top ++;
    stack[top] = d;
    return top;
}

int pop(int stack[], int top) {
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return top;
    }
    printf("%d\n",stack[top]);
    top--;
    return top;
}

void peek(int stack[], int top) {
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n",stack[top]);
    return;
}

void display(int stack[], int top) {
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Stack Elements : ");
    while(top != -1)
        printf("%d -> ",stack[top--]);
    printf("\n");
    return;
}

int main() {
    int stack[max],top = -1,ch,value;
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter Value to Insert in Stack : ");
                scanf("%d",&value);
                top = push(stack,top,value);
                break;
            case 2:
                top = pop(stack,top);
                break;
            case 3:
                peek(stack,top);
                break;
            case 4:
                display(stack,top);
                break;
            case 5:
                exit(0);
            default :
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
