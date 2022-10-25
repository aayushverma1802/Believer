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

bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL and r2 == NULL)
    {
        return true;
    }
    if (r1 == NULL and r2 != NULL)
    {
        return false;
    }
    if (r1 != NULL and r2 == NULL)
    {
        return false;
    }
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    if (r1->data == r2->data and right and left)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    Node *root1 = new Node(1);
    Node *root2 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    if (isIdentical(root1, root2))
        cout << "Both trees are identical.";
    else
        cout << "Trees are not identical.";

    return 0;
}