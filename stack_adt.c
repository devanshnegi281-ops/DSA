#include <stdio.h>
#include <stdlib.h>
#define max 100

struct Stack {
    int top;
    int stack[max];
};

int push(struct Stack *s, int d) {
    if(s->top == max -1)
    {
        printf("Stack Overflow\n");
        return s->top;
    }
    s->top++;
    s->stack[s->top] = d;
    return s->top;
}

int pop(struct Stack *s) {
    if(s->top == -1)
    {
        printf("Stack Underflow\n");
        return s->top;
    }
    int d = s->stack[s->top];
    s->top--;
    return d;
}

void peek(struct Stack *s) {
    if(s->top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n",s->stack[s->top]);
    return;
}

void display(struct Stack *s) {
    if(s->top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Stack Elements : ");
    for(int i = s->top; i >= 0; i--)
        printf("%d -> ",s->stack[i]);
    printf("\n");
    return;
}

int main() {
    struct Stack s;
    s.top = -1;
    int ch, value;
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
                printf("Enter the value to be pushed : ");
                scanf("%d",&value);
                push(&s,value);
                break;
            case 2:
                value = pop(&s);
                if(value != -1)
                    printf("Popped element is : %d\n",value);
                break;
            case 3:
                peek(&s);
                break;
            case 4:
                display(&s);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
