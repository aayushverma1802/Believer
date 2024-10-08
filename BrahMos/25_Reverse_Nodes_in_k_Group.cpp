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
        ListNode *next = NULL;
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *temp = head;
        int size = 0;
        while (temp != nullptr)
        {
            temp = temp->next;
            size++;
        }
        if (k > size)
        {
            return head;
        }
        int count = 0;
        while (curr != nullptr and count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        // Recursively reverse the remaining list and connect it
        if (next != nullptr)
        {
            head->next = reverseKGroup(next, k);
        }

        // Return the new head after reversal
        return prev;
    }
};