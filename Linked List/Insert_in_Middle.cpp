//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// function to display the linked list
void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *insertInMiddle(Node *head, int x);

int main()
{
    int T, n, x;
    cin >> T;
    while (T--)
    {
        cin >> n >> x;

        struct Node *head = new Node(x);
        struct Node *tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> x;
            tail->next = new Node(x);
            tail = tail->next;
        }

        cin >> x;
        head = insertInMiddle(head, x);
        display(head);
    }
    return 0;
}

// } Driver Code Ends

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to insert a node in the middle of the linked list.
Node *insertInMiddle(Node *head1, int x)
{
    Node *head = head1;
    int count = 0, i = 0;
    // Code here

    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    if (count % 2 == 0)
    {
        count = count / 2;
    }
    else
    {
        count = (count + 1) / 2;
        // count++;
    }
    head = head1;
    while (i < count - 1)
    {
        head = head->next;
        i++;
    }
    Node *n = new Node(x);
    n->next = head->next;
    head->next = n;
    return head1;
}