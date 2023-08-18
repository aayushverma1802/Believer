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
    bool check(TreeNode *rootL, TreeNode *rootR)
    {
        if (rootL == NULL and rootR == NULL)
        {
            return true;
        }
        if (rootL == NULL or rootR == NULL)
        {
            return false;
        }
        if (rootL->val != rootR->val)
        {
            return false;
        }
        return check(rootL->left, rootR->right) and check(rootL->right, rootR->left);
        // return true;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        return check(root->left, root->right);
    }
};