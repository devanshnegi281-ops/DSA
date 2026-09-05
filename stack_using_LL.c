#include <stdio.h>
#include <stdlib.h>
#define max 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct ll {
    struct Node* head,* tail;
    size_t size;
};

struct ll* newLL() {
    struct ll* temp = (struct ll*)malloc(sizeof(struct ll));
    temp->head = NULL;
    temp->tail = NULL;
    temp->size = 0;
    return temp;
}

void Push(struct ll* ll, int data) {
    struct Node* temp = newNode(data);
    temp->next = ll->head;
    ll->head = temp;
    if(ll->tail == NULL)
        ll->tail = temp;
    ll->size++;
    return;
}

void Pop(struct ll* ll) {
    if(ll->head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = ll->head;
    ll->head = ll->head->next;
    free(temp);
    ll->size--;
    if(ll->head == NULL)
        ll->tail = NULL;
    return;
}

void display(struct ll* ll) {
    if(ll->head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* curr = ll->head;
    printf("Stack Elements : ");
    while(curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
    return;
}

void peek(struct ll* ll) {
    if(ll->head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d\n", ll->head->data);
    return;
}

int main() {
    struct ll* stack = newLL();
    int choice, data;
    while(1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                Push(stack, data);
                break;
            case 2:
                Pop(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                peek(stack);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
