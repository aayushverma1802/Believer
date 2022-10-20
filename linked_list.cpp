#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
//void Print
void Linked_List_traversal(Node * head){
    Node *n=head;
    while(n!=NULL){
        cout<<n->data<<" ";
       // printf("\n");
        n=n->next;

    }
}
Node *Insertion_at_head(Node * head, int data)
{
    Node *n = new Node(data);
    n->next = head;
    head = n;
    return head;
}
Node *Insertion_at_end(Node * head,int data){
    Node *n=new Node(data);
    Node *q=head;

    while(q->next!=NULL){
        q=q->next;
        //n->next=NULL;
    }
    q->next=n;
    n->next=NULL;
    return head;

}
int main()
{
    Node *head = new Node(32);
    // cout << head->data << endl;
    // cout << head->next << endl;
    head = Insertion_at_head(head, 69);
    head = Insertion_at_end(head, 90);
    head = Insertion_at_end(head, 20);
    head = Insertion_at_end(head, 50);
    head = Insertion_at_end(head, 70);
    // cout << head->data << endl;
    // cout << head->data << endl;
    // cout << head->data << endl;
    // cout << head->data << endl;
    // cout << head->data << endl;
    // cout << head->data << endl;
    // cout << head->next << endl;
    Linked_List_traversal(head);
}