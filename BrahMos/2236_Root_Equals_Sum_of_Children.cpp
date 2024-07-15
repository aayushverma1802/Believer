/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool checkTree(TreeNode *root)
    {
        if (root == NULL or root->left == NULL or root->right == NULL)
        {
            return false;
        }
        int lt = 0;
        int rt = 0;
        if (root->left != nullptr)
        {
            lt = root->left->val;
        }
        if (root->right != nullptr)
        {
            rt = root->right->val;
        }
        if (root->val == lt + rt)
        {
            return true;
        }
        return false;
    }
};