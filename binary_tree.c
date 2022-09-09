#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*left;
    struct Node* right;
};
int main(){
    //Constructing the root Node;
    struct Node *p;
    p=(struct Node *)malloc(sizeof(struct Node ));
    p->left=NULL;
    p->left=NULL;
    p->data=23;
    //Constructing the second Node;
    struct Node *p1;
    p1=(struct Node*)malloc(sizeof(struct Node));
    p1->left=NULL;
    p1->right=NULL;
    p->data=233;
    struct Node *p2;
    //Constructing the third Node;
    p2->left=NULL;
    p2->right=NULL;
    p->data=43;
    //Linking the root with left and right children;
    p->left=p1;
    p->right=p2;
    return 69;
}