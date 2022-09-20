#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    
};
int main(){
    struct Node *head=(struct Node *)malloc(sizeof(struct Node));
    struct Node *s=(struct Node *)malloc(sizeof(struct Node));
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    struct Node *f=(struct Node *)malloc(sizeof(struct Node));
    struct Node *end=(struct Node *)malloc(sizeof(struct Node));
    //Linking the nodes;
    head->next=s;
    s->next=t;
    t->next=f;
    f->next=end;
    end->next=NULL;
    //Entering the data;
    head->data=1;
    s->data=2;
    t->data=3;
    f->data=4;
    end->data=5;
    struct Node *ptr=head;
    int count =0,a[100];
    while( ptr!=NULL){
        count++;
        ptr=ptr->next;
    }
    if(count%2==0){
        for(int i=0;i<count;i++){
            a[i]=head->data;
            head=head->next;
        }
        printf("%d",a[count/2]);
    }
    else{
        for(int j=0;j<count;j++){
             a[j]=head->data;
            head=head->next;
        }
        printf("%d",a[(count-1)/2]);
        
    }
        

}
