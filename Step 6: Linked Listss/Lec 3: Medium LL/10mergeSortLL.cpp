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

ListNode *merge(ListNode *list1, ListNode *list2)
{
    ListNode *dummyNode = new ListNode(-1);
    ListNode *temp = dummyNode;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }
    if (list1 != NULL)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }

    return dummyNode->next;
}

ListNode *middle(ListNode *head)
{

    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *mid = middle(head);

        ListNode *right = mid->next;
        mid->next = nullptr;
        ListNode *left = head;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};