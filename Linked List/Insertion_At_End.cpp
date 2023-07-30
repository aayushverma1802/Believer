#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Solution
{
public:
    // Displayer
    void LinkList_Traversal(Node *n)
    {
        Node *head = n;
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
    // Function traversing

    Node *insert_at_end(Node *head, int data)
    {

        Node *n = new Node(data);
        if (head == NULL)
        {
            return n;
        }

        Node *p = head;

        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = n;
        n->next = NULL;
        return head;
    }
};
int main()
{
    Solution *obj;
    // Node *n=new Node(10);
    // Node *n1=new Node(20);
    // Node *n2=new Node(30);
    // Node *n3=new Node(40);
    // Node *n4=new Node(50);
    // Manual Traversing

    // n->next=n1;
    // n1->next=n2;
    // n2->next=n3;
    // n3->next=n4;
    Node *n = NULL;

    n = obj->insert_at_end(n, 10);
    n = obj->insert_at_end(n, 20);
    n = obj->insert_at_end(n, 30);
    n = obj->insert_at_end(n, 40);
    n = obj->insert_at_end(n, 50);
    n = obj->insert_at_end(n, 60);

    obj->LinkList_Traversal(n);

    return 69;
}
