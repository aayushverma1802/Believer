#include<stdio.h>
#include<stdlib.h>
//Making Structure
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
//Function to remove the nth Node in linked list
struct Node *Remove_n(struct Node *head,int n){
    struct Node *ptr=head;
    struct Node *nth=head;
    int h=n;//Position to remove
    for(int i=0;i<=h;i++){
        ptr=ptr->next;//Moving the pointer to the nth position
    }
    //Main work 
    while(ptr->next!=NULL){
        ptr=ptr->next;
        nth=nth->next;
    }
    nth->next=nth->next->next;
    return head;
}
int main(){
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    struct Node *s=(struct Node *)malloc(sizeof(struct Node));
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    struct Node *last=(struct Node *)malloc(sizeof(struct Node));
    //Entering the data
    head->data=10;
    s->data=11;
    t->data=12;
    last->data=13;
    //Connecting the data
    head->next=s;
    s->next=t;
    t->next=last;
    last->next=NULL;
    //Remove the 2nd node from the linked list
    head=Remove_n(head,2);
    linkedListTraversal(head);
    return 69;
}