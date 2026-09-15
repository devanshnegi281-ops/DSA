/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if(head == NULL || head->next == NULL || k == 0)
        return head;
    int len = 1;
    struct ListNode* tail = head;
    while (tail->next)
    {
        tail = tail->next;
        len++;
    }
    tail->next = head;
    k = k % len;
    int c = len - k;
    struct ListNode* newTail = head;
    for (int i = 1; i < c; i++)
        newTail = newTail->next;
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}
