#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node *createNode(int data){
    struct Node *n;
    n=(struct Node *)malloc(sizeof(struct Node ));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void preOrder(struct Node *root ){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct Node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
int main(){
    struct Node *p=createNode(234);
    struct  Node *p1=createNode(343);
    struct Node  *p2=createNode(54);
    p->left=p1;
    p->right=p2;
    printf("Preorder\n");
    preOrder(p);
    printf("\nPostorder\n");
    postOrder(p);
    return 0;




}