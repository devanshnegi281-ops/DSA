#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next,* prev;
};

struct Node* newNode(int d) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = d;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

struct ll{
    struct Node* head,* tail;
    size_t size;
};

struct ll* newLl(){
    struct ll* temp = (struct ll*)malloc(sizeof(struct ll));
    temp->head = NULL;
    temp->tail = NULL;
    temp->size = 0;
    return temp;
}

void insertAtHead(struct ll* ll, int d) {
    struct Node* temp = newNode(d);
    if (ll->head == NULL) {
        ll->head = temp;
        ll->tail = temp;
    } else {
        temp->next = ll->head;
        ll->head->prev = temp;
        ll->head = temp;
    }
    ll->size++;
    return;
}

void insertAtTail(struct ll* ll, int d) {
    struct Node* temp = newNode(d);
    if (ll->tail == NULL) {
        ll->head = temp;
        ll->tail = temp;
    } else {
        temp->prev = ll->tail;
        ll->tail->next = temp;
        ll->tail = temp;
    }
    ll->size++;
    return;
}

void insertAfterK(struct ll* ll, int k, int d) {
    if (ll -> head == NULL || ll -> tail -> data == k) {
        insertAtTail(ll, d);
        return;
    }
    struct Node* current = ll->head;
    while (current != NULL && current->data != k)
        current = current->next;
    if (current == NULL) {
        insertAtTail(ll, d);
        return;
    }
    struct Node* temp = newNode(d);
    temp->next = current->next;
    temp->prev = current;
    if (current->next != NULL)
        current->next->prev = temp;
    current->next = temp;
    ll ->size++;
    return;
}

void insertBeforeK(struct ll* ll,int k, int d) {
    if (ll -> head == NULL || ll -> head -> data == k) {
        insertAtHead(ll, d);
        return;
    }
    struct Node* current = ll->head;
    while (current != NULL && current->data != k)
        current = current->next;
    if (current == NULL) {
        insertAtHead(ll, d);
        return;
    }
    struct Node* temp = newNode(d);
    temp->next = current;
    temp->prev = current->prev;
    if (current->prev != NULL)
        current->prev->next = temp;
    current->prev = temp;
    ll ->size++;
    return;
}

void insertAtPosition(struct ll* ll, int pos, int d) {
    if (pos <= 0) {
        insertAtHead(ll, d);
        return;
    }
    if (pos >= ll->size) {
        insertAtTail(ll, d);
        return;
    }
    struct Node* current = ll->head;
    for (int i = 0; i < pos; i++)
        current = current->next;
    struct Node* temp = newNode(d);
    temp->next = current;
    temp->prev = current->prev;
    if (current->prev != NULL)
        current->prev->next = temp;
    current->prev = temp;
    ll ->size++;
    return;
}

void deleteFromHead(struct ll* ll) {
    if (ll->head == NULL)
    {
        printf("Underflow\n");
        return;
    }
    struct Node* temp = ll->head;
    ll->head = ll->head->next;
    if (ll->head != NULL)
        ll->head->prev = NULL;
    else
        ll->tail = NULL;
    free(temp);
    ll->size--;
    return;
}

void deleteFromTail(struct ll* ll) {
    if (ll->tail == NULL)
    {
        printf("Underflow\n");
        return;
    }
    struct Node* temp = ll->tail;
    ll->tail = ll->tail->prev;
    if (ll->tail != NULL)
        ll->tail->next = NULL;
    else
        ll->head = NULL;
    free(temp);
    ll->size--;
    return;
}

void deleteK(struct ll* ll, int k) {
    if (ll->head == NULL) {
        printf("Underflow\n");
        return;
    }
    struct Node* current = ll->head;
    while (current != NULL && current->data != k)
        current = current->next;
    if (current == NULL) {
        printf("Element not found\n");
        return;
    }
    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        ll->head = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;
    else
        ll->tail = current->prev;
    free(current);
    ll ->size--;
    return;
}

void deleteAtPosition(struct ll* ll, int pos) {
    if (ll->head == NULL) {
        printf("Underflow\n");
        return;
    }
    if (pos <= 0) {
        deleteFromHead(ll);
        return;
    }
    if (pos >= ll->size - 1) {
        deleteFromTail(ll);
        return;
    }
    struct Node* current = ll->head;
    for (int i = 0; i < pos; i++)
        current = current->next;
    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    ll ->size--;
    return;
}

void display(struct ll* ll) {
    if(ll -> head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* current = ll->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    return;
}

int main() {
    struct ll* ll = newLl();
    int choice, data, pos, k;
    while(1)
    {
        printf("1. Insert at head\n");
        printf("2. Insert at tail\n");
        printf("3. Insert after k\n");
        printf("4. Insert before k\n");
        printf("5. Insert at position\n");
        printf("6. Delete from head\n");
        printf("7. Delete from tail\n");
        printf("8. Delete element k\n");
        printf("9. Delete at position\n");
        printf("10. Display\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtHead(ll, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtTail(ll, data);
                break;
            case 3:
                printf("Enter k and data: ");
                scanf("%d %d", &k, &data);
                insertAfterK(ll, k, data);
                break;
            case 4:
                printf("Enter k and data: ");
                scanf("%d %d", &k, &data);
                insertBeforeK(ll, k, data);
                break;
            case 5:
                printf("Enter position and data: ");
                scanf("%d %d", &pos, &data);
                insertAtPosition(ll, pos, data);
                break;
            case 6:
                deleteFromHead(ll);
                break;
            case 7:
                deleteFromTail(ll);
                break;
            case 8:
                printf("Enter k: ");
                scanf("%d", &k);
                deleteK(ll, k);
                break;
            case 9:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(ll, pos);
                break;
            case 10:
                display(ll);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
