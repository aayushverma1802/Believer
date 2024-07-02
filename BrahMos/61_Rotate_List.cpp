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
        int n = 1;

        ListNode *curr = head;
        if (k == 0 or head == NULL or head->next == NULL)
        {
            return head;
        }
        while (curr->next != NULL)
        {
            curr = curr->next;
            n++;
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