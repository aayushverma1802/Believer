#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
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
void RverOrder(struct Node *root)
{
    queue<struct Node *> q;
    stack<struct Node *> s;
    q.push(root);
    while (!q.empty())
    {
        struct Node *n = q.front();
        // cout << n->data << " ";
        s.push(n);
        q.pop();
        if (n->left != NULL)
        {
            q.push(n->left);
        }
        if (n->right != NULL)
        {
            q.push(n->right);
        }
    }
    while (!s.empty())
    {
        root = s.top();
        cout << root->data << " ";
        s.pop();
    }
}
void Invert(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        struct Node *temp;
        Invert(root->left);
        Invert(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
int main()
{
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(2);
    struct Node *p2 = createNode(7);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(3);
    Node *p5 = createNode(6);
    Node *p6 = createNode(9);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    inOrder(p);
    Invert(p);
    printf("\n");
    inOrder(p);
    // printf("\n");
    // if (isBst(p))
    // {
    //     printf("This is a bst");
    // }
    // else
    // {
    //     printf("This is not a bst");
    // }
    // printf("Depth of the Binary tree:-\n%d ", height(p));
    return 0;
}