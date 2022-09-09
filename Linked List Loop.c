#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *ptr)
{
    while (ptr!= NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void findloop(struct Node *head) {
    struct Node *slow, *fast;
    slow = fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast  = fast->next->next;
        if (slow == fast) {
           printf("Linked List contains a loop\n");
           return;
        }
    }
    printf("No Loop in Linked List\n");
}
void fuck(struct Node *head){
    struct Node *slow,*fast;
    slow=fast=head;
    while(slow&&fast&&fast->next){

    }
}
int main(){
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    struct Node *s=(struct Node *)malloc(sizeof(struct Node));
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    struct Node *last=(struct Node *)malloc(sizeof(struct Node));
    head->data=10;
    s->data=11;
    t->data=12;
    last->data=13;
    head->next=s;
    s->next=t;
    t->next=last;
    last->next=s;
    findloop(head);
    //linkedListTraversal(head);
    return 69;
}