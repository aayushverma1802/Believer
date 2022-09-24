#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *merge(struct Node *h, struct Node *h_2)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));

    struct Node *head = h, *head_2 = h_2, *ptr = p;

    while (head != NULL && head_2 != NULL)
    {
        if (head->data <= head_2->data)
        {
            ptr->next = head;
            head = head->next;
        }
        else
        {
            ptr->next = head_2;
            head_2 = head_2->next;
        }
        ptr = ptr->next;
    }
    while (head != NULL)
    {
        ptr->next = head;
        head = head->next;
        ptr = ptr->next;
    }
    while (head_2 != NULL)
    {
        ptr->next = head_2;
        head_2 = head_2->next;
        ptr = ptr->next;
    }
    return p;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *s = (struct Node *)malloc(sizeof(struct Node));
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head_2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *s_2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *t_2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last_2 = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;
    s->data = 11;
    t->data = 12;
    last->data = 13;
    head_2->data = 90;
    s_2->data = 91;
    t_2->data = 92;
    last_2->data = 93;
    head->next = s;
    s->next = t;
    t->next = last;
    last->next = NULL;
    head_2->next = s_2;
    s_2->next = t_2;
    t_2->next = last_2;
    last_2->next = NULL;
    head = merge(head, head_2);
    linkedListTraversal(head);
    return 69;
}