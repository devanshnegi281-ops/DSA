#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeg(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    return head;
}

struct Node* insertAfterK(struct Node* head, int data, int k) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    struct Node* temp = head;
    do{
        if (temp->data == k)
            break;
        temp = temp->next;
    } while (temp != head);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* insertBeforeK(struct Node* head, int data, int k) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    do{
        if (temp->data == k)
            break;
        prev = temp;
        temp = temp->next;
    } while (temp != head);
    if(temp == head)
    {
        struct Node* last = head;
        while (last->next != head)
            last = last->next;
        last->next = newNode;
        newNode->next = head;
        return newNode;
    }
    prev->next = newNode;
    newNode->next = temp;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0)
        return insertAtBeg(head, data);
    struct Node* temp = head;
    for (int i = 1; i < position && temp->next != head; i++)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* insertAtMiddle(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    struct Node* slow = head;
    struct Node* fast = head;
    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != head && fast->next != head);
    newNode->next = slow->next;
    slow->next = newNode;
    return head;
}

struct Node* deleteAtBeg(struct Node* head) {
    if (head == NULL)
        return NULL;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL)
        return NULL;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != head)
        temp = temp->next;
    free(temp->next);
    temp->next = head;
    return head;
}

struct Node* deleteAfterK(struct Node* head, int k) {
    if (head == NULL)
        return NULL;
    struct Node* temp = head;
    do{
        if (temp->data == k)
            break;
        temp = temp->next;
    } while (temp != head);
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    return head;
}

struct Node* deleteBeforeK(struct Node* head, int k) {
    if (head == NULL)
        return NULL;
    struct Node* temp = head;
    struct Node* prev = NULL;
    do{
        if (temp->data == k)
            break;
        prev = temp;
        temp = temp->next;
    } while (temp != head);
    if (prev == NULL) {
        struct Node* last = head;
        while (last->next != head)
            last = last->next;
        struct Node* toDelete = last;
        last->next = head->next;
        free(toDelete);
        return head->next;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL)
        return NULL;
    if (position == 0)
        return deleteAtBeg(head);
    struct Node* temp = head;
    for (int i = 1; i < position && temp->next != head; i++)
        temp = temp->next;
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    return head;
}

struct Node* deleteAtMiddle(struct Node* head) {
    if (head == NULL)
        return NULL;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prev = NULL;
    do {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != head && fast->next != head);
    prev->next = slow->next;
    free(slow);
    return head;
}

void display(struct Node* head) {
    if (head == NULL)
        return;
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;
    head = insertAtBeg(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAfterK(head, 25, 20);
    head = insertBeforeK(head, 15, 20);
    head = insertAtPosition(head, 5, 0);
    display(head);

    head = insertAtMiddle(head, 22);
    display(head);

    head = deleteAtBeg(head);
    display(head);

    head = deleteAtEnd(head);
    display(head);

    head = deleteAfterK(head, 15);
    display(head);

    head = deleteBeforeK(head, 25);
    display(head);

    head = deleteAtPosition(head, 1);
    display(head);

    head = deleteAtMiddle(head);
    display(head);

    return 0;
}
