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
    int ans(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int l = ans(root->left);
        int r = ans(root->right);
        return max(l, r) + 1;
    }
    int maxDepth(TreeNode *root)
    {
        return ans(root);
    }
};