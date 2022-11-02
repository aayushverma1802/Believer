#include <iostream>
#include <vector>
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
vector<int> v;

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        v.push_back(root->data);
        inOrder(root->right);
    }
}
int main()
{
    Node *root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
    inOrder(root);
    for (auto &it : v)
    {

        // Print the values
        cout << it << ' ';
    }
}