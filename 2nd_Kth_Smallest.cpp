#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int ans =0;
void inOrder(BinaryTreeNode<int>* root,int &i ,int k){
    if(root==NULL){
        return ;
    }
    //L

     inOrder(root->left,i,k);
    i++;
    if(i==k){
        ans= root->data;
        return ;
        //i++;
    }
    

    //R
      inOrder(root->right,i,k);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i=0;
    ans=-1;
    inOrder(root,i,k);
    return ans;
}