#include<iostream>
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
int inOrder(Node *root,int &i ,int k){
    if(root==NULL){
        return -1;
    }
    //L
    int left=inOrder(root->left,i,k);
    if(left!=-1){
        return left;
    }
    
    i++;
    if(i==k){
        return root->data;
    }
    //R
    return inOrder(root->right,i,k);
}
int kSmallest(Node *root,int k){
    int i=0;
    int ans=inOrder(root,i,k);
    return ans;
}

int main(){
    Node *n=new Node(20);
    n->left=new Node(10);
    n->right=new Node (34);
    n->left->left=new Node (90);
    n->left->right=new Node (79);
    cout<< kSmallest(n,3);

}