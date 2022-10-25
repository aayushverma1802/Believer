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
    if (root == NULL)
    {
        return 0;
    }
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
bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    {
        return true;
    }

}
int main()
{
        // Node *root = new Node(10);
        // root->left = new Node(5);
        // root->right = new Node(30);
        // root->right->left = new Node(15);
        // root->right->right = new Node(20);

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);
    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";
    return 0;
}