/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *predecessor(TreeNode *root)
    {
        TreeNode *pred = root->left;
        while (pred->right != NULL)
        {
            pred = pred->right;
        }
        return pred;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        TreeNode *pred;
        if (root == NULL)
            return NULL;
        if (root->val == key)
        {
            // case 1: No child
            if (root->left == NULL && root->right == NULL)
            {
                free(root);
                return NULL;
            }
            if (key < root->val)
            {
                root->left = deleteNode(root->left, key);
            }
            else if (key > root->val)
            {
                root->right = deleteNode(root->right, key);
            }
            else
            {
                if (root->left == NULL)
                {
                    TreeNode *temp = root->right;
                    delete root;
                    return temp;
                }
                else if (root->right == NULL)
                {
                    TreeNode *temp = root->left;
                    delete root;
                    return temp;
                }
                else
                {
                    TreeNode *pred = predecessor(root);
                    root->val = pred->val;
                    root->left = deleteNode(root->left, pred->val);
                }
            }
        }
        return root;
    }
};