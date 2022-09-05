// Using the Floyd's Algorithm.

// Including the header file
#include <stdio.h>
#include <stdlib.h>
// Making a structure named "Node" (Creation of Linked List)
struct Node
{
    int data;
    struct Node *next;
};
// Printing all the elements of the Linked List
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// Function to check if there is a Cycle or not !!
void findloop(struct Node *head)
{
    // 1)Make 2 pointer (Slow and Fast)
    struct Node *slow, *fast;
    // Take the address of head in both the pointer
    slow = fast = head;
    while (fast->next != NULL && fast != NULL)
    {
        // 3)Slow takes the address of head and Fast take the next Pointer.
        slow = slow->next;
        fast = fast->next->next;
        // 4)Checking if slow is = NUll or any other Node.
        if (slow == fast)
        {
            printf("Linked List contains a loop\n");
            return;
        }
    }
    printf("No Loop in Linked List\n");
}
int main()
{
    // Creating a Linked List.
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *s = (struct Node *)malloc(sizeof(struct Node));
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = (struct Node *)malloc(sizeof(struct Node));
    // Entering the data.
    head->data = 10;
    s->data = 11;
    t->data = 12;
    last->data = 13;
    // Linking the data.
    head->next = s;
    s->next = t;
    t->next = last;
    last->next = t;
    findloop(head);
    // linkedListTraversal(head);
    return 69;
}