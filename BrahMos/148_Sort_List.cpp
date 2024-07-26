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
    // Function to append a node with value 'head' at the end of the list 'ans'
    ListNode *solve(int head, ListNode *ans)
    {
        ListNode *temp = new ListNode(head);
        if (ans == nullptr)
        {
            return temp;
        }
        ListNode *current = ans;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = temp;
        return ans;
    }

    ListNode *sortList(ListNode *head)
    {
        vector<int> v;
        while (head != nullptr)
        {
            v.push_back(head->val);
            head = head->next;
        }

        sort(v.begin(), v.end());

        ListNode *ans = nullptr;
        ListNode *tail = nullptr;
        for (int i : v)
        {
            if (ans == nullptr)
            {
                ans = new ListNode(i);
                tail = ans;
            }
            else
            {
                tail->next = new ListNode(i);
                tail = tail->next;
            }
        }
        return ans;
    }
};
