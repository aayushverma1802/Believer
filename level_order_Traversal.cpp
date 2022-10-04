#include <stdio.h>
#include <stack>
#include <iostream>
#include <queue>
#include <vector>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

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
void Level_Order_Traversal(struct Node *root)
{
    queue<struct Node *> q;
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        printf("%d ", root->data);
        q.pop();

        if (root->left != NULL)
        {
            q.push(root->left);
        }
        if (root->right != NULL)
        {
            q.push(root->right);
        }
    }
}
int main()
{
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(7);
    struct Node *p3 = createNode(2);
    struct Node *p4 = createNode(4);
    struct Node *p5 = createNode(3);
    struct Node *p6 = createNode(6);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p4->left = p5;
    p4->right = p6;
    Level_Order_Traversal(p);
}
