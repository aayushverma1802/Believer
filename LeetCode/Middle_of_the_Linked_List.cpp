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
    ListNode *middleNode(ListNode *head)
    {
        int count = 0;
        ListNode *temp = head;
        while (head != NULL)
        {

            head = head->next;
            count++;
        }
        int i = 0;
        while (i < count / 2)
        {
            cout << temp->val;
            temp = temp->next;
            i++;
        }
        return temp;
    }
};