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
struct Node *Insert_At_Pos(struct Node *node, int data,int pos)
{
    struct Node *new=(struct Node *)malloc(sizeof(struct Node));
    struct Node *prev=node;
    new->data = data;
    int i=0;
    while(i<pos-1 && prev->next!=NULL){
        prev=prev->next;
        //nextt=nextt->next;
        i++;
    }
    new->next=prev->next;
    prev->next=new;
    return node;
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
    head = Insert_At_Pos(head, 69,2);
    printf("Updated Linked List:- \n");
    Linked_list_Traversal(head);
    return 69;
}