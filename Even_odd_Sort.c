#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};


int swapNode(struct Node* head) {
    int temp=0;
    temp = head->data;
    head->data = head->next->data;
    head->next->data = temp;
}


int main()
{
    struct Node *prev,*head,*p;
    int n=8;
    
    head=NULL;
    for(int i=0;i<n;i++)
    {
        p=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL)
            head=p;
        else
            prev->next=p;
        prev=p;
    }
    p=head;
    for(int i=0;i<n;i=i+2)
    {
        swapNode(p);
        p=p->next->next;
    }
    p=head;
    for(int i=0;i<n;i++)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    return 0;
}