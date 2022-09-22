#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int pr;
    struct Node *next;
};

int main()
{
    struct Node *prev,*prev2,*head,*head2,*ptr,*p2,*p3,*head3,*prev3;
    head=NULL;
    head2=NULL;
    head3=NULL;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->pr=1;
    while(ptr->pr!=0)
    {
        ptr=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&ptr->data);
        scanf("%d",&ptr->pr);
        ptr->next=NULL;
        if(head==NULL)
            head=ptr;
        else
            prev->next=ptr;
        prev=ptr;
    }
    ptr=head;
    p2=head;
    while(p2->pr!=0)
    {
        p2=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&p2->data);
        scanf("%d",&p2->pr);
        p2->next=NULL;
        if(head2==NULL)
            head2=p2;
        else
            prev2->next=p2;
        prev2=p2;
    }
    ptr=head;
    p3=NULL;
    while(ptr!=NULL)
    {
        
        p2=head2;
        while(p2!=NULL)
        {
            if(ptr->pr==p2->pr)
            {
                p3=(struct Node *)malloc(sizeof(struct Node));
                p3->data=ptr->data+p2->data;
                p3->pr=ptr->pr;
                p3->next=NULL;
                if(head3==NULL)
                    head3=p3;
                else
                    prev3->next=p3;
                prev3=p3;
                break;
            }
            p2=p2->next;
        }
        if(p3==NULL)
        {
            p3=(struct Node *)malloc(sizeof(struct Node));
            p3->data=ptr->data;
            p3->pr=ptr->pr;
            p3->next=NULL;
            if(head3==NULL)
                head3=p3;
            else
                prev3->next=p3;
            prev3=p3;  
        }
        ptr=ptr->next;
    }
    ptr=head3;
    while(ptr!=NULL)
    {
        printf("%d %d ",ptr->data,ptr->pr);
        ptr=ptr->next;
    }
    return 0;
}