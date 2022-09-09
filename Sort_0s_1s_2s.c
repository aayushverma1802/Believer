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
struct Node *check(struct Node *head)
{
    struct Node *ptr = head;
    int z = 0, f = 0, s = 0;
    while (ptr != NULL)
    {
        if (ptr->data == 0)
        {
            z++;
        }
        else if (ptr->data== 1)
        {
            f++;
        }
        else if (ptr->data == 2)
        {
            s++;
        }
        ptr = ptr->next;
    }
    ptr = head;
    while (ptr != NULL)
    {
        if (z != 0)
        {
            ptr->data = 0;
            z--;
        }
        else if (f != 0)
        {
            ptr->data = 1;
            f--;
        }
        else if (s != 0)
        {
            ptr->data = 2;
            s--;
        }
        ptr = ptr->next;
    }
    return head;
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *s = (struct Node *)malloc(sizeof(struct Node));
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = (struct Node *)malloc(sizeof(struct Node));
    head->data = 0;
    s->data = 1;
    t->data = 1;
    last->data = 2;
    struct Node *l = (struct Node *)malloc(sizeof(struct Node));
    l->data = 2;
    head->next = s;
    s->next = t;
    t->next = last;
    last->next = l;
    l->next = NULL;
    head = check(head);
    linkedListTraversal(head);
    return 69;
}