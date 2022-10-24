#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
int height(Node *root)
{
    if (root != NULL)
    {
        int l = height(root->left);
        int r = height(root->right);
        if (l > r)
        {
            return l + 1;
        }
        else
        {
            return r + 1;
        }
    }
}
void Mirror(Node *root){
    if(root==NULL){
        return ;
    }
    Mirror(root->left);
    Mirror(root->right);
    swap(root->left,root->right);
}
void InOrder(Node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    InOrder(root);
    cout<<"\n";
    Mirror(root);
    InOrder(root);
   // cout<<height(root);
}
