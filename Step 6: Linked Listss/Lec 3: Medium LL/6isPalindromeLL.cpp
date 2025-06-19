/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode *reverseLinkedList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;

    while (curr != NULL)
    {
        ListNode *front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // now slow is at the MID and fast is either at second last or last node
        ListNode *newMidHead = reverseLinkedList(slow->next);

        ListNode *first = head;
        ListNode *second = newMidHead;
        while (second != NULL)
        {
            if (first->val != second->val)
            {
                reverseLinkedList(newMidHead); // just so that the initial linklist is not tampered
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLinkedList(newMidHead); // just so that the initial linklist is not tampered
        return true;
    }
};