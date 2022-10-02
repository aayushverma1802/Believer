#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
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
void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
int isBst(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBst(root->left))
        {
            return 0;
        }
        if (prev != NULL && prev->data >= root->data)
        {
            return 0;
        }
        prev = root;
        return isBst(root->right);
    }
    else
    {
        return 1;
    }
}
int height(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
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
int toCheck(struct Node *p1, struct Node *p2)
{
    // Both roots are NULL , it is iso..  by the defination
    if (p1 == NULL && p2 == NULL)
    {
        return 1;
    }
    if (p1 == NULL || p2 == NULL)
    {
        return 0;
    }
    if (p1->data != p2->data)
    {
        return 0;
    }
    int a = toCheck(p1->left, p2->left) && toCheck(p1->right, p2->right);
    int b = toCheck(p1->left, p2->right) && toCheck(p1->left, p2->right);
    return a || b;
}
int main()
{
    // Creating one tree
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);
    // Creating one tree
    struct Node *p111 = createNode(5);
    struct Node *p11 = createNode(3);
    struct Node *p21 = createNode(6);
    struct Node *p31 = createNode(1);
    struct Node *p41 = createNode(4);
    // One tree
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    // Another tree
    p111->left = p11;
    p111->right = p21;
    p11->left = p31;
    p11->right = p41;
    if (toCheck(p, p111) == 1)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 69;
}