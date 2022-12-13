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
    ListNode *rev(ListNode *head)
    {
        struct ListNode *prev = NULL;
        struct ListNode *curr = head;
        struct ListNode *nxt;
        while (curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
        return head;
    }
    void insertAtEnd(ListNode *&head, int x)
    {
        ListNode *n = new ListNode(x);
        if (head == NULL)
        {
            head = n;
            return;
        }
        ListNode *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = n;
        n->next = NULL;
    }
    ListNode *add(ListNode *first, ListNode *second)
    {
        int carry = 0;
        ListNode *j = NULL;
        while (first != NULL and second != NULL)
        {
            int sum = carry + first->val + second->val;
            int digit = sum % 10;
            insertAtEnd(j, digit);
            carry = sum / 10;

            first = first->next;
            second = second->next;
        }
        while (first != NULL)
        {
            int sum = carry + first->val;
            int digit = sum % 10;
            insertAtEnd(j, digit);
            carry = sum / 10;
            first = first->next;
        }
        while (second != NULL)
        {
            int sum = carry + second->val;
            int digit = sum % 10;
            insertAtEnd(j, digit);
            carry = sum / 10;
            second = second->next;
        }
        while (carry != 0)
        {
            int sum = carry;
            int digit = sum % 10;
            insertAtEnd(j, digit);
            carry = sum / 10;
        }
        return j;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // l1=rev(l1);
        // l2=rev(l2);
        ListNode *ans = add(l1, l2);
        // ans=rev(ans);
        return ans;
    }
};