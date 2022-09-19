#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void Linked_list_Traversal(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
struct Node *Insert_At_head(struct Node *head, int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr_2 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr_3 = (struct Node *)malloc(sizeof(struct Node));
    // Inserting the data;
    head->data = 56;
    ptr_2->data = 34;
    ptr_3->data = 98;
    // Connecting the node;
    head->next = ptr_2;
    ptr_2->next = ptr_3;
    ptr_3->next = NULL;
    //Traversal of the Linked List;
    Linked_list_Traversal(head);
    // Traversal of the Updated Linked List ;
    head = Insert_At_head(head, 69);
    printf("Updated Linked List:- \n");
    Linked_list_Traversal(head);
    return 69;
}