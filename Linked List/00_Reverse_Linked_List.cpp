#include <iostream>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    // ListNode(int val)
    // {
    //     this->val = val;
    //     this->next = NULL;
    // }
    // Second method of the class
    ListNode(int data)
    {
        val= data;
        this->next = nullptr;
    }
};
class Functioner
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev=NULL, *curr, *nxt = NULL;
        curr = head;
        while (curr != nullptr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};
class Statment_Printer
{
    public:
    void printer(ListNode *head)
    {
        ListNode *k = head;
        while (k != nullptr)
        {
            cout << k->val <<" ";
            k=k->next;
        }
        cout<<endl;
    }
};
int main()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=nullptr;
    Statment_Printer ans;
    ans.printer(n1);
    Functioner *operation;
    // ListNode *take=NULL;
    n1=operation->reverseList(n1);
    ans.printer(n1);

    return 69;
}