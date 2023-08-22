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
ListNode *atTail(ListNode *head,int data)
 {

        ListNode *n = new ListNode(data);
        if (head == NULL)
        {
            return n;
        }

        ListNode *p = head;

        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = n;
        n->next = NULL;
        return head;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *a=list1;
        ListNode *b=list2;
         ListNode *n=NULL;
        vector<int>v;

        while(a!=NULL and b!=NULL){
            if(a->val>=b->val){
                v.push_back(b->val);
            b=b->next;

            }
            else{
                v.push_back(a->val);
            a=a->next;

            }
            
        }
        while(a!=NULL){
            v.push_back(a->val);
            a=a->next;
        }
        while(b!=NULL){
            v.push_back(b->val);
            b=b->next;
        }
        
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            n=atTail(n,v[i]);
        }
        return n;
    }
};