#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
    return head;
}

struct Node* insertAfterK(struct Node* head, int data, int k) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    do {
        if (temp->data == k)
            break;
        temp = temp->next;
    } while (temp != head);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

struct Node* insertBeforeK(struct Node* head, int data, int k) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    do {
        if (temp->data == k)
            break;
        temp = temp->next;
    } while (temp != head);
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
    if (temp == head)
        return newNode;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position == 0)
        return insertAtBeginning(head, data);
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++)
        temp = temp->next;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

struct Node* insertAtMiddle(struct Node* head, int data) {
    if (head == NULL)
        return createNode(data);
    struct Node* slow = head;
    struct Node* fast = head;
    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != head && fast->next != head);
    return insertBeforeK(head, data, slow->data);
}

struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL)
        return NULL;
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    head->prev->next = head->next;
    head->next->prev = head->prev;
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
    struct Node* temp = head->prev;
    temp->prev->next = head;
    head->prev = temp->prev;
    free(temp);
    return head;
}

struct Node* deleteAfterK(struct Node* head, int k) {
    if (head == NULL)
        return NULL;
    struct Node* temp = head;
    do {
        if (temp->data == k)
            break;
        temp = temp->next;
    } while (temp != head);
    if (temp->next == head)
        return deleteAtEnd(head);
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    toDelete->next->prev = temp;
    free(toDelete);
    return head;
}

struct Node* deleteBeforeK(struct Node* head, int k) {
    if (head == NULL)
        return NULL;
    struct Node* temp = head;
    do {
        if (temp->data == k)
            break;
        temp = temp->next;
    } while (temp != head);
    if (temp->prev == head)
        return deleteAtBeginning(head);
    struct Node* toDelete = temp->prev;
    toDelete->prev->next = temp;
    temp->prev = toDelete->prev;
    free(toDelete);
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL)
        return NULL;
    if (position == 0)
        return deleteAtBeginning(head);
    struct Node* temp = head;
    for (int i = 1; i < position && temp->next != head; i++)
        temp = temp->next;
    if (temp == head)
        return deleteAtEnd(head);
    struct Node* toDelete = temp;
    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;
    free(toDelete);
    return head;
}

struct Node* deleteAtMiddle(struct Node* head) {
    if (head == NULL)
        return NULL;
    struct Node* slow = head;
    struct Node* fast = head;
    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != head && fast->next != head);
    return deleteBeforeK(head, slow->data);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    displayList(head);

    head = insertAtBeginning(head, 5);
    displayList(head);

    head = insertAfterK(head, 15, 10);
    displayList(head);

    head = insertBeforeK(head, 25, 30);
    displayList(head);

    head = deleteAtBeginning(head);
    displayList(head);

    head = deleteAtEnd(head);
    displayList(head);

    head = deleteAfterK(head, 15);
    displayList(head);

    head = deleteBeforeK(head, 20);
    displayList(head);

    head = deleteAtPosition(head, 1);
    displayList(head);

    head = deleteAtMiddle(head);
    displayList(head);

    return 0;
}