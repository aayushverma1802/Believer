#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node (int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
void preOrder(Node *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Node *root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
void postOrder(Node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
}
void Level_Order_Traversal(Node  *root){
    if(root==NULL ){
        return ;

    }
    else{
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            Node * n=q.front();
            cout<<n->data<<" ";
            q.pop();
            if(n->left!=NULL){
                q.push(n->left);

            }
            if(root!=NULL){
                q.push(n->right);
            }

        }
    }
}

int main(){
    Node *n=new Node(20);
    n->left=new Node(10);
    n->right=new Node (34);
    n->left->left=new Node (90);
    n->left->right=new Node (79);
    
    preOrder(n);

}