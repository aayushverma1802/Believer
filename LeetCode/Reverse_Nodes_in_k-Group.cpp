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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL)
        {
            return NULL;
        }
        // Make the three pointer
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nxt = NULL;
        ListNode *temp = head;
        int count = 0;

        int size = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            size++;
        }
        if (k > size)
        {
            return head;
        }
        while (count < k and curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }
        // Make the recursive calls;
        // Recursion makes the k groups and return the ans;
        if (nxt != NULL)
        {
            head->next = reverseKGroup(nxt, k);
        }
        return prev;
    }
};