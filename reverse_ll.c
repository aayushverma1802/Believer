#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *head)
{
    struct Node *ptr=head;
    while (ptr!= NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node * reverse(struct Node *node ){
    struct Node *prev,*curr,*nextt;
    prev=NULL;
    curr=nextt=node;
    while(nextt!=NULL){
        nextt=nextt->next;
        curr->next=prev;
        prev=curr;
        curr=nextt;

    }
    node =prev;
    return node;
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
    last->next=NULL;
    head=reverse(head);
    linkedListTraversal(head);
    return 69;
}