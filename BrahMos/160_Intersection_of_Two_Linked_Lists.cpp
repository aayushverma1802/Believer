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
        unordered_set<ListNode *> m;
        while (headA != NULL)
        {
            m.insert(headA);
            headA = headA->next;
        }
        while (headB != NULL)
        {
            if (m.find(headB) != m.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};