/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *list1 = headA;
        ListNode *list2 = headB;
        // can also write it as :
        while(list1!=list2){
            list1 = (list1==nullptr) ? headB : list1->next;
            list2 = (list2==nullptr) ? headA : list2->next;
        }
        // same for the above code, but more readable 
        while (list1 != list2)
        {
            list1 = list1->next;
            list2 = list2->next;

            if (list1 == list2)
                return list1;

            if (list1 == NULL)
                list1 = headB;
            if (list2 == NULL)
                list2 = headA;
        }
        return list1;
    }
};