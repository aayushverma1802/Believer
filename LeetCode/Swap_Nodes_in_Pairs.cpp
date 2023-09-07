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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL or head->next == NULL)
        {
            return head;
        }
        ListNode *p = head;
        ListNode *q = head->next;
        while (q != NULL)
        {
            swap(p->val, q->val);
            if (!(q->next && q->next->next))
                break;
            p = p->next->next;
            q = q->next->next;
        }
        return head;
    }
};