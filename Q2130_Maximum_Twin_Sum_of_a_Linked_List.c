/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head)
{
    struct ListNode* reverseList(struct ListNode* head)
    {
        struct ListNode* prev = NULL;
        struct ListNode* next = NULL;
        while (head != NULL)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* secondHalf = reverseList(slow);
    struct ListNode* firstHalf = head;
    int maxSum = INT_MIN;
    while (secondHalf != NULL)
    {
        int sum = firstHalf->val + secondHalf->val;
        if (sum > maxSum)
            maxSum = sum;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return maxSum;
}