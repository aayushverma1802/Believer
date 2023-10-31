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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *curr = head;
        if (head == NULL or k == 0 or !head->next)
        {
            return head;
        }
        int n = 1;
        while (curr->next != NULL and n++)
        {
            curr = curr->next;
        }
        curr->next = head;

        k = k % n;
        k = n - k;
        while (k--)
        {
            curr = curr->next;
        }
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};