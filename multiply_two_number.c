#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void check(struct Node *head, struct Node *h2)
{
    struct Node *ll = head;
    struct Node *l2 = h2;
    int mul = 1;
    int a1[100], i = 0;
    int a2[100], j = 0;
    while (ll != NULL)
    {
        a1[i] = ll->data;
        ll = ll->next;
        i++;
    }
    while (l2 != NULL)
    {
        a2[j] = l2->data;
        l2 = l2->next;
        j++;
    }
    while (i != 0 && j != 0)
    {
        mul = a1[i] * a2[j];
        i--;
        j--;
    }
    while (i != 0)
    {
        mul *= a1[i];
        i--;
    }
    while (j != 0)
    {
        mul *= a2[j];
        j--;
    }

    printf("Answer is :- %d\n", mul);
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *s = (struct Node *)malloc(sizeof(struct Node));
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = (struct Node *)malloc(sizeof(struct Node));
    // Entering the Data;
    head->data = 9;
    s->data = 4;
    t->data = 6;
    last->data = 14;
    // Connection of Linked List;
    head->next = s;
    s->next = t;
    t->next = last;
    last->next = NULL;
    // New linked list;
    struct Node *h1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *h2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *h3 = (struct Node *)malloc(sizeof(struct Node));
    // adding of the data;
    h1->data = 8;
    h2->data = 4;
    h3->data = 1;
    // Connection the linked list;
    h1->next = h2;
    h2->next = h3;
    h3->next = NULL;
    check(head, h1);
    // linkedListTraversal(head);
    return 69;
}