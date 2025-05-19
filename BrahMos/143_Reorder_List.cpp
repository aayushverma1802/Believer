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
    void reorderList(ListNode *head)
    {
        stack<ListNode *> s;
        ListNode *tcnt = head;
        ListNode *curr = head;
        while (tcnt != nullptr)
        {
            s.push(tcnt);
            tcnt = tcnt->next;
        }
        int k = s.size();
        k /= 2;
        while (k--)
        {
            ListNode *topn = s.top();
            s.pop();
            ListNode *temp = curr->next;
            curr->next = topn;
            topn->next = temp;
            curr = temp;
        }
        curr->next = nullptr;
    }
};