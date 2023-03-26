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
    TreeNode *current = new TreeNode(0);
    void helper(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        helper(root->left);
        // TreeNode *r=root;
        root->left = NULL;
        current->left = NULL;
        current->right = root;

        current = root;
        helper(root->right);
    }
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *ans = current;
        helper(root);
        return ans->right;
    }
};