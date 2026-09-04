#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void deleteMiddle(struct Node** head)
{
    if (*head == NULL || (*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* slow = *head;
    struct Node* fast = (*head)->next->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct Node* temp = slow->next;
    slow->next= slow->next->next;
    free(temp);
    return;
}

void printList(struct Node* head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node* head;
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    printf("Original List:\n");
    printList(head);
    deleteMiddle(&head);
    printf("After Deleting Middle Node:\n");
    printList(head);
    return 0;
}
