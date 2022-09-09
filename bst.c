#include <stdio.h>
#include <malloc.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int data)
{
    struct Node *n;                                 // Making a Node pointer
    n = (struct Node *)malloc(sizeof(struct Node)); // Allocating memory in the heap
    // Entering the data
    n->data = data;
    // Connecting the left and right children to NULL
    n->left = NULL;
    // Connecting the left and right children to NULL
    n->right = NULL;
    // Returning the created Node
    return n;
}
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int isBST(struct Node *root)
{
    struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
int main()
{
    // Constructing the root Node
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2

    // Linking the root Node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    preOrder(p);
    return 0;
}
