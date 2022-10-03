#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <vector>
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
void Reverse_Order_traversal(struct Node *root)
{
    stack<struct Node *> s;
    queue<struct Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        root = q.front();
        q.pop();
        s.push(root);
        if (root->right)
        {
            q.push(root->right);
        }
        if (root->left)
        {
            q.push(root->left);
        }
    }
    while (s.empty() == false)
    {
        root = s.top();
        cout << root->data << " ";
        s.pop();
    }
}
int main()
{
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    Reverse_Order_traversal(p);
    return 69;
}