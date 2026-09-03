#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

struct Node* newNode(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct ll
{
    struct Node* head,* tail;
    size_t size;
};

struct ll* newLL()
{
    struct ll* temp = (struct ll*)malloc(sizeof(struct ll));
    temp->head = NULL;
    temp->tail = NULL;
    temp->size = 0;
    return temp;
}

void insertAtBegin(struct ll* ll, int data)
{
    struct Node* temp = newNode(data);
    temp->next = ll->head;
    ll->head = temp;
    if(ll->tail == NULL)
        ll->tail = temp;
    ll->size++;
    return;
}

void insertAtEnd(struct ll* ll, int data)
{
    if(ll->head == NULL)
    {
        insertAtBegin(ll, data);
        return;
    }
    struct Node* temp = newNode(data);
    ll->tail->next = temp;
    ll->tail = temp;
    ll->size++;
    return;
}

void insertAtPos(struct ll* ll, int data, int pos)
{
    if(ll->head == NULL || pos <= 0)
    {
        insertAtBegin(ll, data);
        return;
    }
    if(pos >= ll->size)
    {
        insertAtEnd(ll, data);
        return;
    }
    struct Node* curr = ll->head;
    for(int i = 0; i < pos - 1; i++)
    {
        curr = curr->next;
    }
    struct Node* temp = newNode(data);
    temp->next = curr->next;
    curr->next = temp;
    ll->size++;
    return;
}

void insertAfterK(struct ll* ll, int data, int k)
{
    if(ll->head == NULL)
    {
        insertAtBegin(ll, data);
        return;
    }
    struct Node* curr = ll->head;
    while(curr != NULL && curr->data != k)
    {
        curr = curr->next;
    }
    if(curr == NULL || curr == ll->tail)
    {
        insertAtEnd(ll, data);
        return;
    }
    struct Node* temp = newNode(data);
    temp->next = curr->next;
    curr->next = temp;
    ll->size++;
    return;
}

void insertBeforeK(struct ll* ll, int data, int k)
{
    if(ll->head == NULL || ll->head->data == k)
    {
        insertAtBegin(ll, data);
        return;
    }
    struct Node* curr = ll->head;
    while(curr->next != NULL && curr->next->data != k)
    {
        curr = curr->next;
    }
    if(curr->next == NULL)
    {
        insertAtBegin(ll, data);
        return;
    }
    struct Node* temp = newNode(data);
    temp->next = curr->next;
    curr->next = temp;
    ll->size++;
    return;
}

void deleteAtBegin(struct ll* ll)
{
    if(ll->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = ll->head;
    ll->head = ll->head->next;
    free(temp);
    ll->size--;
    if(ll->head == NULL)
    {
        ll->tail = NULL;
    }
    return;
}

void deleteAtEnd(struct ll* ll)
{
    if(ll->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(ll->head == ll->tail)
    {
        free(ll->head);
        ll->head = NULL;
        ll->tail = NULL;
        ll->size--;
        return;
    }
    struct Node* curr = ll->head;
    while(curr->next != ll->tail)
    {
        curr = curr->next;
    }
    free(ll->tail);
    curr->next = NULL;
    ll->tail = curr;
    ll->size--;
    return;
}

void deleteAtPos(struct ll* ll, int pos)
{
    if(ll->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(pos <= 0)
    {
        deleteAtBegin(ll);
        return;
    }
    if(pos >= ll->size - 1)
    {
        deleteAtEnd(ll);
        return;
    }
    struct Node* curr = ll->head;
    for(int i = 0; i < pos - 1; i++)
    {
        curr = curr->next;
    }
    struct Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    ll->size--;
    return;
}

void deleteK(struct ll* ll, int k)
{
    if(ll->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(ll->head->data == k)
    {
        deleteAtBegin(ll);
        return;
    }
    struct Node* curr = ll->head;
    while(curr->next != NULL && curr->next->data != k)
    {
        curr = curr->next;
    }
    if(curr->next == NULL)
    {
        deleteAtEnd(ll);
        return;
    }
    struct Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    ll->size--;
    if(curr->next == NULL)
    {
        ll->tail = curr;
    }
    return;
}

void display(struct ll* ll)
{
    if(ll->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node* curr = ll->head;
    while(curr != NULL)
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
    return;
}

int main()
{
    struct ll* list = newLL();
    int choice, data, pos, k;
    while(1)
    {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Insert after k\n");
        printf("5. Insert before k\n");
        printf("6. Delete at beginning\n");
        printf("7. Delete at end\n");
        printf("8. Delete at position\n");
        printf("9. Delete k\n");
        printf("10. Display\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBegin(list, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(list, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPos(list, data, pos);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter k: ");
                scanf("%d", &k);
                insertAfterK(list, data, k);
                break;
            case 5:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter k: ");
                scanf("%d", &k);
                insertBeforeK(list, data, k);
                break;
            case 6:
                deleteAtBegin(list);
                break;
            case 7:
                deleteAtEnd(list);
                break;
            case 8:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPos(list, pos);
                break;
            case 9:
                printf("Enter k: ");
                scanf("%d", &k);
                deleteK(list, k);
                break;
            case 10:
                display(list);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
