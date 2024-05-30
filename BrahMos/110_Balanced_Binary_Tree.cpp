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
        if (l == -1)
            return -1;
        int h = ans(root->right);
        if (h == -1)
            return -1;
        if (abs(l - h) > 1)
        {
            return -1;
        }
        return max(l, h) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        return ans(root) != -1;
    }
};