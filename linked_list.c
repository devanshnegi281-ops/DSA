#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* newnode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertatbegin(struct node** head, int data)
{
    struct node* temp = newnode(data);
    if(*head == NULL)
    {
        *head = temp;
        return;
    }
    temp->next = *head;
    *head = temp;
    return;
}

void insertatend(struct node** head, int data)
{
    if(*head == NULL)
    {
        insertatbegin(head, data);
        return;
    }
    struct node* temp = newnode(data);
    struct node* curr = *head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return;
}

void insertatpos(struct node** head, int data, int pos)
{
    if(*head == NULL || pos <= 0)
    {
        insertatbegin(head, data);
        return;
    }
    struct node* curr = *head;
    for(int i = 0; i < pos - 1; i++)
    {
        if(curr == NULL)
        {
            insertatend(head, data);
            return;
        }
        curr = curr->next;
    }
    struct node* temp = newnode(data);
    temp->next = curr->next;
    curr->next = temp;
    return;
}

void insertafterk(struct node** head, int data, int k)
{
    if(*head == NULL)
    {
        insertatbegin(head, data);
        return;
    }
    struct node* curr = *head;
    while(curr != NULL && curr->data != k)
    {
        curr = curr->next;
    }
    if(curr == NULL)
    {
        insertatend(head, data);
        return;
    }
    struct node* temp = newnode(data);
    temp->next = curr->next;
    curr->next = temp;
    return;
}

void insertbeforek(struct node** head, int data, int k)
{
    if(*head == NULL)
    {
        insertatbegin(head, data);
        return;
    }
    if((*head)->data == k)
    {
        insertatbegin(head, data);
        return;
    }
    struct node* curr = *head;
    while(curr->next != NULL && curr->next->data != k)
    {
        curr = curr->next;
    }
    if(curr->next == NULL)
    {
        insertatbegin(head, data);
        return;
    }
    struct node* temp = newnode(data);
    temp->next = curr->next;
    curr->next = temp;
    return;
}

void deleteatbegin(struct node** head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
}

void deleteatend(struct node** head)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    struct node* curr = *head;
    while(curr->next->next != NULL)
    {
        curr = curr->next;
    }
    free(curr->next);
    curr->next = NULL;
    return;
}

void deleteatpos(struct node** head, int pos)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(pos == 0)
    {
        deleteatbegin(head);
        return;
    }
    struct node* curr = *head;
    for(int i = 0; i < pos - 1; i++)
    {
        if(curr->next == NULL)
        {
            deleteatend(head);
            return;
        }
        curr = curr->next;
    }
    struct node* temp = curr->next;
    //if(temp == NULL)
    //{
      //  printf("Position out of bounds\n");
       // return;
    //}
    curr->next = temp->next;
    free(temp);
    return;
}

void deletek(struct node** head, int k)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*head)->data == k)
    {
        deleteatbegin(head);
        return;
    }
    struct node* curr = *head;
    while(curr->next != NULL && curr->next->data != k)
    {
        curr = curr->next;
    }
    if(curr->next == NULL)
    {
        deleteatend(head);
        return;
    }
    struct node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    return;
}

void display(struct node* head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node* curr = head;
    while(curr != NULL)
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
    return;
}

int main(){
    struct node* head = NULL;
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
                insertatbegin(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertatend(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertatpos(&head, data, pos);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter k: ");
                scanf("%d", &k);
                insertafterk(&head, data, k);
                break;
            case 5:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter k: ");
                scanf("%d", &k);
                insertbeforek(&head, data, k);
                break;
            case 6:
                deleteatbegin(&head);
                break;
            case 7:
                deleteatend(&head);
                break;
            case 8:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteatpos(&head, pos);
                break;
            case 9:
                printf("Enter k: ");
                scanf("%d", &k);
                deletek(&head, k);
                break;
            case 10:
                display(head);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
