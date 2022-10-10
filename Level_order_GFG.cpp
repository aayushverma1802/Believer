#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <queue>
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
void printLeft(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<struct Node *> q;
    q.push(root);
    while (!q.empty())

    {

        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            struct Node *p = q.front();
            q.pop();
            if (i == 0)
            {
                cout << p->data << endl;
            }
            if (p->left != NULL)
            {
                q.push(p->left);
            }
            if (p->right != NULL)
            {
                q.push(p->right);
            }
        }
    }
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
        if (  prev->data >= root->data )
        {
            return 0;
        }
        if(prev!=NULL){
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
int iterSearch(struct Node *root, int key)
{
    if (root != NULL)
    {
        if (key == root->data)
        {
            return 1;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return 0;
}
void insert(struct Node *root, int key)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            cout << "Cannot Insert !!\n Element Already existing\n";
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct Node *newk = createNode(key);
    if (key < prev->data)
    {
        prev->left = newk;
    }
    else
    {
        prev->right = newk;
    }
}
void inser1t(struct Node *root, int key)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct Node *new1 = createNode(key);
    if (key < prev->data)
    {
        prev->left = new1;
    }
    else
    {
        prev->right = new1;
    }
}
void level_Order_Traversal(struct Node *root)
{
    if(root==NULL){
        return;
    }
    queue<struct Node *> q;
    q.push(root);
    while (!q.empty())
    {
        struct Node *n = q.front();

        cout << n->data << " ";
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
}
int main()
{
    struct Node *p = createNode(1);
    struct Node *p1 = createNode(2);
    struct Node *p2 = createNode(3);
    struct Node *p3 = createNode(6);
    struct Node *p4 = createNode(5);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    level_Order_Traversal(p);
    return 69;
}