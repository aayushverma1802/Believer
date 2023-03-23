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
    int getDecimalValue(ListNode *head)
    {
        vector<int> arr;
        while (head != NULL)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        int ans = 0;
        reverse(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            int p = pow(2, i);
            ans += p * arr[i];
        }
        return ans;
    }
};