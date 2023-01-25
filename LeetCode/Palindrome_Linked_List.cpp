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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int>v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        vector<int>vv;
        vv=v;
        reverse(vv.begin(),vv.end());
        for(int i=0;i<vv.size();i++){
            if(vv[i]!=v[i]){
                return false;
            }
        }
        return true;
    }
};