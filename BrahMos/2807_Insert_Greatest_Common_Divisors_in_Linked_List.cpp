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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *temp = head;
        while (temp->next != nullptr)
        {
            ListNode *a = temp;
            ListNode *b = temp->next;
            int cum_gcd = __gcd(a->val, b->val);
            ListNode *tts = new ListNode(cum_gcd);
            tts->next = temp->next;
            temp->next = tts;
            temp = temp->next->next;
        }
        return head;
    }
};